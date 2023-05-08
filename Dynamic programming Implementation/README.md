# Dynamic programming Implementation

Dynamic programming is a powerful algorithmic technique used to solve problems by breaking them down into smaller subproblems and reusing solutions to those subproblems. This technique is especially useful for problems with overlapping subproblems, where the same subproblem is solved multiple times. Here is an implementation of dynamic programming using C, with examples.

## Example 1: Fibonacci Series
The Fibonacci sequence is a classic example of dynamic programming. The sequence starts with 0 and 1, and each subsequent number is the sum of the two preceding ones. Here is an implementation of the Fibonacci sequence using dynamic programming:



In this implementation, we create an array called memo that stores the results of previous calculations. We start by initializing memo[0] and memo[1] to the first two numbers in the sequence. Then we loop through the remaining numbers and calculate each one by adding the two preceding numbers together. Finally, we return the nth number in the sequence.