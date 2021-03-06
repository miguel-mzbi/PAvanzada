# Kata 10

Miguel Angel Montoya Z.

## Problem

A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

- For 1-byte character, the first bit is a 0, followed by its unicode code.
- For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.

This is how the UTF-8 encoding would work:

| Char. number range (hexadecimal) | UTF-8 octet sequence (binary) |
|---------------------|--------------------------------------------|
| 0000 0000-0000 007F | 0xxxxxxx                                   |
| 0000 0080-0000 07FF | 110xxxxx 10xxxxxx                          |
| 0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx                 |
| 0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx        |

Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

**Note:**
The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.

**Example 1:**

```text
data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.

Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
```

**Example 2:**

```text
data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.

Return false.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.
```

## Breakdown

This problems requires more bit-wise logic than anything else. Let's remember how a bit mask works:

If you use a mask 11111000, means that when combining it with an and (&), you obtain a number that only keeps the bits of the number at the same position as the 1's. So you can compare the masked number with an specific number. If those are equal, means that the number has the desired specific bits.

Example:

```text
Only accept if 1010xxxx (x means that it's unimportant)

Number: 10111111
Mask:   11110000 (You only care for the 4 most significant bits)
Masked: 10110000
The asked number isn't equal to the acceptance conditions.

Number: 10100011
Mask:   11110000 (You only care for the 4 most significant bits)
Masked: 10100000
The asked number is equal to the acceptance conditions.
```

## Solution

Combining the previous methods, with a simple for, that iterates trough each number, you can check if it's a valid character or it isn't.

It would only take O(n) time, to determine if the array is valid.