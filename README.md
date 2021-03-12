# push_swap
- [x] add libft and its Makefile
- [x] write data structure for stacks
- [x] write stacks operation functions
    - [x] push
    - [x] pop
- [ ] function to check if stack is sorted or not
- [ ] Make it compatible for integer (my assumption): handle potential error for overflow
- [ ] write individual operations defined in subjects
- [ ] Checker: read 1 instruction per line and return [OK, KO, ERROR] at the end.
    - 
- [ ] Push-Swap: read stack and return smallest list of instruction to sort.
    - 

# Stack implementations
We can implement the stack using arrays or linked-list. Using linked-list allows to dynamically change the size, whereas with an array resizing will be necessary. In this project, the size of the list of integers is given, so we can opt for the array implementation without bothering with the resizing. However, the following instructions will take linear O(n) time with the array implementation: `ra : rotate a - shift up all elements of stack a by 1.`, `rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.` (idem for `rra`, `rrb`, `rr`, `rrr`) If one considers using these operations for the sorting process, a linked-list implementation would be better off, since it can be done in constant time O(1). 

# Using Generics (void pointer)
https://stackoverflow.com/questions/7828393/c-programming-casting-a-void-pointer-to-an-int

