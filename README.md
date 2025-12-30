# LennyLang

LennyLang is an esoteric programming language composed entirely of Lenny faces, kaomoji, and expressive ASCII emojis. Despite its chaotic appearance, LennyLang supports variables, arithmetic, arrays, input/output, conditionals, loops, and expression grouping.

This README is a concise language reference (formatted like a wiki page) with token reference and runnable-looking examples.

## Features

- Integer variables
- Arrays
- Input / Output
- Addition & subtraction
- If / Else If / Else
- While loops
- Brackets for grouping
- Variable declaration
- Array indexing / updating

## Syntax Reference

### Operations (tokens)

Assignment / Equality
Assigns the value on the right to the variable on the left.

```
:[
```

Example:

```lennylang
x :[ ~hello~
a :[ 2
a :[ (>^o^)> a - 1 (^o^<)
```

Addition

```
+_+
```

Example:

```lennylang
a :[ 6 7 +_+    // assigns 13 to a
~a~ ~b~ +_+ UwU     // prints the string ab
```

Subtraction

```
-_-
```

Example:

```lennylang
b :[ 10 2 -_-
b UwU    // prints 8
```

### Brackets

Brackets can be used to form an expression by temporarily grouping a set of tokens so that they are processed together, instead of being immediately processed/used.

Opening bracket:

```
(>^o^)>
```

Closing bracket:

```
(^o^<)
```

Example:
In this example below, the sum of 3 and 4 are assigned to the variable x. If there were no brackets, 3 would be immediately assigned to x, and 4 would be processed before the add operation, resulting in a stack underflow error.

```lennylang
x :[ (>^o^)> 3 4 +_+ (^o^<)
```

### Input

One can get a value from the input by using the following token.

```lennylang
(>)_(<)
```
To assign the input value to a variable, use the variable assignment operator followed by the input command. In the example below, we can assign the variable _name_ to a value we obtain from the input.

```lennylang
name :[ (>)_(<)
```

### Variable Assignment

One can assign a value to a variable by using the assignment operator, ''':['''. LennyLang will automatically parse the data type of the value, so no data type declaration is needed. One can assign all values with simply the operator, as shown in the example.

```
a :[ 1    // for integer value
b :[ 2.045    // for double value
c :[ ~lennylang is the best!~    // for string value
```

### Output

For the kernel to write an output, one can use the following token.

```lennylang
UwU
```
The standard syntax is to put the value/variable before the output token, separated by a space. For example, 

```lennylang
1 UwU
```
outputs 1, and 

```lennylang
val :[ ~hello world~
val UwU
```
outputs hello world.

## Control Flow

### While Loops

While loops allow you to repeatedly execute a block of code as long as a condition is true. The loop begins with `OwO` followed by a condition in brackets, and ends with `>:3`.

Loop start:
```
OwO
```

Loop end:
```
>:3
```

The condition must be enclosed in brackets `(>^o^)>` and `(^o^<)`, and can use the following comparison operators:
- `==` (equality)
- `>` (greater than)
- `<` (less than)

Example:

```lennylang
i :[ 0
OwO (>^o^)> i < 5 (^o^<)
    i UwU
    i :[ (>^o^)> i 1 +_+ (^o^<)
>:3
```

This loop prints the numbers 0 through 4. It continues while `i` is less than 5, incrementing `i` by 1 each iteration.

Another example with string comparison:

```lennylang
answer :[ ~no~
OwO (>^o^)> answer == ~no~ (^o^<)
    ~Enter yes to continue: ~ UwU
    answer :[ (>)_(<)
>:3
```

This loop continues asking for input until the user enters "yes".

### If-Else Branching

If-else statements allow conditional execution of code blocks based on whether a condition is true or false.

If statement start:
```
( ͡° ͜ʖ ͡°)
```

Else statement:
```
( ͡° ʖ̯ ͡°)
```

If-else end:
```
ಠ_ಠ
```

The condition must be enclosed in brackets `(>^o^)>` and `(^o^<)`, and can use the following comparison operators:
- `==` (equality)
- `>` (greater than)
- `<` (less than)

Example:

```lennylang
age :[ 18
( ͡° ͜ʖ ͡°) (>^o^)> age > 17 (^o^<)
    ~You are an adult~ UwU
( ͡° ʖ̯ ͡°)
    ~You are a minor~ UwU
ಠ_ಠ
```

This checks if `age` is greater than 17. If true, it prints "You are an adult", otherwise it prints "You are a minor".

Another example with equality:

```lennylang
password :[ (>)_(<)
( ͡° ͜ʖ ͡°) (>^o^)> password == ~secret~ (^o^<)
    ~Access granted~ UwU
( ͡° ʖ̯ ͡°)
    ~Access denied~ UwU
ಠ_ಠ
```

## License

This language is for fun and chaos. Use it however you like.
