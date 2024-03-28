# Introduction

## Welcome to Ignite - programming language that transpiles down to C++!
This project started as my replacement to C, I did not like the "do it all yourself" aspect of it. I know it is quite fun to make small code that all work together to solve large problems, but it got bored to me so I decided to make a programming language that transpiles down to C++! It transpiles to C++ instead of C just let C++ do some heavy lifting for me...

Why didn't I just straight up use C++ you may ask? Check the source code of this language transpiler - cause I did use C++ for it. C++ has some tricky to understand features that is not my style. I would like to use C# but it just refused to elaborate in my Linux system, and I want it to be simple and not filled with OOP (Ignite does have *some* OOP). I have tried other programming languages but they just don't fit my style so, here born the Ignite (~~setting flame to every other programming languages~~). I am also highly against the concept of "Data Hiding" or "Access Specifier" (primary reason why I don't like using `class` in C++) and I wanted to achieve freedom and customization in my language.

Ignite is inspired by multitude of programming languages, mainly C/C++, and sometimes C#, Python, Rust (yes). So I **want** the readers to be familiar with the concepts in C/C++ programming language before diving deep in this tutorial. This is **not** a beginners guide to programming and beginners are highly encouraged to learn the C (preferably from https://beej.us/guide/bgc) and C++ (preferably from https://learncpp.com) before taking this tutorial. You don't need to learn all of C++ but vast amount of C knowledge is ideal.

Remember that Ignite only transpiles the high level Ignite source files down to C source file. It does not compile all the way down to assembly or machine code (binary, or whatever you call it). You might consider installing a C++ compiler to compile it all the way down to a machine code.

### Whom this Programming Language Is For?
- Myself.
- My friends.
- Any enthusiastic programmers who is interested to check on small projects.

### Whom this Programming Language Is NOT For?
- Professional Projects
- Critical Softwares
- Real Products

So yeah. This is mainly my personal project. Take Ignite as a grain of salt. This isn't to say that Ignite is bad. I just don't want people to use Ignite in a professional setting and then put a huge pressure on me when it does have some stability and maintainability issues. I will move the items from Is NOT list to Is list, slowly as I refine Ignite.

## Contribution and Forking
Feel free to contribute to this project. I appreciate it. If you want, you can take the specifications of this language and build your own compiler that compiles all the way down to machine code, using your preferred programming language (heck even Ignite if you will). I would love to see an implementation of this project in a different way. Name it ignite-(your-edition) and you gain my attention.
See [SPECS.md](SPECS.md)

## Licensing Terms
This project is licensed under the [MIT License](LICENSE).

## Tutorials
Tutorials are in a single file, [this README.md file](README.md). So without further ado, let's get started!

# Table of Content

**PENDING**

# Installation

## Pre-built Binaries

**PENDING**

Operating System                 | Download
-------------------------------- | --------
*Template*                       | *Package Installation Command*
Other operating systems          | https://github.com/anstropleuton/ignite/releases

## Other Linux Distributions
The official packages may not be available for your other Linux distribution (ones that are not mentioned above). In that case, you can [Build from source](#building-from-source).
But in case if the Ignite programming language's package is available from your distribution's package manager, remember that it is not officially supported.

## Building From Source
 1. Install Git, GNU Make, and GNU C++ compiler.
 2. Run the following commands:
    ```
    git clone https://github.com/anstropleuton/ignite
    cd ignite
    make all
    sudo make install # Only for Unix/Unix-like systems
    ```

## Testing
Test and make sure the compiler is working properly, grab the below `Hello, World!` example and save it to a file named `hello_world.ign`. To compile the file down to C, use the following command:
```
ignite hello_world.ign -o hello_world.c
```
This will create a C source file named `hello_world.c` which you can optionally compile down to a binary.

# Hello, World!
This simple program demonstrates the structure of the Ignite programming language. Don't worry, it is similar to C:

```ign
## Hello, World! - Ignite

# This is a comment and will be preserved in the generated C code.

# Include the standard input and output library
include io : ign.io;

# The entry point main function of the program
int main(# Comment can end before newline #)
{
    # Print a line to the console
    io.print("Hello, World!\n");
}
```

In this example,
- Everything after `#` is a comment and will be preserved in the generated C code.
    - You can use another `#` to end comment before the newline.
    - Use a backslash (`\`) before `#` to not end the comment before the newline.
- `include` is a module inclusion. It searches the availability of the modules in the current directory, include path of your system and installation path for libraries.
    - `ign.io` is a module that provides functionality to interact with console input and output.
    - `io` is the explicit namespace at which the contents of `ign.io` exist.
    - If `io : ` is omitted, you would have to use `ign.io` in your code. You an use any other name that suits your needs.
- `main` is the main entry point function, this is where the program starts executing the code.
    - `int` is an integer, in this case it denotes the return type of the function.
    - Main function either takes no arguments, or takes `char[][] args` as its argument.
    - If a function takes no arguments, `()` is optional.
- `io` is the explicit namespace that wraps the contents of `ign.io` module.
- `.` is the dot operator used to access contents of the namespace, or structures. A namespace in this case.
- `print` is a function used to print string to the console output.
- `"Hello, World!\n"` is the string in question to be printed on the console output. The `\n` is a new line character which finishes the line and moves the cursor to next line.
- `;` is optional and used to end a statement. It is recommended to explicitly use semicolons to end a statement.

# Variables and Basic Operations

This simple program demonstrates the creation and manipulation of variables using basic operators. We will be using only integers (`int`s) in this example:

```ign
include io : ign.io;

int main()
{
    # Declare a variable
    int variable_name;

    # Assign a value to the variable using the `=` (assignment) operator
    variable_name = 2; # Here, `2` is a numerical literal, an integer constant in this case

    # Declare another variable
    int another_variable_name; # The name must be different from what you used before

    # Assign this variable with the one we created earlier
    another_variable_name = variable_name;

    # Print the value of the `another_variable_name` variable
    io.print("The value of the `another_variable_name` variable is {another_variable_name}\n"); # String interpolation. See [String Interpolation](#string-interpolation)
    # ... Use `{{` and `}}` if you want to print literal `{` and `}`

    # For simplicity sake, we will use small variable names from here onward
    int a; # By default the variable will be assigned to `0`

    # Declaring and initializing in a single statement
    int b = 10; # Declare `b` and initialize it (assign value to it) to `10`

    # Declaring multiple variables in a single statement. Here,
    #   `c` is declared and initialized to `0` (by default)
    #   `d` is declared and initialized to `20`
    #   `e` is declared and initialized to `32`
    int c, d = 20, e = 32;



    # Arithmetic Operators

    # Prepare a few variables for demonstration
    b = 10;
    c = 3;

    # Addition
    a = b + c; # This will evaluate `b + c` (`10 + 3`) and assign that to `a` (`a` is now `13`)

    # Subtraction
    a = b - c; # `10 - 3` = `7`

    # Multiplication
    a = b * c; # `10 * 3` = `30`

    # Division (flooring performed)
    a = b / c; # `10 / 3` = `3.333333`... but floored to `3` because integer data type can hold only integer values

    # Modulo (or reminder)
    a = b % c; # `10 % 3` = `1`

    # Exponential (or power)
    a = b ** c; # `10 ** 3` = `1000`



    # Compound Assignment Operator

    # The statement
    a = a + b;
    # can be simplified to
    a += b;
    # This basically means add the value of `b` to the variable `a`

    # Same goes for subtraction, multiplication, division, modulo and exponential operator (including addition here)
    a  += b; # Addition
    a  -= b; # Subtraction
    a  *= b; # Multiplication
    a  /= b; # Division
    a  %= b; # Modulo
    a **= b; # Exponential



    # Increment and Decrement operator

    # Preparation
    a = 2;
    b = 3;

    # This statement
    a += 1; # `a` is now `3`
    # can further be simplified to
    a++; # `a` is now `4`
    # This basically means add `1` to `a`
    # BUT. There is a catch.
    # `a++` does return a value which can be used to assign other variables:
    b = a++;

    # But the position of the `++` (whether it is before or after the variable name) matters. In this case, it is "post increment operator". That means it will use the value of `a` to assign `b` before it increments `a`. So `b` is now `4` and `a` is now `5`

    # But in case of "pre increment operator",
    b = ++a; # `a` is incremented first and then the value of `a` is assigned to `b`. So `b` and `a` both are now `6`

    b = a++; # `b` = `6` and `a` = `7`
    b = ++a; # `b` = `8` and `a` = `8`

    # Decrement works in a similar way but subtracts `1` instead of adding `1`. So same goes for decrement
    b = a--; # `b` = `8` and `a` = `7`
    b = --a; # `b` = `6` and `a` = `6`

    # NOTE: assignment, compound and increment/decrement operator cannot be used on numerical literals
    # 5 = a;  # Error: cannot assign value to numerical literal
    # 5 += 2; # Error: cannot assign value to numerical literal
    # 5++;    # Error: cannot increment value of numerical literal
}
```

# Naming Rules

While naming a variable, function, structure, namespace, etc., you have to follow several rules to define a name for the variable. The naming rules are as follows:
 1. Names only starts with `a`-`z`, `A`-`Z` or `_`.
 2. Names can only contain `a`-`z`, `A`-`Z`, `_` or `0`-`9`.
This implies that names cannot contain special characters or symbols, and cannot start from a number. This naming convention matches traditional naming conventions.

# Recommended Code Style (Simple Edition)

## Naming
 1. Name user-defined types in `Pascal_Snake_Case`.
 2. Name constants in `UPPER_SNAKE_CASE`.
 3. Name everything else in `snake_case`.

## Break Before Brace
 1. Always break before brace if the contents in the brace defines statements.
 2. Never break before brace for everything else (including structure definitions).

## Tabs vs. Spaces
Use 4 spaces. This allows consistency across multiple source code editors. Also I am not never nester.

## Arguments?
There is no argument to which is the best style guidelines. But there is an argument to maintain consistency of style across your project.

# Data Types and Sizes

## Integer Types
You have seen the `int` type in the previous example. But just for clarity, it stores integers. but with the computer memory, you can only hold so much value before it too can become limiting. And this is no different in several programming languages. An `int` in Ignite is not a magical thing that can hold any integer numbers, it has defined limits. In Ignite, `int` variable can only hold values that fall under the range of `-2147483648` to `2147483647` (both inclusive). But to support the range of use cases, from cases where holding anything more than `64` may be pointless, to cases where holding a really large number more than `2147483647` is required, there are several variants of `int`s with different sizes:

### Regular `int`
Regular integer (`int`) has a size of 32 bits and it can hold values in the range of `-2147483648` to `2147483647`.
```ign
int integer_type = 42;
```

### Shortest `int`
Shortest integer (`int8`) is of 1 byte or 8 bits (the minimum allowed by most-if-not-all systems) and it can hold values in the range of `-128` to `127`.
```ign
int8 shortest_int = 127;
```
You can also use `int08` if you want that sweet, very sweet alignment.

### Short `int`
Short integer is what many of you, developer, may recognize as int of 2 bytes or 16 bits, is the same in Ignite, and it can hold values in the range of `-32768` to `32767`.
```ign
int16 short_int = 32767;
```

### Regular `int` pt. 2
There is an alternative typename for `int`, which is `int32` (for sake of consistency). It is exactly the same as `int`.
```ign
int32 regular_int = 2147483647;
```

### Long `int`
You can tell that it is the C's `long` (usually, if not `long long`): It is 8 bytes or 64 bits and it can hold values in the range of `-9223372036854775808` to `9223372036854775807`.
```ign
int64 long_int = 9223372036854775807;
```

You can also use `sint` and their variants (`sint16`, etc.) to explicitly specify signed integer types (again, for sake of consistency).

## Unsigned Integer Types
In certain scenarios, you do not need the negative values that is offered by integers. For example: distance between two cars, number of apples, etc. In those cases, it might be wasteful to use integer type only to use the half of it's range, which might be fine for most cases but it isn't ideal. Ignite provides you unsigned integers which only hold positive values. We can't just remove negative numbers from existence, instead we can use that one bit which will result in removing the signing of integer (sign bit, for those who are familiar) and with this extra bit in hand, we can double the upper bound of the range. The byte size of the unsigned integer types compared to their regular counterpart is same:

### Regular unsigned `int`
Unsigned version (`uint`) of regular int (`int`), it can hold values in the range of `0` to `4294967295`.
```ign
uint unsigned_int = 84;
```

### Shortest unsigned `int`
Unsigned version (`uint8`) of shortest int (`int8`), it can hold values in the range of `0` to `255`.
```ign
uint8 shortest_unsigned_int = 84;
```
Again, you can use `uint08` if you want that extremely sweet alignment.

### Short unsigned `int`
Unsigned version (`uint16`) of short int (`int16`), it can hold values in the range of `0` to `65535`.
```ign
uint16 short_unsigned_int = 65535;
```

### Regular unsigned `int` pt. 2
Again for consistency, here is `uint32` as the exact same type as of `uint`.
```ign
uint32 regular_unsigned_int = 4294967295;
```

### long unsigned `int`
Unsigned version (`uint64`) of long int (`int64`), it can hold values in the range of `0` to `18446744073709551615`.
```ign
uint64 long_unsigned_int = 18446744073709551615;
```

## Floating Point (decimal) Types
Not always will you be storing the whole integers, you might sometimes also want to store real numbers (numbers which may contain a decimal point). This can be the time passed before you shoot the bullet and it hit the target, or the angle between you looking straight and the sun, etc. To address this, Ignite introduces (mostly copies from other programming languages) the floating point types. This can hold the values with decimal point in it. Although it might be logical to assign a range, developers have identified that it is unbalanced. And researchers at IEEE have developed standard 754 to describe a standardized and balanced way to define decimal numbers. And hence a little buggy but very convenient way of storing decimal point was born: floating point. So we will measure with the number of digits of decimal that a float type can (usually) be precise at:

### Regular `float`
Regular float (`float`) is a single precision floating point type that can be precise up to 7 decimal digits.
```ign
float decimal_value = 3.14;
```

### Regular `float` pt. 2
There is an alternative typename for `float`, which is `float32` (again, for sake of consistency). It is exactly the same as `float`.
```ign
float32 regular_float = 1.414213;
```

### Double Precision `float`
The double precision float type can be precise up to 15 to 16 decimal digits.
```ign
float64 double_float = 2.71828182845904;
```

## Character Type
This is another type of data that is regularly used in various programming language: `char`. Characters in Ignite is 1 byte, and there is no variations of `char` with other number of bytes, such as `char16` or `char32`. They do not exist in Ignite. The character literals in Ignite is encoded using the American Standard Code for Information Interchange (ASCII), which uses 7 bits of a byte to represent characters (leaving one unused). This encoding allows for the representation of 127 different characters, including alphabets, numerals, symbols, whitespace characters, and special characters defined by ASCII.
```ign
char c = 'a'; # `'a'` is a character literal
```
It's worth noting that you can use a numerical value and assign it to a `char` type. This will result in conversion from numerical representation of the underlying value of a char literal. You can refer an ASCII table to identify the numerical representation of each character:
```ign
char c = 49; # `c` now has the value of letter `'I'`.
```

## Boolean type
A boolean type (`bool`) only stores the values of `1` and `0`, aka `true` and `false`. You may think that `bool` is 1 bit in size but remember: nothing can be smaller than one byte in Ignite, so actually `bool` is 1 byte just like `int8`, so that means `true` anything that is not `0`, and `false` is `0`. This isn't to say that you can use `bool` instead of `int8`, so don't do that. It's only good for `true` and `false`.
```ign
bool b = true;
```
More complex boolean expressions can be made with logical operators, see [Booleans](#booleans).

## Casting
A variable of fundamental data type can be implicitly or explicitly converted to other fundamental data type. Fundamental data types refers to the above discussed data types, including `int`, `float`, `char`, `bool`, etc.
Implicit Casting:
```ign
int integer = 42;
float floating_point = 3.141592;
int float_to_int = floating_point; # `float_to_int` is now `3`
float int_to_float = integer; # `int_to_float` is now `42` (but in `float` data type)
```
Explicit Casting (usually not required):
```ign
int integer = 42;
float floating_point = 3.141592;
int float_to_int = (int)floating_point; # `float_to_int` is now `3`
float int_to_float = (float)integer; # `int_to_float` is now `42`
```

## `auto`
The `auto` keyword is used to define a variable whose type is determined by the type of value the variable is being assigned (more can be dome with `auto`, we will talk about it later). For instance:
```ign
auto variable = 7;
```
Here, `auto` is now a type of `int8` (lowest sized integer that can hold the value `7`).
It's important to note that this variable cannot be declared as such:
```ign
auto variable; # Error: unknown type
```
This is because the `auto` resolves it's type on initialization and the type of variable does not change throughout the existence of the variable.

## Promotion
What happens when you multiply an integer value with a floating point value? Data type promotion takes place. The integer is converted to a floating point value and resulting data type of the expression is a floating point type. For example:
```ign
float value_1 = 2.5;
int value_2 = 4;
auto value_3 = value_1 * value_2; # `value_3` will be of `float64` type
```
The conversion rules are slightly different for different operators:
- Firstly, if there is any operation of two different types, the higher order ones are selected. The order list is:
    `bool`, `char` < `int` < `uint` < `float`
    This also means addition, multiplication, etc. of `bool` with `float` results in a `float` value.
- Secondly, if there is any operation of two same types but of different sizes, the highest possible size is picked.
    This means value of `int8` times value of `int16` will result in `int64`.
    - The "Highest possible" is the highest ever possible if you are initializing a value to `auto` variable, or the "Highest possible" is the type of variable.

## Example Usage for Data Types
```ign
## Example Usage for Data Types - Ignite

include io : ign.io;

int main()
{
    # Make use of regular or unsigned int for most scenarios
    int amount_withdrawn = 100000;

    # Make use of memory efficiently by utilizing small size int in scenarios like this
    uint8 pixel_brightness = 64;

    # Output unsigned int
    io.print("Brightness of pixel is: {pixel_brightness}\n");

    # Use double precision for better floating point arithmetic in scenarios where precision matters more
    float64 pi = 3.14159265358979;

    # Use auto for the same type (not the most recommended use of `auto` tho, so don't)
    auto tau = 2.0 * pi;

    # Output a float
    io.print("Value of pi is: {pi}\n");

    # Store the character
    char c = 'I';

    # Output a character
    io.print("Value of c is: {c}\n");

    # Convert character to int
    int character_as_int = (int)c; # `character_as_int` now has `49` as it's value

    # Implicit conversion
    int pixel_brightness_squared = pixel_brightness ** 2; # Convert `pixel_brightness` to `int` and then square it
}
```

# Numerical Literals

In case of the example:
```ign
int my_size = 36;
```
and
```ign
float my_approximation = 4.57;
```
The numerical literals are `36` and `4.57`. However, if you want to incorporate size in the literal, or if you want to represent number from a different number system, you can use suffixes (for sizes):
```ign
auto my_number = 2.4f46_32; # `_32` suffix denotes a `float32` type
```
or prefixes:
```ign
auto my_digit = 0x34d25f; # Here, `0x` denotes a hexadecimal, which is equivalent to `3461727`
```
Here is the chart for all the built-in systems and sizes:

Type          | Prefix | Suffix | Description                       | Applicable For
------------- | :----: | :----: | --------------------------------- | --------------
Number System | 0x     | \-     | Hexadecimal Number                | All Numerical Literal
Number System | 0o     | \-     | Octal Number                      | All Numerical Literal
Number System | 0d     | \-     | Decimal Number                    | All Numerical Literal
Number System | 0b     | \-     | Binary Number                     | All Numerical Literal
Type          | \-     | _i     | Signed Type                       | Only Integer Literal
Type          | \-     | _u     | Unsigned Type                     | Only Integer Literal
Type          | \-     | _s     | Signed Type                       | Only Integer Literal
Type          | \-     | _f     | Floating Point Type               | All Numerical Literal
Type and Size | \-     | _i*n*  | Size Provided Signed Type         | Only Integer Literal
Type and Size | \-     | _u*n*  | Size Provided Unsigned Type       | Only Integer Literal
Type and Size | \-     | _s*n*  | Size Provided Signed Type         | Only Integer Literal
Type and Size | \-     | _f*n*  | Size Provided Floating Point Type | All Numerical Literal

Where *n* is the number of bits for the size.
There however is no exponent because power operator `**` can be used.
You can overload them by introducing your own numerical literal format, see [Literal Overloading](#literal-overloading).

You can also use a single quote to separate the values just as humans tend to separate large number with a commas (or periods depending on what country you live in):
```ign
int amount_1 = 8'345'319;
# Same as:
int amount_2 = 8345319;
```

## Example Usage for Numerical Literals
Hexadecimal integer:
```ign
int hex = 0x54acfb8e;
```
Unsigned integer:
```ign
auto unsigned = 14'35'45'232_u; # Just an example that `'` doesn't need to be uniformly placed
```
Signed 64-bit integer encoded in octal:
```ign
auto signed = 0o1377_s64;
```

64-bit (Double precision) floating point value represented as binary:
```ign
# NOTE: This is not the actual bit representation of a `float` value
auto floating = 0b11010.1001_f64; # 26.5625
```

# Standard I/O and Format Specifiers

Not always will you be printing stuff on the console, you might also want to get stuff off of the console by the user. Don't you? In that case, you can use `io.scan` function.
```ign
## I/O - Ignite

include io : ign.io;

int ign.main()
{
    int output = 3;
    io.print("Value of output: {output}\n"); # Print the value of output to the console using string interpolation
    # Use `{{` and `}}` if you want to print literal `{` and `}`

    io.print("Enter a value: ");
    int input;
    io.scan(&input); # Use the & (address-of) operator to get the pointer, and use it for argument. See [Pointers](#pointers)
    # When user enters digits and presses enter button, the `scan` function will take the input and store it in `input` variable
    # Internal parsing occurs. Failure in parsing will not alter the value

    # Print the value that the user has entered
    io.print("You entered: {input}\n");
}
```

## Format Specifiers
Wait hold on... where are format specifiers as promised in the title? For this, we use C's `printf` and `scanf` functions. This works a bit differently... This deserves the real Standard I/O and Format Specifiers title:
```ign
## Standard I/O and Format Specifiers - Ignite/C

# This time, we will use C's standard IO
include stdio : c.stdio;

int main()
{
    int output = 4;
    stdio.printf("Value of output: %d\n", output); # Here, `%d` is a placeholder for which the value of the `output` will be placed before printing to console, you can also use `%i`

    stdio.printf("Enter a value: ");
    int input;
    stdio.scanf("%d", &input);

    # Few common Format Specifiers for scanning (input)
    stdio.printf("Enter a character: ");
    stdio.scanf("%c", &ch);

    stdio.printf("Enter an integer in normal form: ");
    stdio.scanf("%d", &num);

    stdio.printf("Enter an integer in normal, octal or hexadecimal form: ");
    stdio.scanf("%i", &num);

    stdio.printf("Enter an unsigned integer: ");
    stdio.scanf("%u", &unum);

    stdio.printf("Enter a float: ");
    stdio.scanf("%f", &fnum);

    stdio.printf("Enter a double (float64): ");
    stdio.scanf("%lf", &dnum);

    # Few common Format Specifier for printing (output)
    stdio.printf("\nValues entered:\n");
    stdio.printf("Character: %c\n", ch);
    stdio.printf("String: %s\n", str);
    stdio.printf("Integer: %d\n", num);
    stdio.printf("Unsigned Integer: %u\n", unum);
    stdio.printf("Float: %f\n", fnum);
    stdio.printf("Double: %lf\n", dnum);
}
```

# Booleans

## Boolean Operators
Before you understand control flow statements (we will get to it later), you need to understand boolean operators. This is because of the use of boolean conditions in control flow statements. Even for boolean, you could use regular addition (`+`) and multiplication (`*`) to perform logical OR and AND between two conditions, but that is not recommended. It is prone to overflow of underlying integer which can produce false results (not `false` results, I mean to say inaccurate results). Overflow is when you assign a value that falls out of the type's range. It rolls back to the opposite side of the range (just learn C pls). For example, let's say you have done a lot of addition operator to get the OR of the two condition. Suddenly, the underlying integer overflowed to negative and later became `-1`? When doing addition operation for `-1` and `1` it becomes `false`. The actual OR operator would see it as non-zero OR non-zero, basically `true` OR `true` which is `true`. We got an incorrect result. So, we use special logical operators instead:

### Logical AND
Logical AND (`&&`) operator gives the AND of it's operands,
For `A && B` where `A` and `B` are boolean values:

  A   |   B   |  Result
:---: | :---: | :------:
  0   |   0   |    0
  0   |   1   |    0
  1   |   0   |    0
  1   |   1   |    1

Only when both `A` and `B` are `true`, the evaluated result is `true`.

### Logical OR
Logical OR (`||`) operator gives the OR of it's operands,
For `A || B` where `A` and `B` are boolean values:

  A   |   B   |  Result
:---: | :---: | :------:
  0   |   0   |    0
  0   |   1   |    1
  1   |   0   |    1
  1   |   1   |    1

Only when either `A` or `B` or both are `true`, the evaluated result is `true`.

### Logical NOT
Logical NOT (`!`) operator gives the inverse of it's operand (there is only one operand and that is at the right of the operator),
For `!A` where `A` is boolean value:

  A   |  Result
:---: | :------:
  0   |    1
  1   |    0

Only when `A` is `false`, the evaluated result is `true`.

## Comparison Operators
To actually make expressions that can get you boolean values, you need comparison operators:

- Greater than (`>`), return `true` when the value of the left operand is grater than the value of right operand.
- Less than (`<`), return `true` when the value of the left operand is less than the value of right operand.
- Greater than or equal to (`>=`), return `true` when the value of the left operand is grater than or equal to the value of right operand.
- Less than or equal to (`<=`), return `true` when the value of the left operand is less than or equal to the value of right operand.
- Equal to (`==`), return `true` when the value of the left operand is equal to the value of right operand.
- Not Equal to (`!=`), return `true` when the value of the left operand is not equal to the value of right operand.

## Example Usage for Logical and Comparison Operators
```ign
## Example Usage for Logical and Comparison Operators - Ignite

include io : ign.io;

int ign.main()
{
    int total_fruits_cost = 13;
    int total_vegetables_cost = 3; # Low on vegetables :(

    # Using comparison operators
    bool apply_fruit_discount = total_fruits_cost > 10; # `true`
    bool apply_vegetable_discount = total_vegetables_cost > 5; # `false`, buy some more vegetables ;)

    # Using logical operators
    bool apply_discount = apply_fruit_discount || apply_vegetable_discount; # `true`
    bool no_discount = !apply_discount; # `false`

    bool is_high_season = true;
    bool is_member = false;

    # Just a tiny bit complex
    bool eligible_for_extra_discount = apply_discount && (is_high_season || is_member);
}
```

## Assigning Boolean Expressions
To store the results that you get from a boolean expression, you use the `bool` type and assign the value of the expression. For example:
```ign
int a = 3;
int b = 4;
bool is_a_greater = a > b; # The value of `is_a_greater` is `false` or `0`
```

## Bitwise Operators
Variables are stored in memory. How do you represent memory? In terms of bytes. What does a byte consist of? 8 bits. Only if there was a way to manipulate individual bits of the memory of a variable... Enter Bitwise Operators:

### Bitwise AND
Let's consider two 16-bit unsigned integer (`uint16`) `a` and `b`. Bitwise AND operator (`&`) takes the AND of the individual bits of `a` and `b`:
```ign
uint16 a = 0b'0000'0010'1101'0100; # `724`
uint16 b = 0b'0000'0010'0100'1101; # 589

uint16 c = a & b; # `c` is now `0b'0000'0010'0100'0100` or `580`
```

### Bitwise OR
Let's take the same value as above. Bitwise OR operator (`|`) takes the OR of the individual bits of `a` and `b`:
```ign
uint16 d = a | b; # `d` is now `0b'0000'0010'1101'1101` or `733`
```

### Bitwise NOT
Bitwise NOT operator (`~`) takes the NOT of the individual bits of `a`:
```ign
uint16 e = ~a; # `e` is now `0b'1111'1101'0010'1011` or `64811`
```
The number of `0` bytes before the `1` (if any) that are flipped (NOTed) does not depend on the literal, instead it depends on the size of the variable. For example:
```ign
uint16 f = 0b'1101'0010;
uint16 g = ~f; # You may think `g` is `0b'0010'1101` but it actually is `0b'1111'1111'0010'1101`
```

### Bitwise XOR
Bitwise XOR operator (`^`) looks like power operator. Its not. It takes the XOR of the individual bits of `a` and `b`:
```ign
uint16 h = a ^ b; # `h` is now `0b'0000'0000'1001'1001`
```

### Bitwise Left Shift
You know how you can multiply a decimal number by 10 to make all it's digits appear one digit towards left? You can do that to the bits too:
```ign
uint16 i = 0b'0101'0011; # 83
uint16 j = i << 1; # `i` left shifted by one bit, `j` is `0b'1010'0110` or `166`
uint16 k = i << 3; # `k` is `0b'0010'1001'1000` or `664`
```

### Bitwise Right Shift
Same as left shift but opposite, or as if dividing a decimal number by 10:
```ign
uint16 l = i >> 1; # `i` right shifted by one bit, `l` is `0b'0010'1001` or `41`
uint16 m = i >> 3; # `i` right shifted by one bit, `m` is `0b'1010'` or `10`
```

You can do right shift by using left shift operator with negative number of bits to shift towards left, and same goes for left shifting:
```ign
uint16 n = i >> -3; # Same as `i << 3`, so `n` is `0b'0010'1001'1000` or `664`
```

# Control Flow

If you want to execute some part of code depending on some input from user, or other conditions - Whether it might be moving the player forward when the user presses W key, or changing the color of an object based on the time of day, you would use control flow statements to achieve this.

## `if` Statement
This is a basic control flow statement that allows you to execute a statement or block of statements provided a specific condition to be non-zero:
```ign
if (condition)
{
    statement1;
    statement2;
    statement3;
    # Execute the statements in this block, a block is defined by a `{` and `}`
}
```

Or if there is only one statement, you can simplify by removing the block
```ign
if (condition)
    statement;
```
This applies for all the other statements

For example:
```ign
bool player_has_sword;
# ...
if (player_has_sword)
{
    # Alert nearby mobs to attach the player
}
```

You can directly use the boolean expression as the condition:
```ign
int users_count;
const int MAX_USERS_PER_ROOM = 20;
# ...
if (users_count > MAX_USERS_PER_ROOM)
{
    # Move some users to different room
}
```

## `else` Statement
The `else` statement optionally comes right after an `if` statement. This statement is executed only if the condition of the `if` statement turns out to be `false` or `0`.
```ign
if (condition)
    statements_if_condition_is_true;
else
    statements_if_condition_is_false;
```

For example:
```ign
int score;
# ...
if (score < 10)
{
    # Allow user to retry
}
else
{
    # Move on to next stage
}
```

You may think that you would want only the `else` part of the code for whatever reason, but it is redundant to do this way:
```ign
int password_length;
# ...
if (password_length < 10)
{
    # Empty block
}
else
{
    # Allow password
}
```

But you can just flip the condition and do this:
```ign
int password_length;
# ...
if (password_length >= 10)
{
    # Allow password
}
```

## `if`-`else`-`if` Ladder
You can chain the `if` and `else` to create a ladder:
```ign
if (first_condition)
{
    # First code (ran if the `first_condition` is `true`)
}
else if (second_condition)
{
    # Second code (ran if the `first_condition` is `false` and `second_condition` is `true`)
}
else if (third_condition)
{
    # Third code (ran if the `first_condition` is `false` and `second_condition` is `false` and `third_condition` is `true`)
}
else
{
    # Final code (ran if all the above condition is `false`)
}
```

For example:
```ign
if (level_one_3_stars)
{
    # Congrats the user for achieving 3 stars in level one
}
else if (level_two_3_stars)
{
    # Congrats the user for achieving 3 stars in level two
}
else
{
    # Inform the user that no levels have 3 stars achieved
}
```

`if`-`else`-`if` ladder is actually equivalent to this:
```ign
if (first_condition)
{
    # First code (ran if the `first_condition` is `true`)
}
else
{
    if (second_condition)
    {
        # Second code (ran if the `first_condition` is `false` and `second_condition` is `true`)
    }
    else
    {
        if (third_condition)
        {
            # Third code (ran if the `first_condition` is `false` and `second_condition` is `false` and `third_condition` is `true`)
        }
        else
        {
            # Final code (ran if all the above condition is `false`)
        }
    }
}
```

## `while` Statement
The `while` statement is used to repeat the code as long as a given condition is `true`.
```ign
while (condition)
    statement_that_is_executed_as_long_as_condition_remains_true; # It is recommended to alter the condition in the loop so it does not run infinitely
```

For example:
```ign
int chocolates_count = 20;
# ...
while (chocolates_count > 0)
{
    # Eat chocolate
    chocolates_count--; # Alter the condition so it doesn't get hooked into an infinite loop (and don't eat infinite chocolates)
    # Take a break
}
```

## `for` Statement
The `for` statement is used when you want to execute a code certain defined amount of times. It executes the initial statement, checks condition and executes the block accordingly, and executes a statement after each iteration that is meant to alter the condition.
```ign
for (initial_statement; condition; update_statement)
    statement_to_execute_defined_times;
```
It is a shorthand for:
```ign
initial_statement;
while (condition)
{
    statement_to_execute_defined_times;
    update_statement;
}
```

For example:
```ign
for (int weapon_index = 0; weapon_index < weapon_count; weapon_index++)
{
    # Refill ammos of all the weapons
}
```

## `do` Statement
The `do` statement in Ignite is very different than in most programming languages. In Ignite, the `do` statement is executed at least once in any type of loop. All the statements in `do` is executed first and once, and then the loop starts. And in the loop the statements in `do` is executed regularly:
```ign
while (condition)
{
    do
    {
        # This will execute at least once if the condition firstly resulted in `false`
        # And executed repeatedly while the condition is `true`
        statement_to_execute_at_least_once;
    }
    # This is executed repeatedly while the condition is `true`
    statement_to_execute_in_regular_while;
    do
    {
        # This will execute at least once if the condition firstly resulted in `false`
        # And executed repeatedly while the condition is `true`
        statement_to_execute_at_least_once;
    }
}
```
It will initially execute both the statements in `do`.

or for `for` loop:
```ign
# NOTE: the `initial_statement` is executed before the statements in the `do`
for (initial_statement; condition; update_statement)
{
    do
    {
        # This will execute at least once if the condition firstly resulted in `false`
        # And executed repeatedly while the condition is `true`
        statement_to_execute_at_least_once;
    }
    # This is executed repeatedly while the condition is `true`
    statement_to_execute_in_regular_while;
    do
    {
        # This will execute at least once if the condition firstly resulted in `false`
        # And executed repeatedly while the condition is `true`
        statement_to_execute_at_least_once;
    }
}
```

For example:
```ign
int guessed_number;
while (guessed_number != 8)
{
    # Tell that the user guessed wrong number
    do
    {
        # Ask user to guess a number at least once
    }
}
# Tell that the user has finally guessed the correct number
```
Don't worry, the order may feel weird but you can get used to it pretty quickly.

### `do`-`while` Statement
If you however still couldn't grasp this idea and are more familiar with the traditional `do`-`while` statement, Ignite got you! In Ignite you can use the traditional (~~inferior~~... mhm) syntax to do the same:
```ign
do
    statement_to_execute_at_least_once;
while (condition);
```

### `do`-`for` Statement
I cannot not provide flexibility, so here it is:
```ign
do (initial_statement)
    statement_to_execute_at_least_once;
for (condition; update_statement);
```

## `break` Statement
The `break` statement is used to stop a loop from continuing, it is useful when you want to halt the loop without executing the rest of the code in the loop:
```ign
while (condition)
{
    statements;
    if (some_other_condition)
        break; # Stop the loop and don't execute rest of the statements
    rest_of_the_statements_in_loop;
}
```
or for `for` loop:
```ign
for (initial_statement; condition; update_statement)
{
    statements;
    if (some_other_condition)
        break; # Stop the loop and don't execute rest of the statements
    rest_of_the_statements_in_loop;
}
```

For example:
```ign
# Loop for a user in all the lobbies
for (int lobby = 0; lobby < lobbies_count; lobby++)
{
    if (user_found)
        break; # Break if the user is found, and stop marking lobbies as searched
    # Mark lobby as searched
}
# Optionally do something with all the lobbies that isn't marked as searched
```

## `continue` Statement
The `continue` statement is used to restart a loop, meaning it will skip execution of the sentences and start from the beginning of the loop (will execute the `condition` statement, and will execute the `update_statement` in case of `for` loop), and continue executing from the start of the next iteration:
```ign
while (condition)
{
    statements;
    if (some_other_condition)
        continue; # Go back to the beginning of the loop
    rest_of_the_statements_in_loop;
}
```
or for `for` loop:
```ign
for (initial_statement; condition; update_statement)
{
    statements;
    if (some_other_condition)
        continue; # Go back to the beginning of the loop
    rest_of_the_statements_in_loop;
}
```

For example:
```ign
int number;
int sum;
while (sum < 100)
{
    # Ask the user to enter a positive number
    if (number < 0)
    {
        # Say that the number is invalid and will not be added to the sum
        continue;
    }
    # Add the number to the sum if it was not negative number
}
```

## `switch` Statement
The `switch` statement is used in replacement for `if`-`else`-`if` ladder, and it also one that defers from most programming languages:
```ign
switch (expression)
{
    case == value:
        statements_if_expression_matches_value; # expression == value
        break; # Here, `break` is used to break out of the `switch` statement similar to loop
    case >= value:
        statements_if_expression_is_greater_than_or_equal_to_value; # expression >= value
        break;
    case < value:
        statements_if_expression_is_less_than_value; # expression < value
        break;
    default:
        statements_if_every_other_case_is_not_met;
        # No need for a `break` statement for last thing in `switch`
}
```

For example:
```ign
uint number;
# ...
switch (number)
{
    case == 0:
        # Say zero in words
        break;
    case == 1:
        # Say one in words
        break;
    # ...
    case == 9:
        # Say nine in words
        break;
    default:
        # Say too large
}
```

If you have some statement before any `case` in a `switch`, it will never be executed.
```ign
switch (expression)
{
    statement_that_will_never_be_executed;
    case == value:
        statements_if_expression_matches_value;
        break;
    case >= value:
        statements_if_expression_is_greater_than_or_equal_to_value;
        break;
    case < value:
        statements_if_expression_is_less_than_value;
        break;
    default:
        statements_if_every_other_case_is_not_met;
}
```

### Simpler `switch`
If no operator is provided, the `switch` statement looks more traditional:
```ign
switch (expression)
{
    case value_1:
        statements_if_expression_matches_value_1; # expression == value_1
        break;
    case value_2:
        statements_if_expression_matches_value_2; # expression == value_2
        break;
    case value_3:
        statements_if_expression_matches_value_3; # expression == value_3
        break;
    default:
        statements_if_every_other_case_is_not_met;
}
```
And this is a valid syntax!

### `switch` Without `break`
Sometimes, you would want to execute the code of the next case too, in that case, you can omit the `break` of the previous case:
```ign
switch (expression)
{
    case == value1:
        statement_if_expression_is_equal_to_value1; # Won't be executed if expression is equal to value2
    case == value2:
        statement_if_expression_is_equal_to_value1_or_value2;
        break;
    default:
        statement_if_other_cases_are_not_met;
}
```
You can also omit the `break` before the default if you want to execute that as well.

### `switch` With `continue`
`continue` in a `switch` statement means falling to the next `case` of the `switch`.
```ign
switch (expression)
{
    case == value:
        statements_if_expression_matches_value_before_if_statement;
        if (condition)
            continue; # This will fall to case `case >= value`
        statements_if_expression_matches_value_after_if_statement; # This will not be executed if `condition` was `true`
        break;
    case >= value: # Execution continues here if `expression == value` and `condition` is `true`
        statements_if_expression_is_greater_than_or_equal_to_value;
        break;
    case < value:
        statements_if_expression_is_less_than_value;
        break;
    default:
        statements_if_every_other_case_is_not_met;
}
```

## Multiple `break`
Traditionally, you can break out of `for`, `while` and `switch` just fine, but what if those statements were inside another `for`, `while` or `switch`? In that case, one break would break out of most nested `for`, `while` or `switch`, but what if you want to also break out of the parent `for`, `while` or `switch`? In that case, you can write `break break;`:
```ign
while (outer_condition)
{
    for (initial_statement; inner_condition; update_statement)
    {
        if (some_other_condition)
        {
            break break; # Break out of `for` and `while`
        }
    }
}
```

For example:
```ign
for (int i = 0; i < snake_rows; i++)
{
    for (int j = 0; j < snake_columns; j++)
    {
        if (found_ladder_in_grid)
        {
            # Climb ladder and break
            break break;
        }
    }
}
```

You can expand it to break out of more loops and switches by adding more `break` statements.

## Multiple `continue`
When you use `continue`, it will restart the nested-most loop (`for` or `while`). If you want to restart the outer or more outer loop, you can use two or more `continue`:
```ign
while (outer_condition)
{
    for (initial_statement; inner_condition; update_statement)
    {
        if (some_other_condition)
        {
            continue continue; # Restart the outer `while` loop
        }
    }
}
```

## `switch` and Loops with Multiple `break` or `continue`

If you have a nested switch within a loop, and used multiple `break` or `continue`, the `break` will break out of the loop or `continue` will restart the loop:
```ign
for (initial_statement; inner_condition; update_statement)
{
    switch (expression)
    {
        case == value1:
            continue continue; # Restart the `for` loop
        case == value2:
            break break; # Break out of `for` loop
    }
}
```

In case you have a nested loop within a switch, use of multiple `break` or `continue` will break out of the `switch` or fall through the next `case` in `switch`:
```ign
switch (expression)
{
    case == value1:
        while (condition)
        {
            if (sub_condition)
                continue continue; # Fall through the `case == value2` case
            if (other_condition)
                break break; # Break out of `switch`
        }
        break;
    case == value2:
        break;
}
```

## Even more `break` or `continue`
What if you have 3 `for` loops nested and want to break out of them from different places? Writing `break break break;` is tedious. Well... deal with it. Or much better: refactor your inferior code to use functions for specific tasks.

## Labels and `goto`
Labels are one of the programming concept that some users just do not want to use it. They say "It makes hard to track control flow". While it may be true, I believe that labels are necessary part of a programming language and can be considered a good feature if used responsibly. Use `jmp` keyword to declare a label, and `goto` to jump to it:
```ign
jmp label_name:
    # ...
    if (some_condition) goto label_name;
```
or
```ign
    if (some_condition) goto label_name;
    # ...
jmp label_name:
```
Here, `label_name` defines a point at which the execution can jump to using the `goto` statement. The label can be defined anywhere within a function, even after the `goto` statement.

For all you `goto` haters, take this valid use case of `goto`. Consider the below example, the code is messy:
```ign
    bool first_file_opened = open_first_file();
    if (!first_file_opened)
    {
        return 1; # Break out of the main function with error code `1`
    }
    bool second_file_opened = open_second_file(use_stuff_from_first_file);
    if (!second_file_opened)
    {
        # We must close the first file if the second file failed to open
        close_first_file();
        return 1;
    }
    bool third_file_opened = open_third_file(use_stuff_from_second_file);
    if (!third_file_opened)
    {
        # We must close the first and second file if third file failed to open
        close_first_file();
        close_second_file();
        return 1;
    }
    bool fourth_file_opened = open_fourth_file(use_stuff_from_third_file);
    if (!fourth_file_opened)
    {
        # We must close all the previously opened file if fourth file failed to open
        close_first_file();
        close_second_file();
        close_third_file();
        return 1;
    }

    # Do stuff with the files
    # ...

    close_first_file();
    close_second_file();
    close_third_file();
    close_fourth_file();

    return 0;
```
You see the problem? We are duplicating the code for each failure, and it gets progressively worse for more of this. This can be solved using `goto`, so you can do this:
```ign
    int return_value = 0;
    bool first_file_opened = open_first_file();
    if (!first_file_opened)
    {
        return_value = 1;
        goto first_file_failed;
    }
    bool second_file_opened = open_second_file(use_stuff_from_first_file);
    if (!second_file_opened)
    {
        return_value = 1;
        goto second_file_failed;
    }
    bool third_file_opened = open_third_file(use_stuff_from_second_file);
    if (!third_file_opened)
    {
        return_value = 1;
        goto third_file_failed;
    }
    bool fourth_file_opened = open_fourth_file(use_stuff_from_third_file);
    if (!fourth_file_opened)
    { 
        return_value = 1;
        goto fourth_file_failed;
    }

    # Do stuff with the files
    # ...

jmp fourth_file_failed:
    close_fourth_file();

jmp third_file_failed:
    close_third_file();

jmp second_file_failed:
    close_second_file();

jmp first_file_failed:
    close_first_file();

    return return_value;
```
This way, the errored part, let's say third file opening, can just go to the label that states to close the third file. And the execution will fall to the proceeding labels and close the second and first file and return the function.

Just remember that bad use case of `goto` does indeed make the code hard to read and maintain, so use it responsibly. But you can't change my mind on the usefulness of `goto`s.

# Functions

**PENDING**

You have been using them!

## Nested Functions
## Function Types and Instances
## Delegates and Lambdas
## Anonymous Functions
## Functions with Function as Parameters and Function as Return Type

# Constants

Sometimes, you would want to set a variable as constant, so you don't accidentally change its value and cause your factory to be set on fire. To declare a variable as constant, use the `const` keyword, a type specifier, before the type:
```ign
const int MAX_STARS_CAN_RENDER = 512;
```
Conventionally we use UPPER_SNAKE_CASE to name a constant. A constant, when a value is set, cannot be changed (that's why it's called a constant):
```ign
MAX_STARS_CAN_RENDER = 128; // Error: Cannot change the value of constant
```

NOTE: This is not a valid syntax:
```ign
int const CONSTANT_NAME = value;
```
The `const` is applied towards the right, but there is no variable name on the right side of the `const` so this is an invalid syntax.

# Pointers

Ok now don't panic.. d-don't panic. Alright? Calm down. Shhhh...
Ok a pointer is just a variable that stores the memory address of another variable. Ok ok shhh calm down calm down we got this.

Memory of a variable is usually stored in RAM, Cache (CPU automatically takes stuff from RAM and put it in cache) or sometimes even you storage drive (SSD, HDD. If you have set up your swap partition or file. Or whatever is equivalent in Microsoft Windows OS). So it isn't too accurate to say that memory of a variable lies on RAM. For simplicity sake, we do.

So, every variable has a memory address at which the value of a variable resides. This address can be retrieved using the `addr` (Address Of) operator. The returned value of this is a pointer type. But it is just a number. A number that happened to be a memory address of a variable. You can store this number in a pointer type. Use the `ptr` keyword, a type specifier, to create a pointer that points to a variable of a certain type:
```ign
# Demo integer
int my_totally_normal_variable = 4;
ptr int my_pointer_variable = addr my_totally_normal_variable;
```

Ok. Now what can we do with a pointer? We can edit the value of a variable without accessing the variable. To do this, use the `deref` keyword:
```ign
deref my_pointer_variable = 6;

# Prints `6`?!
io.print("Value of my_totally_normal_variable: {my_totally_normal_variable}\n");
```

You may think pointers are pointless (get it?). This example is pointless. But pointers allow for so much flexibility. See [Pointer `struct`](#pointer-struct) and [Manual Memory Management](#manual-memory-management).

# References

References are just aliases to a variable.

# More on Functions

## Pass by Value vs. Pass by Reference or Pointer

# `struct`

**PENDING**

## Member Functions (Methods)
## Member Assignment Operator
## `struct` With Type Specifiers
## Pointers `struct`
## References `struct`
## Constants `struct`

# OOP Stuff

**PENDING**

## Inheritance
## All Public

# Arrays

When you want to store multiple data of similar type and similar intent, doing this is bad:
```ign
int 1_user_id;
int 2_user_id;
int 3_user_id;
int 4_user_id;
int 5_user_id;
# ...
```
Not only it repeats the code, but also hard to maintain. So introducing arrays:
```ign
int[5] user_ids; # Here, you can store 5 different `int`s under a same name (`user_ids`), each can have arbitrary `int` value
```
The size is optional, if not specified, it will use the size as number of parameters given to initialize the array, or `0` if none specified.

To access the individual element of an array, you would use subscript operator `[` and `]`:
```ign
int 4_user_id = user_ids[3]; # Get the fourth element of the array
io.print("Value of the id of the second user: ", user_ids[1]); # Get the second element
```
Note that the index (which comes in between the subscript operator) starts from `0`. Which means the first element is at `0`, the second element is at `1`, and so on, and the last element is at the number of total elements minus one (`n-1`).

You can edit the element as such:
```
user_ids[2] = 10013; # Edit the value of the third element
```

## Traversing an Array
The `for` loop and array love each other. You can ues `for` loop to visit and perform some operation on each element of an array using:
```ign
for (int i = 0; i < array.count(); i++) # the .count method is used to get the number of elements in an array
{
    # Some operation on array
}
```
For example:
```ign
for (int i = 0; i < user_ids.count(); i++)
{
    io.print("ID of user #{i}: {user_ids[i]}\n");
}
```

## Operations on Arrays
Arrays have a few methods (see [Member Functions (Methods)](#member-functions-methods)) that can be used to manipulate array. Only a few. But you can access more by including `ign.array` module (see [More Array Operations](#more-array-operations)). The few is just 3 by default:

### `count()`
This function returns the number of elements that the array has.
For example:
```ign
int[5] array = [2, 4, 5, 6]; # Still has 5 elements
uint64 elements_count = array.count(); # `count()` returns of type `uint64`
io.print("Number of elements: {elements_count}\n"); # Prints `Number of elements: 5`
```

### `insert(index, element)`
This functions inserts a new element at index (it must be from `0` to `n` (inclusive)). If it fails, it throws an exception `"Invalid Index {index}"` (see [Exceptions](#exceptions)).
For example:
```ign
int[4] array = [1, 2, 4, 5];
array.insert(2, 3); # Insert the value `3` at position `2`, this will also increase the size of the array

# Prints `Array elements: 1 2 3 4 5`
io.print("Array elements:");
for (uint64 i = 0; i < array.count(); i++)
{
    io.print(" {array[i]}");
}
io.print("\n");
```

### `remove(index)`
This function removes an element at index (it must be from `0` to `n-1` (inclusive)). If it fails, it throws an `"Invalid Index {index}"` exception.
For example:
```ign
int[6] array = [1, 2, 3, 4, 4, 5];
array.remove(3); # Remove an element at position `3`

# Prints `Array elements: 1 2 3 4 5`
io.print("Array elements:");
for (uint64 i = 0; i < array.count(); i++)
{
    io.print(" {array[i]}");
}
io.print("\n");
```

## Strings
Ever wondered what the data type of `"string"` was? It's an array of `char`, so it's `char[]`. That's it! `io.print` function accepts `char[]` as it's input.
```ign
char[] my_name = "Anstro Pleuton";

io.print("My name is: {my_name}\n");
```

## Operations on Strings
There are some things that you can do to string but not to any other array, they are:

### `length()`
`length()` differs from `count()`, `length()` returns the number of characters excluding the null terminator of the string (just learn C goddamn it).
```ign
char[] my_address = "#000 AAA, #000 BBB, CCC, DDD - #00000000"; # Did you really thought?

uint64 address_length = my_address.length(); # `40`
uint64 address_memory_size = my_address.count(); # `41`! (no not `41` factorial for all you math memers out there)
```

### Conversion to String
You can also convert an integer to a string, by casting it to `char[]`:
```ign
int my_integer = 42;
char[] my_integer_as_string = my_integer; # Implicit cast/conversion

io.print("My integer as string: {my_integer_as_string}\n");
```
This happens only when there is a casting operation present in the data type. `int` and all the other fundamental data types has it.

### String Interpolation
You have been using it since the second example. Remember adding `{` and `}` in the string? Within the `{` and `}`, it's a code expression that returns a value. The returned value is converted to string in the same way as previous, but the string is joined with the rest (see [More Handy Array Operations](#more-handy-string-operations)). If you want to print a literal `{` and `}`, you would type `{{` and `}}` in the code.
For example:
```ign
char[] name = "Ray"; # No not my real name
int age = 21;
uint id = 10025;

char[] formatted_string = "Name: {name}\nAge: {age}, User ID: {id}";

# This prints `Name: Ray, Age: 21, User ID: 10025`
io.print(formatted_string);
```
If you have a regex pattern like `^[a-zA-Z0-9_-]{3,16}$`, you would use `{{` and `}}` instead of `{` and `}` in the string:
```ign
char[] regex_pattern = "^[a-zA-Z0-9_-]{{3,16}}$";
```

## Negative Array Index
You can access the last element of an array using `-1` as it's index values. For example:
```ign
int[] array = [1, 2, 3, 4, 5];

int last_element = array[-1];

# Prints `Last element: 5`
io.print("Last element: {last_element}");
```
This features is ~~stolen~~ taken from the Python programming language. So you can get the last *n*th element in an array:
```ign
int last_second_element = array[-2];
int last_third_element = array[-3];
int first_element = array[-array.count()];
```

Note that using signed integer for subscript will mean you can only access `9223372036854775808` elements from negative index. Does it matter? No.

## More Handy Array Operations
Ever wanted to add a new element at the end of the array without doing this pesky thing all the time?
```ign
array.insert(array.count(), value);
```
Yes? Ever wanted to join two arrays together without having to do this?
```ign
for (uint64 i = 0; i < array_two.count(); i++)
    array_one.insert(array_one.count(), array_two[i]);
```
Yes? We have got ya! All you need to do is include `ign.array.extras` library.
```ign
include ign.array.extras;
```

### Array `+` Operator
To join two arrays, which creates a new array, you can use the `+` operator:
```ign
int array_one = [1, 2, 3, 4, 5];
int array_two = [6, 7, 8, 9, 10];

int joined_array = array_one + array_two;
```
Or you can use the `join` method to join the arrays:
```ign
int joined_array = array_one.join(array_two);
```
Or this if you want to be ever so slightly consistent
```ign
int joined_array = int[].join(array_one, array_two);
```

You can also use a the `+` operator with an array and a variable/constant of the data type of the array as it's operands:
```ign
int my_array = [1, 2, 3, 4];
int new_array = my_array + 5; # Append `5` at the back of the array, so this array has elements `[1, 2, 3, 4, 5]`
```
Or you can use the `append` method:
```ign
int my_array = [1, 2, 3, 4];
int new_array = my_array.append(5);
```

### Array `+=` Operator
Tired of doing this now?
```ign
array_one = array_one + array_two;
```
Just do:
```ign
array_one += array_two;
```
All the same stuff as previous. Or this if you want to use the `join` method using a special operator:
```ign
array_one .= join(array_two);
```
The above `.=` operator is called [Method Assignment Operator](#method-assignment-operator).

### Array slicing
You can slice an array into a smaller array by using `[` followed by the first index (inclusive), then `:`, then the last index (exclusive), and then `]`. This is also ~~stolen~~ taken from the Python programming language:
```ign
int big_array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

int small_array = big_array[3:6];

# Prints `Small array contents: 4 5 6`
io.print("Small array contents:");
for (uint64 i = 0; i < small_array.count(); i++)
    io.print(" {small_array[i]}");
io.print("\n");
```
Or you can use the `split` method:
```ign
int big_array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

int small_array = big_array.split(3, 6);
```
This can also throw an exception `"Invalid Range [{first}, {last}]"` if the `first` in the operator or method is more than `last`, so don't do `[3:1]`. If the `first` and `last` are equal, it will return an empty array.

## Non-homogeneous Arrays
This is going to be a weird one, but you can have an array with elements of different types. Why will it be useful? Developers will figure it out (maybe replacement for variadic functions). This will require you to retrieve type of an element, using Type-Of operator (see [Operations on Types](#operations-on-types)), which is surrounding a type by angle brackets. To declare and use non-homogeneous arrays, use the `auto`:
```ign
auto[] non_homogeneous_array = [1, 2.5, 0.30000000000000004_f64, "Hello, Homogeneous", 'a', 'r', 'r', 'a', 'y', '!', true, "ly", "gorgeous"];

# Print all
for (uint64 i = 0; i < non_homogeneous_array.count(); i++)
{
    auto element = non_homogeneous_array[i];

    # void here basically means all the fundamental type
    if (<element> == void)
    {
        io.print(" {element}");
    }
    else
    {
        io.print(" (unable to print non-fundamental types)");
    }
}
```

# Operations on Types

**PENDING**

# Working with Multiple Files

**PENDING**

# Module-Wise Extending `struct`s

**PENDING**

# Members on Fundamental Types

**PENDING**

# More Array Operations

**PENDING**

# Exceptions

**PENDING**

# Literal Overloading

**PENDING**

# Manual Memory Management
