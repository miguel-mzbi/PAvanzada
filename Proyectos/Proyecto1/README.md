# Proyecto 1

Miguel Angel Montoya Z.

## Problem 1089. Verification with a Vocabulary

Time limit: 2.0 second. Memory limit: 64 MB

Your teacher of English has recently told you that she dreams about the automated system of correction and count of mistakes that her pupils do very frequently. The 8th of March is soon and you've decided that if you write such program and you'll present your teacher with it, then she will be glad and may be will be more favorable to you at the exam. The task is to replace words that differ from the ones in the vocabulary not more than by a letter and to count an amount of the made mistakes. Your teacher must have forgotten that her pupils sometimes forget to write letters and even sometimes they write extra letters - excellent! You are not to think about it!

### Input

In the first line and then up to the line containing the only symbol '#' go vocabulary words, each word in its line. In the lines that go after the one containing '#' goes a text that you are to check-up. There are not more than 100 words in the vocabulary. A length of a word in the vocabulary doesn't exceed 8 symbols. A length of the text being checked-up doesn't exceed 1000 words. All the words are written in the lower case. A word might contain Latin letters from 'a' to 'z'. The vocabulary is compiled so that for each word not more than one variant of correction is possible. There's exactly one end of line character at the end of the text.

### Output

You are to output the corrected text in the same format as the initial one (the same punctuation marks, line breaks and words that are absent in the vocabulary) and in the line next to the text there is to be a number of corrections.

Sample input:

```text
country
occupies
surface
covers
russia
largest
europe
part
about
world
#
the rushia is the larjest cauntry in the vorld.
it ockupies abaut one-seventh of the earth's surfase.
it kovers the eastern park of yurope and the northern park of asia.
```

Sample output

```text
the russia is the largest country in the world.
it occupies about one-seventh of the earth's surface.
it covers the eastern part of europe and the northern part of asia.
11
```

## Breakdown

- The bad written words need to have the same length as the correct ones
- Iterate trough words, following previous rules.
- Only need to check for chars between 'a'-'z'. Rest of chars are left as original.

## Solution

- Iterate words, and search for replacements of same length.
- If possible replacement has more than 1 difference, return false for that word.