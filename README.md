# Push Swap

The goal of the Push Swap project is to reimplement a sorting algorithm using linked lists in C.

## Project Description

The project involves implementing two programs:

1. **push_swap**: This program sorts a list of integers in ascending order using two stacks and a set of predefined instructions.
   
2. **checker**: This program checks if a list of integers is sorted in ascending order. It takes the same list of integers and instructions as the push_swap program and verifies if the list would be sorted correctly by the push_swap program.

## Game Rules

- The game consists of 2 stacks named 'a' and 'b'.
- At the beginning:
  - Stack 'a' contains a random quantity of negative and/or positive numbers that cannot be duplicated.
  - Stack 'b' is empty.
- The goal of the game is to sort the numbers in stack 'a' in ascending order. To achieve this, you have the following instructions:
  - `sa` (swap a): Swaps the top 2 elements of stack 'a'. Does nothing if there is only one or no element.
  - `sb` (swap b): Swaps the top 2 elements of stack 'b'. Does nothing if there is only one or no element.
  - `ss`: Performs `sa` and `sb` simultaneously.
  - `pa` (push a): Takes the top element of stack 'b' and pushes it onto stack 'a'. Does nothing if 'b' is empty.
  - `pb` (push b): Takes the top element of stack 'a' and pushes it onto stack 'b'. Does nothing if 'a' is empty.
  - `ra` (rotate a): Shifts all elements in stack 'a' up by one position. The first element becomes the last.
  - `rb` (rotate b): Shifts all elements in stack 'b' up by one position. The first element becomes the last.
  - `rr`: Performs `ra` and `rb` simultaneously.
  - `rra` (reverse rotate a): Shifts all elements in stack 'a' down by one position. The last element becomes the first.
  - `rrb` (reverse rotate b): Shifts all elements in stack 'b' down by one position. The last element becomes the first.
  - `rrr`: Performs `rra` and `rrb` simultaneously.

## Compilation Example: push_swap

To compile the `push_swap` program, run:

```bash
make
$ ./push_swap 3 1 2 6 0
rra
pb
ra
pb
rra
sa
pa
pa
```
To compile the `checker` program, run:
expected output:

After entering the instructions, press Ctrl+D
```bash
make
$ ./checker 3 1 2 6 0
rra
pb
ra
pb
rra
sa
pa
pa
OK
```
wrong output:

After entering the instructions, press Ctrl+D
```bash
make
$ ./checker 3 1 2 6 0
sa
ra
ra
pb
KO
```
## Conclusion

For a brief introduction to linked lists, you can check out this [link](https://www.geeksforgeeks.org/what-is-linked-list/).

To learn more about the project and the algorithm used, you can refer to this [link](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).
