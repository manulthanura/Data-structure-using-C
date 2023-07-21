# The Word Search Game

A word search engine is a website or application that allows users to find words in a grid of letters. The words can be hidden in any direction, including horizontally, vertically, diagonally, and backwards. Word search engines typically have a large database of words, and they allow users to search for words by letter, length, or theme.

## How I implement this?

I've crafted two fascinating algorithms, each employing distinct data structures, to power an engaging Word Search game. My noble pursuit revolves around unearthing the ultimate algorithm that can swiftly locate a word amidst a vast database of words. To achieve this goal, I've harnessed the prowess of both the Linear Search and Hash algorithms. While it's possible that superior algorithms exist, let's delve into the remarkable speed of my implementations and explore the wonders they unfold.

For this experiment, I used a database that includes more than 500,000 words. The database of words is available in the `database.txt` file.

## Speed of the Linear Search Algorithm

The Linear Search algorithm is a brute-force algorithm that sequentially searches for a target value in a list. It's a simple algorithm that's easy to implement and understand. However, it's not the most efficient algorithm for searching large databases. The Linear Search algorithm has a time complexity of O(n), which means that the time it takes to search for a word in a database is proportional to the size of the database.

Example code: [Linear Search Algorithm](./WSG%20-%20linear%20search.c)

## Speed of the Hash Algorithm

The Hash algorithm is a more efficient algorithm for searching large databases. It uses a hash function to map a word to a unique number. The hash function is a mathematical function that takes a word as input and returns a number as output. 

Example code: [Hash Algorithm](./WSG%20-%20Hash.c)