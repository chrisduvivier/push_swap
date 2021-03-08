# push_swap
- [ ] add libft and its Makefile
- [ ] write data structure for stacks
- [ ] write stacks operation functions
    - [ ] push
    - [ ] pop
- [ ] write individual operations defined in 
- [ ] 

# Stack implementations
We can implement the stack using arrays or linked-list. Using linked-list allows to dynamically change the size, whereas with an array resizing will be necessary. In this project, the size of the list of integers is given, so we can opt for the array implementation without bothering with the resizing. However, the following instructions will take linear O(n) time with the array implementation: `ra : rotate a - shift up all elements of stack a by 1.`, `rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.` (idem for `rra`, `rrb`, `rr`, `rrr`) If one considers using these operations for the sorting process, a linked-list implementation would be better off, since it can be done in constant time O(1). 

In my implementation of the sorting algorithm, these operations were not needed, so I opted for the simpler array implementation.


