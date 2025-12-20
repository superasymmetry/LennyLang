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

Brackets can be used to temporarily group a set of tokens so that they are processed together, instead of being immediately processed/used.

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

Reads an integer from the user.

Syntax:

```lennylang
( ━☞´◔‿ゝ◔`)━☞ (>^o^)> variable <(^o^<)
```

Example:

```lennylang
( ━☞´◔‿ゝ◔`)━☞ (>^o^)> n <(^o^<)
```

### Output

Prints the value of an expression.

Syntax:

```lennylang
╾━╤デ╦︻(▀̿Ĺ̯▀̿ ̿) (>^o^)> expression <(^o^<)
```

Example:

```lennylang
╾━╤デ╦︻(▀̿Ĺ̯▀̿ ̿) (>^o^)> x <(^o^<)
```

### Variable Declaration

Declares a variable and initializes it to 0.

Syntax:

```lennylang
╰( ⁰ ਊ ⁰ )━☆ﾟ.*･｡ﾟ (>^o^)> variable <(^o^<)
```

Example:

```lennylang
╰( ⁰ ਊ ⁰ )━☆ﾟ.*･｡ﾟ (>^o^)> count <(^o^<)
```

## Control Flow

### While Loops

Syntax:

```lennylang
¯\_( ͡° ͜ʖ ͡°)_/¯ (>^o^)> condition <(^o^<) (｡☉౪ ⊙｡) body (>^o^)><(^o^<)
```

The body executes while the condition is nonzero.

Example:

```lennylang
¯\_( ͡° ͜ʖ ͡°)_/¯ (>^o^)> x <(^o^<)
(｡☉౪ ⊙｡)
    x ¯\_(ツ)_/¯ x (ㆆ _ ㆆ) 1
(>^o^)><(^o^<)
```

### If / Else If / Else

If token:

```
( ͡° ͜ʖ ͡°)
```

Else-if token:

```
( ͡~ ͜ʖ ͡°)
```

Else token:

```
ಠ_ಠ
```

Example:

```lennylang
( ͡° ͜ʖ ͡°) (>^o^)> x <(^o^<)
    ╾━╤デ╦︻(▀̿Ĺ̯▀̿ ̿) (>^o^)> 1 <(^o^<)

( ͡~ ͜ʖ ͡°) (>^o^)> x (ㆆ _ ㆆ) 5 <(^o^<)
    ╾━╤デ╦︻(▀̿Ĺ̯▀̿ ̿) (>^o^)> 2 <(^o^<)

ಠ_ಠ
    ╾━╤デ╦︻(▀̿Ĺ̯▀̿ ̿) (>^o^)> 3 <(^o^<)
```

## Arrays

Create an array (length):

```lennylang
┬──┬ ノ( ゜-゜ノ) (>^o^)> length <(^o^<)
```

Creates an array of the given length, filled with 0.

Example:

```lennylang
arr ¯\_(ツ)_/¯ ┬──┬ ノ( ゜-゜ノ) (>^o^)> 5 <(^o^<)
```

Modify an array element (set/remove):

```lennylang
(ノಠ益ಠ)ノ彡┻━┻ (>^o^)> index <(^o^<) (>^o^)> value <(^o^<)
```

Example:

```lennylang
arr (ノಠ益ಠ)ノ彡┻━┻ (>^o^)> 2 <(^o^<) (>^o^)> 99 <(^o^<)
```

## Full Example Program

Program: Sum of first N integers

```lennylang
╰( ⁰ ਊ ⁰ )━☆ﾟ.*･｡ﾟ (>^o^)> n <(^o^<)
╰( ⁰ ਊ ⁰ )━☆ﾟ.*･｡ﾟ (>^o^)> sum <(^o^<)

( ━☞´◔‿ゝ◔`)━☞ (>^o^)> n <(^o^<)

¯\_( ͡° ͜ʖ ͡°)_/¯ (>^o^)> n <(^o^<)
(｡☉౪ ⊙｡)
    sum ¯\_(ツ)_/¯ sum ('_')┏oo┓('_') n
    n ¯\_(ツ)_/¯ n (ㆆ _ ㆆ) 1
(>^o^)><(^o^<)

╾━╤デ╦︻(▀̿Ĺ̯▀̿ ̿) (>^o^)> sum <(^o^<)
```

## Notes

- Use consistent bracket tokens for grouping: `>^o^)>` and `<(^o^<`.
- Keep expressions simple while composing complex logic.

## License

This language is for fun and chaos. Use it however you like.
