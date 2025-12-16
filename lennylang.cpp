#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <functional>
#include <variant>
#include <memory>

using namespace std;
using std::function;
using std::shared_ptr;
using Value = std::variant<int, double, std::string>;

struct LoopBody
{
    map<std::string, Value> variables;
    std::vector<std::string> condition;
    std::stack<std::string> stack;
    std::vector<std::variant<std::string, std::shared_ptr<LoopBody>>> body;
};

static string load(const string &path)
{
    // given a file path, loads the entire file into a string
    ifstream f(path);
    if (!f.is_open())
    {
        cerr << "Error opening file: " << path << endl;
        exit(1);
    }
    string s((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
    return s;
}

vector<string> split(const string &s)
{
    // given a string s, split it into tokens by whitespace
    vector<string> tokens;
    string cur;
    for (char c : s)
    {
        if (isspace(c))
        {
            if (!cur.empty())
            {
                tokens.push_back(cur);
                cur.clear();
            }
        }
        else
        {
            cur += c;
        }
    }
    if (!cur.empty())
    {
        tokens.push_back(cur);
    }
    return tokens;
}

// ---------------- LennyLang Operations ----------------
void output(string thing)
{
    cout << thing << endl;
}

// helper function to check if a string is a number
bool is_number(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

// addition operation
string add_two(string a, string b)
{
    // if numbers
    if (is_number(a) && is_number(b))
    {
        int sum = stoi(a) + stoi(b);
        return to_string(sum);
    }
    return a + b;
}

// subtraction operation
string subtract_two(string a, string b)
{
    if (is_number(a) && is_number(b))
    {
        int diff = stoi(a) - stoi(b);
        return to_string(diff);
    }
    cerr << "Error: Subtraction requires numeric operands." << endl;
    exit(1);
}

// multiplication operation
string multiply_two(string a, string b)
{
    if (is_number(a) && is_number(b))
    {
        int prod = stoi(a) * stoi(b);
        return to_string(prod);
    }
    cerr << "Error: Multiplication requires numeric operands." << endl;
    exit(1);
}

// division operation
string divide_two(string a, string b)
{
    if (is_number(a) && is_number(b))
    {
        if (stoi(b) == 0)
        {
            cerr << "Error: Division by zero." << endl;
            exit(1);
        }
        int quot = stoi(a) / stoi(b);
        return to_string(quot);
    }
    cerr << "Error: Division requires numeric operands." << endl;
    exit(1);
}

// equality operation
bool is_equal(string a, string b)
{
    if (is_number(a) && is_number(b))
    {
        return stoi(a) == stoi(b);
    }
    return a == b;
}

// greater-than operation
bool is_greater(string a, string b)
{
    if (is_number(a) && is_number(b))
    {
        return stoi(a) > stoi(b);
    }
    cerr << "Error: Greater-than comparison requires numeric operands." << endl;
    exit(1);
}

// less-than operation
bool is_less(string a, string b)
{
    if (is_number(a) && is_number(b))
    {
        return stoi(a) < stoi(b);
    }
    cerr << "Error: Less-than comparison requires numeric operands." << endl;
    exit(1);
}

bool evaluate_cond(const std::vector<std::string> &condition)
{
    if (condition.size() != 3)
    {
        cerr << "Error: Invalid condition format." << endl;
        exit(1);
    }
    string var = condition[0];
    string op = condition[1];
    string value = condition[2];

    if (op == "==")
    {
        return is_equal(var, value);
    }
    else if (op == ">")
    {
        return is_greater(var, value);
    }
    else if (op == "<")
    {
        return is_less(var, value);
    }
    else
    {
        cerr << "Error: Unknown operator in condition." << endl;
        exit(1);
    }
}

static std::map<std::string, Value> globals;

void assign(string a, string b)
{
    globals[a] = Value(b);
}

// for debugging
void PrintStack(stack<string> s)
{
    // used for debugging
    if (s.empty())
        return;

    string x = s.top();
    s.pop();
    PrintStack(s);
    std::cout << x << " ";
    s.push(x);
}

void PrintMap(map<string, Value> m)
{
    for (const auto &pair : m)
    {
        std::cout << pair.first << ": ";
        if (std::holds_alternative<int>(pair.second))
        {
            std::cout << std::get<int>(pair.second);
        }
        else if (std::holds_alternative<double>(pair.second))
        {
            std::cout << std::get<double>(pair.second);
        }
        else if (std::holds_alternative<std::string>(pair.second))
        {
            std::cout << std::get<std::string>(pair.second);
        }
        std::cout << std::endl;
    }
}

void run_code(
    const vector<variant<string, shared_ptr<LoopBody>>> &tokens,
    map<string, Value> &variables,
    stack<string> &todo)
{

    stack<string> toassign; // variable names yet to be assigned
    std::stack<std::shared_ptr<LoopBody>> loop_stack;
    bool in_loop = false;
    // cout << "Initial todo" << endl;
    // PrintStack(todo);
    // cout << endl;
    for (auto it = tokens.begin(); it != tokens.end(); ++it)
    {
        // debug
        // cout << "Token: [";
        // if (holds_alternative<string>(*it))
        // {
        //     cout << get<string>(*it);
        // }
        // else
        // {
        //     cout << "(loop)";
        // }
        // cout << "] Hex: ";
        // stack<string> temp = todo;
        // cout << "Current todo: ";
        // PrintStack(temp);
        // cout << endl;
        if (holds_alternative<shared_ptr<LoopBody>>(*it)){
            auto loop = get<shared_ptr<LoopBody>>(*it);
            while (evaluate_cond(loop->condition))
            {
                run_code(loop->body, variables, todo); // Recursively execute loop body
            }
        }else if (holds_alternative<string>(*it)){

            // assign variables: open-bracket variable assignment-operator value close-bracket
            if (holds_alternative<shared_ptr<LoopBody>>(*it))
            {
                auto loop_body = get<shared_ptr<LoopBody>>(*it);
                run_code(loop_body->body, loop_body->variables, loop_body->stack);
            }
            else if (holds_alternative<string>(*it) && get<string>(*it) == "(>^o^)>")
            {
                if (!todo.empty())
                    todo.pop();
            }
            else if (holds_alternative<string>(*it) && get<string>(*it) == "(^o^<)")
            { //(^o^<)
                // end process
                if (!todo.empty())
                {
                    todo.pop();
                }
            }
            else if (holds_alternative<string>(*it) && get<string>(*it) == "UwU")
            { //( ͡° ͜ʖ ͡°)
                if (todo.empty())
                {
                    cerr << "Error: Stack underflow on UwU" << endl;
                    return;
                }
                string val = todo.top();
                todo.pop();
                if (variables.find(val) != variables.end())
                {
                    Value v = variables[val];
                    if (std::holds_alternative<int>(v))
                    {
                        output(std::to_string(std::get<int>(v)));
                    }
                    else if (std::holds_alternative<double>(v))
                    {
                        output(std::to_string(std::get<double>(v)));
                    }
                    else if (std::holds_alternative<std::string>(v))
                    {
                        output(std::get<std::string>(v));
                    }
                }
                else
                {
                    output(val);
                }
            }
            else if (holds_alternative<string>(*it) && get<string>(*it) == "+_+")
            { //('_')┏oo┓('_')
                // addition
                if (todo.size() < 2)
                {
                    cerr << "Error: Stack underflow on addition" << endl;
                    return;
                }
                string a = todo.top();
                todo.pop();
                string b = todo.top();
                todo.pop();
                string result = add_two(a, b);
                todo.push(result);
            }
            else if (holds_alternative<string>(*it) && get<string>(*it) == "-.-")
            {
                if (todo.size() < 2)
                {
                    cerr << "Error: Stack underflow on (ㆆ _ ㆆ)" << endl;
                    return;
                }
                string a = todo.top();
                todo.pop();
                string b = todo.top();
                todo.pop();
                string result = subtract_two(b, a);
                todo.push(result);
            }
            else if (holds_alternative<string>(*it) && get<string>(*it) == ":[")
            {
                // variable assignment
                if (todo.size() < 1)
                {
                    cerr << "Error: No variable specified for assignment" << endl;
                    return;
                }
                toassign.push(todo.top());
                todo.pop();
            }
            else if (holds_alternative<string>(*it) && get<string>(*it) == "OwO")
            {
                // start to put things in loop
                auto new_loop = std::make_shared<LoopBody>();
                // parse the next tokens in brackets as the loop condition
                auto cond_it = it + 1;
                if (cond_it == tokens.end() || !holds_alternative<string>(*cond_it) || get<string>(*cond_it) != "(>^o^)>")
                {
                    cerr << "Error: Expected (>^o^)> to start loop condition after OwO" << endl;
                    return;
                }
                ++cond_it; // move past (>^o^)>
                std::vector<std::string> condition_tokens;
                while (!(holds_alternative<string>(*cond_it) && get<string>(*cond_it) == "(^o^<)"))
                {
                    if (cond_it == tokens.end())
                    {
                        cerr << "Error: Expected (^o^<) to end loop condition" << endl;
                        return;
                    }
                    condition_tokens.push_back(get<string>(*cond_it));
                    ++cond_it;
                }
                // skip (^o^<)
                ++cond_it;

                new_loop->condition = condition_tokens;
                it = cond_it;
                loop_stack.push(new_loop);
                in_loop = true;
            }
            else if (holds_alternative<string>(*it) && get<string>(*it) == ">:3")
            {
                // end loop
                auto finished_loop = loop_stack.top();
                loop_stack.pop();
                if (!loop_stack.empty())
                {
                    loop_stack.top()->body.push_back(finished_loop);
                    loop_stack.top()->condition = finished_loop->condition;
                    loop_stack.top()->variables = finished_loop->variables;
                    loop_stack.top()->stack = finished_loop->stack;
                }
                else
                {
                    in_loop = false;
                    while (evaluate_cond(finished_loop->condition))
                    {
                        run_code(finished_loop->body, finished_loop->variables, finished_loop->stack);
                    }
                }
            }
            else
            {
                todo.push(get<string>(*it));
                if (!toassign.empty())
                {
                    string name = toassign.top();
                    toassign.pop();
                    string valueStr = todo.top();
                    todo.pop();
                    if (is_number(valueStr))
                        variables[name] = stoi(valueStr);
                    else
                        variables[name] = valueStr;
                }
                else if (variables.find(get<string>(*it)) != variables.end())
                {
                    Value val = variables[get<string>(*it)];
                    if (std::holds_alternative<int>(val))
                    {
                        todo.push(std::to_string(std::get<int>(val)));
                    }
                    else if (std::holds_alternative<double>(val))
                    {
                        todo.push(std::to_string(std::get<double>(val)));
                    }
                    else if (std::holds_alternative<std::string>(val))
                    {
                        todo.push(std::get<std::string>(val));
                    }
                }

                if (in_loop)
                {
                    loop_stack.top()->stack.push(get<string>(*it));
                }
            }
        }
    }
}

vector<variant<string, shared_ptr<LoopBody>>> parse_tokens(
    const vector<string> &tokens, int &i)
{
    vector<variant<string, shared_ptr<LoopBody>>> result;

    while (i < tokens.size())
    {
        if (tokens[i] == "OwO")
        {
            ++i;
            if (i >= tokens.size() || tokens[i] != "(>^o^)>")
            {
                cerr << "Error: Expected (>^o^)> after OwO" << endl;
                exit(1);
            }
            ++i;

            // Parse condition
            vector<string> cond;
            while (i < tokens.size() && tokens[i] != "(^o^<)")
            {
                cond.push_back(tokens[i]);
                ++i;
            }
            if (i >= tokens.size())
            {
                cerr << "Error: Expected (^o^<) to end loop condition" << endl;
                exit(1);
            }
            ++i; // skip (^o^<)

            // Create loop and recursively parse its body
            auto loop = make_shared<LoopBody>();
            loop->condition = cond;
            loop->body = parse_tokens(tokens, i); // Recursive call
            result.push_back(loop);
        }
        else if (tokens[i] == ">:3")
        {
            ++i;
            break;
        }
        else
        {
            result.push_back(tokens[i]);
            ++i;
        }
    }
    return result;
}

void PrintLoopBody(vector<variant<string, shared_ptr<LoopBody>>> &body, int indent = 0)
{
    string indentStr(indent, ' ');
    for (const auto &token : body)
    {
        if (holds_alternative<string>(token))
        {
            cout << indentStr << "Token: " << get<string>(token) << endl;
        }
        else
        {
            auto loop = get<shared_ptr<LoopBody>>(token);
            cout << indentStr << "Loop Condition: ";
            for (const auto &condToken : loop->condition)
            {
                cout << condToken << " ";
            }
            cout << endl;
            cout << indentStr << "Loop Body:" << endl;
            PrintLoopBody(loop->body, indent + 4);
        }
    }
}

int main(int argc, char **argv)
{
    string flag;
    if (argc < 2)
    {
        flag = "-h";
    }
    else
    {
        flag = argv[1];
    }

    if (flag == "-h" || flag == "--help")
    {
        cout << "\n";
        cout << "========================================\n";
        cout << "   Welcome to LennyLang Interpreter!    \n";
        cout << "========================================\n";
        cout << R"(
              _                   
 __ __ _____| |__ ___ _ __  ___ 
 \ V  V / -_) / _/ _ \ '  \/ -_)
  \_/\_/\___|_\__\___/_|_|_\___|
                                
)" << endl;
        cout << "LennyLang is an esoteric language using, you've guessed it, Lenny Faces as code.\n";
        cout << "\n";
        cout << "Usage: " << argv[0] << " <source-file>\n";
        cout << "       " << argv[0] << " -h        Show this help message\n";
        cout << "       " << argv[0] << " -v        Show version info\n";
        cout << "\n";
        cout << "If <source-file> is '-' (a single dash), input is read from standard input.\n";
        cout << "\n";
        cout << "Enjoy the chaos!\n";
        cout << "========================================\n";
        return 0;
    }

    if (flag == "-v" || flag == "--version")
    {
        cout << "LennyLang ¯\\_(ツ)_/¯ Interpreter version 1.0.0\n";
        return 0;
    }

    string code = load(argv[1]);
    vector<string> tokens = split(code);
    int i = 0;
    LoopBody loop_body;
    // LoopBody code_body = parse_loop(loop_body, tokens, i, false, {});
    vector<variant<string, shared_ptr<LoopBody>>> code_body = parse_tokens(tokens, i);
    for (const auto &t : code_body)
    {
        if (holds_alternative<shared_ptr<LoopBody>>(t))
        {
            cout << "Loop body" << endl;
            PrintLoopBody(get<shared_ptr<LoopBody>>(t)->body);
        }
        else
        {
            cout << "Parsed token: " << get<string>(t) << endl;
        }
    }
    stack<string> todo;
    run_code(code_body, globals, todo);

    return 0;
}