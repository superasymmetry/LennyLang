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

static string load(const string &path) {
    // given a file path, loads the entire file into a string
    ifstream f(path);
    if(!f.is_open()) {
        cerr << "Error opening file: " << path << endl;
        exit(1);
    }
    string s((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
    return s;
}

vector<string> split(const string &s) {
    // given a string s, split it into tokens by whitespace
    vector<string> tokens;
    string cur;
    for(char c : s){
        if(isspace(c)){
            if(!cur.empty()){
                tokens.push_back(cur);
                cur.clear();
            }
        } else {
            cur += c;
        }
    }
    if(!cur.empty()){
        tokens.push_back(cur);
    }
    return tokens;
}

// ---------------- LennyLang Operations ----------------
void output(string thing) {
    cout << thing << endl;
}

// helper function to check if a string is a number
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

// addition operation
string add_two(string a, string b) {
    // if numbers
    if (is_number(a) && is_number(b)) {
        int sum = stoi(a) + stoi(b);
        return to_string(sum);
    }
    return a + b;
}

// subtraction operation
string subtract_two(string a, string b) {
    if (is_number(a) && is_number(b)) {
        int diff = stoi(a) - stoi(b);
        return to_string(diff);
    }
    cerr << "Error: Subtraction requires numeric operands." << endl;
    exit(1);
}

// multiplication operation
string multiply_two(string a, string b) {
    if (is_number(a) && is_number(b)) {
        int prod = stoi(a) * stoi(b);
        return to_string(prod);
    }
    cerr << "Error: Multiplication requires numeric operands." << endl;
    exit(1);
}

// division operation
string divide_two(string a, string b) {
    if (is_number(a) && is_number(b)) {
        if (stoi(b) == 0) {
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
bool is_equal(string a, string b) {
    if (is_number(a) && is_number(b)) {
        return stoi(a) == stoi(b);
    }
    return a == b;
}

// greater-than operation
bool is_greater(string a, string b) {
    if (is_number(a) && is_number(b)) {
        return stoi(a) > stoi(b);
    }
    cerr << "Error: Greater-than comparison requires numeric operands." << endl;
    exit(1);
}

// less-than operation
bool is_less(string a, string b) {
    if (is_number(a) && is_number(b)) {
        return stoi(a) < stoi(b);
    }
    cerr << "Error: Less-than comparison requires numeric operands." << endl;
    exit(1);
}

// variable assignments
struct Value {
    using array_t = std::vector<std::unique_ptr<Value>>;
    using var_t = std::variant<std::monostate, int, double, std::string, array_t>;
    var_t v;

    Value() = default;
    template<typename T> Value(T&& x) : v(std::forward<T>(x)) {}
};

static std::map<std::string, Value> globals;

void assign(string a, string b) {
    globals[a] = Value(b);
}

void PrintStack(stack<string> s)
{
    // used for debugging
    if (s.empty()) 
        return;
    
    string x = s.top();
    s.pop();
    PrintStack(s);
    cout << x << " ";
    s.push(x);
}

int main(int argc, char **argv) {
    string flag;
    if (argc < 2) {
        flag = "-h";
    } else {
        flag = argv[1];
    } 

    if (flag == "-h" || flag == "--help") {
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

    if (flag == "-v" || flag == "--version") {
        cout << "LennyLang ¯\\_(ツ)_/¯ Interpreter version 1.0.0\n";
        return 0;
    }

    string code = load(argv[1]);
    map<string, function<void()>> operations;
    stack<string> todo;
    vector<string> tokens = split(code);
    // print initial stack
    // cout << "Initial todo" << endl;
    // PrintStack(todo);
    // cout << endl;
    for (auto it = tokens.begin(); it != tokens.end(); ++it) {
        // debug
        // cout << "Token: [" << *it << "] Hex: ";
        // stack<string> temp = todo;
        // cout << "Current todo: ";
        // PrintStack(temp);
        // cout << endl;

        // assign variables: open-bracket variable assignment-operator value close-bracket
        if (*it == "(>^o^)>") {
            if (!todo.empty()) todo.pop();
        } else if (*it == "(^o^<)") { //(^o^<)
            // end process
            if (!todo.empty()) {
                todo.pop();
            }
        } else if (*it == "(`O`)") { //( ͡° ͜ʖ ͡°)
            if (todo.empty()) {
                cerr << "Error: Stack underflow on '( ͡° ͜ʖ ͡°)'" << endl;
                return 1;
            }
            output(todo.top());
            todo.pop();
        } else if (*it == "('_')++('_')") { //('_')┏oo┓('_')
            // addition
            if (todo.size() < 2) {
                cerr << "Error: Stack underflow on addition" << endl;
                return 1;
            }
            string a = todo.top(); todo.pop();
            string b = todo.top(); todo.pop();
            string result = add_two(a, b);
            todo.push(result);
        } else {
            todo.push(*it);
        }
    }

    return 0;
}