# 24-points

This console game is a [_24 puzzle_](https://en.wikipedia.org/wiki/24_(puzzle)) implementation.

> The 24 puzzle is an arithmetical puzzle in which the objective is to find a way to manipulate four integers so that the end result is 24. For example, for the numbers 4, 7, 8, 8, a possible solution is `(7-(8/8))*4=24`.  

## Specifications

1. The program randomly generates 4 integers. There is a guaranteed solution for these 4 integers.
2. Press Enter to show all possible solutions.
3. Repeat step 1.

## Solution format

The number before each operator indicates the order of operation.  
i.e.  

``` shell output
7 1- 8 0/ 8 2* 4
```

means `8/8` are done first, then `7-(8/8)`, and finally `(7-(8/8))*4`.
