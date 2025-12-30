# LennyLang (～￣▽￣)～

LennyLang is an esoteric programming language composed entirely of Lenny faces, kaomoji, and expressive ASCII emojis. Despite its chaotic appearance, LennyLang is fully functional and supports variables, arithmetic, arrays, input/output, conditionals, loops, and expression grouping.

This README contains the documentation for this language. 

## Table of contents

- [Variable assignment](#variable-assignment)
- [Commenting](#commenting)
- [Operations](#operations)
- [Brackets](#brackets)
- [Input / Output](#io)
- [While loops](#while-loops)
- [If-Else branching](#if-else-branching)
- [Arrays](#arrays)

## Documentation

<a id="variable-assignment"></a>
### Variable Assignment

One can assign a value to a variable by using the assignment operator, ''':['''. LennyLang will automatically parse the data type of the value, so no data type declaration is needed. One can assign all values with simply the operator, as shown in the example.

```
a :[ 1    // for integer value
b :[ 2.045    // for double value
c :[ ~lennylang is the best!~    // for string value
```

<a id="commenting"></a>
### Commenting

Commenting uses the token (^///^). Comments can be for a full-line or in-line.

Example:
```lennylang
(^///^) commenting is good – go do it
```

```lennylang
~hello lenny~ UwU     (^///^) this is an in-line comment
```

<a id="brackets"></a>
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

<a id="operations"></a>
### Operations

LennyLang supports the arithmetic operations addition, subtraction, multiplication, and division. It also supports operations with strings, such as concatenation. For operations with numbers, all numbers will be cast as float.

Addition

For addition, both numbers and strings are accepted as valid input types. LennyLang will automatically detect the input type and perform the appropriate operation.

```
+_+
```

Example:

```lennylang
a :[ (>^o^)> 6 7 +_+ (^o^<)   (^///^) assigns 13.000000 to a
~a~ ~b~ +_+ UwU     (^///^) prints the string ab
```

Subtraction

```
-_-
```

Example:

```lennylang
b :[ (>^o^)> 6 7 -_- (^o^<)
b UwU    (^///^) prints -1.000000
```

Multiplication

```
*_*
```

Example:

```lennylang
val :[ (>^o^)> 6 7 *_* (^o^<)
val UwU    (^///^) prints 42.000000
```

Division

```
/\_/\
```

```lennylang
val :[ (>^o^)> 6 7 /\_/\ (^o^<)
val UwU    (^///^) prints 0.857143
```

<a id="io"></a>
### Input/Output

One can get a value from the input by using the following token.

```lennylang
(>)_(<)
```
To assign the input value to a variable, use the variable assignment operator followed by the input command. In the example below, we can assign the variable _name_ to a value we obtain from the input.

```lennylang
name :[ (>)_(<)
```

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

<a id="while-loops"></a>
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

<a id="if-else-branching"></a>
### If-Else Branching

If-else statements allow conditional execution of code blocks based on whether a condition is true or false.

If statement start:
```
>.<
```

Else statement:
```
>_<
```

The condition must be enclosed in brackets `(>^o^)>` and `(^o^<)`, and can use the following comparison operators:
- `==` (equality)
- `>` (greater than)
- `<` (less than)

Example:

```lennylang
name :[ ~lenny~
>.< (>^o^)> name == ~lenny~ (^o^<)
    ~yay, you are lenny~ UwU
>_< ~nay!~ UwU
```

Another example with nested if-else branches:

```lennylang
score :[ 85
>.< (>^o^)> score > 80 (^o^<)
    >.< (>^o^)> score > 90 (^o^<)
        ~grade of A~ UwU
    >_< ~grade of B~ UwU
>_< ~go study more~ UwU
```

## License

This language is for fun and chaos. Use it however you like.
