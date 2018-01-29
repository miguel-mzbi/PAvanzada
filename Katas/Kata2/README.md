# Kata 1

Miguel Angel Montoya Z.

## Problem

A password is considered strong if below conditions are all met:

    It has at least 6 characters and at most 20 characters.
    It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
    It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).

Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.

int strongPasswordChecker(char* s) {}

## Breakdown

- If password has less than 6 digits return a string filling the necessary space with valid characters.
- Create flags and after character reading assign solutions.
  - If lowercase missing, add it at the end.
  - If uppercase missing, add it at the end.
  - If number missing, att it at the end.
  - For the previous flags:
    - If adding will imply 3 repeating chars, add the next ASCII char.
    - If adding will imply more than 20 chars, replace a char of a 3 repeating sequence with missing chars (If available) or replace first possible legal char.
  - If 3 repeating chars, replace last char of sequence with the +1 ASCII char value.
  - If password is too long, delete repeating chars until a max of 20 chars is achieved.
  - If password is too short, even after all fixed flags, add random chars (Would add max 3 chars if password to test is empty).

## Solution

Iterate trough char array. Mark pertinent flags, and position of each 3rd char in 3 repeating chars. O(n)
Deal with each flag. O(1)
Fix short password O(1)
Go to each 3R position and try to replace the char with a the next char in ASCII. If this next char is the same as the character to the right, try the next one. O(n)
Fix long password (If previous step didn't fix it already). O(n)
