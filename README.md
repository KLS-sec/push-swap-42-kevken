*This project has been created as part of the 42 curriculum by kbrun, kle-scor*

## Description
The Push swap project is a very simple and highly straightforward algorithm project :  
Data must be sorted.

At our disposal, we have a set of integer values, 2 stacks, and a set of operations to manipulate both stacks.

The goal ? Write a C program called push_swap which calculates and displays on the standard output the smallest program, made of Push swap language operations, that sorts the integers received as arguments.  
Another goal of this project was to make us discover algorithmic complexity in a very concrete way.

We work with 2 **stacks a and b**.  
The first one contains a random amount of negative and/or positive numbers without any duplicate.  
The b stack is empty.

We need to sort everything in **stack a** thanks to some of th following operations :  
- *sa (swap a)* : Swap the first two elements at the top of stack a.  
Do nothing if there is only one or no elements
- *sb (swap b)* : Swap the first two elements at the top of stack b.  
Do nothing if there is only one or no elements.
- *ss (swap both)* : sa + sb simuteanously
- *pa (push to a)* : Take the first element at the top of b and put it at the top of a.  
Do nothing if b is empty
- *pb (push to b)* : Take the first element at the top of a and put it at the top of b.  
Do nothing if a is empty.
- *ra (rotate a)* : Shift up all elements of stack a by one.  
The first element becomes the last one.
- *rb (rotate b)* : Shift up all elements of stack b by one.  
The first element becomes the last one.
- *rr (rotate both)* : ra + rb simuteanously
- *rra (reverse rotate a)* : Shift down all elements of stack a by one.  
The last element becomes the first one.
- *rrb (reverse rotate b)* : Shift down all elements of stack b by one.  
The last element becomes the first one.
- *rrr (reverse rotate both)* : rra + rrb simuteanously

To enforce a rigorous understanding of algorithmic complexity (time and space), we implemented four distinct sorting strategies and integrated them to the program. The program must be able to select a strategy at runtime based on the input configuration.  

All strategies are implemented in C and must generate sequences of Push_swap operations to perform the sorting. This means :  
- Our C algorithms analyze the input and generate the appropriate sequence of operations: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr.  
- The output strategy is the sequence of these operations that sorts the stack.  
- When we talk about the complexity of a class, it must reflect the cost measured in number of Push_swap operations generated, not the theoretical complexity of a
classical array-based algorithm.

We also measured disorder, which is a number between 0 and 1 that tells how far the initial *stack a* is from being sorted.  
If the numbers are already in the right order, the disorder is 0.  
If they are in the worst possible order, the disorder is 1.  
Anything in between means the stack is partly sorted, but still messy.  
To calculate it, we looked at all the possible pairs of numbers in the stack. Each time a bigger number appears before a smaller one, that pair counts as a mistake. The more mistakes there is, the closer the disorder is to 1.

## Instructions



## Resources
*kbrun* a utilisé des ressources vidéos de la chaine [M.A. BENALLAL](https://www.youtube.com/@m.a.benallal) pour commencer à apprendre les bases des algorithmes utilisés
I also watched a video about [Double linked lists](https://www.youtube.com/watch?v=589GpRJ6VFo) to learn how to handle them correctly.

## Algorithms justification



### Contributions

**kbrun** contributed by creating and completing this README.md, the Makefile, creating the double linked stack and applying all operations to them...

**kle-scor** contributed by comprehending and implementing some of the algorithms...
