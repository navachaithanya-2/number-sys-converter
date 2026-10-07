# Number System Converter

A simple C program that converts numbers between different number systems using a command-line menu.

## Features

- Decimal to Binary
- Decimal to Octal
- Decimal to Hexadecimal
- Binary to Decimal
- Binary to Octal
- Binary to Hexadecimal
- Octal to Decimal
- Octal to Binary
- Octal to Hexadecimal
- Hexadecimal to Decimal
- Hexadecimal to Binary
- Hexadecimal to Octal

## Supported Number Systems

- Decimal (Base 10)
- Binary (Base 2)
- Octal (Base 8)
- Hexadecimal (Base 16)

## How to Run

### Linux / macOS

```bash
gcc numbersystemconverter.c -o numbersystemconverter
./numbersystemconverter
```

### Windows (MinGW / GCC)

```bash
gcc numbersystemconverter.c -o numbersystemconverter.exe
numbersystemconverter.exe
```

## Usage

1. Choose the source number system.
2. Choose the target number system.
3. Enter the number to convert.
4. The program displays the converted result.

## Example

```text
===========================
  Number System Converter  
===========================
Enter the Source Number System
1. Decimal(Base 10)
2. Binary(Base 2)
3. Octa(Base 8)
4. Hexa(Base 16)
Enter choice(1-4):  1

Enter the Target Number System
1. Decimal(Base 10)
2. Binary(Base 2)
3. Octa(Base 8)
4. Hexa(Base 16)
Enter choice(1-4):  2

Enter the Number in the choosen System:  25
The converted number is 11001
```

## Notes

- Valid input must match the selected base.
- Hexadecimal input accepts digits `0-9` and letters `A-F` (both uppercase and lowercase).
- The program is designed for beginner-level learning and demonstrates manual conversion logic in C.

## Author

This project is a basic number system converter written in C for educational/practical use.
