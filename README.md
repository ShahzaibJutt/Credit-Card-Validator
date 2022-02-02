# Credit Card Validator

[![Open in Visual Studio Code](https://open.vscode.dev/badges/open-in-vscode.svg)](https://open.vscode.dev/ShahzaibJutt/Credit-Card-Validator)

This program validates your credit card number using luhn algorithm. It can also display the company of the credit card you are using.

## What is Luhn Algorithm?
Most cards use an algorithm invented by **Hans Peter Luhn** of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:
- Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
- Add the sum to the sum of the digits that weren’t multiplied by 2.
- If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

## Compilation

``` bash
gcc validator.cpp -o validator
./validator
```

## Usage

```bash
Input: 4003600000000014
Output: Visa
Input: 374245455400126
Output: Amex
Input: 60115564485789458
Output: INVALID! Please enter the valid number.
```
You can specify the number of cards you want to validate by changing the **MAX** *macro* in the code.

*by default MAX = 1*

## Todo's
- Add file handling support
