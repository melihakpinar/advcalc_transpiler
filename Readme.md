# AdvCalc to LLVM IR Transpiler

A transpiler that translates input in the form of assignment statements and expressions of the AdvCalc++ language into LLVM IR code that can compute and output those statements.

It is a project for the course "CMPE230 Systems Programming" at the Bogazici University.

## Build

Run make command to build the project and generate the executable file.

```bash
make
```

## Run

Run the executable file with the input file as the first argument.

```bash
./advcalc2ir <file_name>.adv
```

This will generate the LLVM IR code in the file named "<file_name>.ll". \
This file can be compiled with the LLVM compiler to generate the executable file.

```bash
llc file.ll -o file.s
clang file.s -o executable
./executable
```

## .adv File Format

The input file must be in the AdvCalc++ language.

```
<statement>
<statement>
...
```


## AdvCalc++ Language

The AdvCalc++ language is a simple language that can be used to evaluate expressions and assign values to variables. \
If a line is an assignment statement, the value of the expression on the right side of the assignment operator is assigned to the variable on the left side. \
If a line is an expression, the value of the expression is computed and printed to the standard output.\
The language supports the following operations:

- Arithmetic operations: +, -, *, /
- Modulo operation: %
- Bitwise logical operations: &, |
- Bitwise shift and rotate functions: ls(), rs(), lr(), rr()
- Bitwise complement and xor function: not(), xor()
- Assignment operator: =

## Example Input

```
x = 1
y = x + 3
z = x * y * y*y
z
qqq = xor(131, 198)
qqq
xor(((x)), x)
xor(((x)), x) | z + y
rs(xor(((x)), x) | z + y, 1)
ls(rs(xor(((x)), x) | z + y, 1), (((1))))
lr(ls(rs(xor(((x)), x) | z + y, 1), (((1)))), 1)
rr(lr(ls(rs(xor(((x)), x) | z + y, 1), (((1)))), 1), 1)
qqq * not(not(10))
rr(lr(ls(rs(xor(((x)), x) | z + y, 1), (((1)))), 1), 1) - qqq * not(not(10))
0 & rr(lr(ls(rs(xor(((x)), x) | z + y, 1), (((1)))), 1), 1) - qqq * not(not(10))
```
This program gives the following output:

```
64
69
0
68
34
68
136
68
690
-622
0
```