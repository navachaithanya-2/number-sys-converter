# Number System Converter

A simple C program that converts numbers between different number systems.

## Project Overview

This project provides a console-based number converter that supports:

- Decimal (Base 10)
- Binary (Base 2)
- Octal (Base 8)
- Hexadecimal (Base 16)

It allows conversion from one base to another and is useful for learning number system conversions in C.

## Features

- Convert decimal to binary, octal, and hexadecimal
- Convert binary to decimal, octal, and hexadecimal
- Convert octal to decimal, binary, and hexadecimal
- Convert hexadecimal to decimal, binary, and octal
- Interactive menu-driven interface

## File

- `numbersystemconverter.c` - Main program source code

## How to Run

### Using GCC (Linux/macOS)

```bash
gcc numbersystemconverter.c -o numberconverter
./numberconverter
```

### Using GCC on Windows (MinGW / Git Bash)

```bash
gcc numbersystemconverter.c -o numberconverter.exe
./numberconverter.exe
```

## Example

```text
===========================
  Number System Converter  
===========================
Enter the Source Number System
1. Decimal(Base 10)
2. Binary(Base 2)
3. Octal(Base 8)
4. Hexadecimal(Base 16)
Enter choice(1-4): 1
Enter the Target Number System
1. Decimal(Base 10)
2. Binary(Base 2)
3. Octal(Base 8)
4. Hexadecimal(Base 16)
Enter choice(1-4): 2
Enter Decimal number: 10
Result: 1010
```

## Notes

This program uses basic arithmetic and string conversion methods to convert between numeral systems.

## Author

Built as a C programming practice project.
