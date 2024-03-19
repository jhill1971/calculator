# RPN Calculator

## Overview

This is a simple Reverse Polish Notation (RPN) calculator implemented in C. It evaluates mathematical expressions provided in RPN format via command-line arguments.

## Usage

1. Compile the code using a C compiler such as GCC:

    ```
    gcc -o calc calculator.c
    ```

2. Run the compiled executable `calc` followed by the RPN expression. For example:

    ```
    ./calc 2 3 +
    ```

Supported operators are `+` (addition), `-` (subtraction), `x` (multiplication), and `/` (division). The multiplication operator is represented by `x` due to limitations with special characters in command-line arguments.

## Functionality

- The calculator evaluates the RPN expression provided as command-line arguments.
- It supports basic arithmetic operations: addition, subtraction, multiplication, and division.
- The result of the expression is printed to the console.

## Implementation Details

- The calculator uses a stack data structure to process the operands and intermediate results during evaluation.
- Error handling is implemented to detect stack overflow, stack underflow, division by zero, and invalid operators.
- Command-line arguments are processed to identify operands and operators, which are then evaluated accordingly.

## File Structure

- `calculator.c`: Contains the implementation of the RPN calculator.
- `README.md`: This file, providing instructions and information about the calculator.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

