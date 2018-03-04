# Kata 5

Miguel Angel Montoya Z.

## Problem

You want to build a word cloud, an infographic where the size of a word corresponds to how often it appears in the body of text.

To do this, you'll need data. Write code that takes a long string and builds its word cloud data in a hash table ↴ , where the keys are words and the values are the number of times the words occurred.

Think about capitalized words. For example, look at these sentences:

``` C
"After beating the eggs, Dana read the next step:"
"Add milk and eggs, then add flour and sugar."
```

What do we want to do with "After", "Dana", and "add"? In this example, your final hash table should include one "Add" or "add" with a value of 2.

Make reasonable (not necessarily perfect) decisions about cases like "After" and "Dana".

## Breakdown

There isn't much to implement. Just an update function for the class practice hash table, a function that reads text and a functions that iterates trough the table to show the results ant the end.

- Every word will be converted to all lowercase.
- Every special character and punctuation mark will be ignored.

## Solution

The solution is simple. Each insertion in the table takes O(l) where l is the number of items in the bucket. Its the same for each update.

A function that prints every element in the hash table would take O(n)