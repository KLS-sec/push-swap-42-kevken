*This project has been created as part of the 42 curriculum by kbrun, kle-scor.*

## Description
The Push swap project is a very simple and highly straightforward algorithm project :  
Data must be sorted.

At our disposal, we have a set of **integer values, 2 stacks, and a set of operations to manipulate both stacks**.

The goal ? Write a C program called push_swap which calculates and displays on the standard output the smallest program, made of Push swap language operations, that sorts the integers received as arguments.  
Another goal of this project was to make us discover algorithmic complexity in a very concrete way.

We work with **2 stacks a and b**.  
The first one contains a random amount of negative and/or positive numbers without any duplicate.  
The b stack is empty.

We need to sort everything in the end inside **stack a** thanks to some of the following operations :  
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

To enforce a rigorous understanding of *algorithmic complexity (time and space)*, we implemented *four distinct sorting strategies* and integrated them to the program. The program must be able to select a strategy at runtime based on the input configuration.  

All strategies are implemented in C and must generate sequences of Push_swap operations to perform the sorting. This means :  
- Our C algorithms analyze the input and generate the appropriate sequence of operations: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr.  
- The output strategy is the sequence of these operations that sorts the stack.  
- When we talk about the complexity of a class, it must reflect the cost measured in number of Push_swap operations generated, not the theoretical complexity of a
classical array-based algorithm.

We also measured **disorder**, which is a number between 0 and 1 that tells how far the initial **stack a** is from being sorted.  
If the numbers are already in the right order, *the disorder is 0*.  
If they are in the worst possible order, *the disorder is 1*.  
Anything in between means the stack is partly sorted, but still messy.  
To calculate it, we looked at all the possible pairs of numbers in the stack. Each time a bigger number appears before a smaller one, that pair counts as a mistake. The more mistakes there is, the closer the disorder is to 1.

## Instructions

***TO COMPLETE / MODIFY***  
To launch the program, you must use the **make** command first to archive all files together and create the push_swap.a file. From here, you can compile using **(g)cc push_swap.a [name of function]**

## Resources
***kbrun*** watched some of the videos of the Youtube channel [M.A. BENALLAL](https://www.youtube.com/@m.a.benallal) to learn the basics of the algorithm we used and adapted.  
I also looked at a video about [Double linked lists](https://www.youtube.com/watch?v=589GpRJ6VFo) to learn how to handle them correctly and handle them on our program.

## Algorithms justification and explanation

***TO DO / MODIFY***  
#### Basically what is bubble sort, chunk sort, radix, what are their functions and why did we choose them over the others ?

### Space Complexity
**The space complexity** represent all the memory used by the algorithm itself. We always use the **Big O** notations to calculate the space and time complexity, which depends on the average or worst case scenario.  
*O* stands for *Order of approximation* and refers to formal or informal expressions for how accurate an approximation is in terms of the number of parameters used to construct the approximation.  
For example, if we ever only manipulates one variable or file, the space complexity will be *O(1)*, because the program only use this one variable and doesn't create a new one or stock anything else more than this.

The **bubble sort algorithm**, the equivalent of the simple algorithm, only needs the allocated memory space to be of use, so its space complexity will always be *O(1)* even in the worst case.

The **chunk based algorithm** we made, equivalent to the medium algorithm uses the same amount of memory and doesn't need to allocate or generate more memory for its own purpose.  
So its complexity should be at O(1) in the best / worst situation.

***TO DO / MODIFY***  
Finally, the **radix algorithm**, equivalent to the complex algorithm, needs...  
Which means its complexity should be at O(...) in average / worst.

The **adaptive version** is just the selection between all of the above algorithm, so its theoretical space complexity is at best O(1) and at worst O(...)

### Time Complexity
**The time complexity** implies how much time the algorithm and program take to sort the given inputs. It also use the Big O notations, which means In our push_swap program, we can switch the amount of time in seconds or milliseconds with the number of Push_Swap operations it takes.

The **bubble sort algorithm** takes at best O(n) movements for small inputs or a list almost sorted, and in the worst case, like in a case where the disorder is close to 100% and / or a long-length list, will take up to O(n^2) movements.

The **chunk based algorithm** we developed, depends of how many chunks it will creates, which is based on the square root of the n elements given, and at worst, the n times squared elements, so O(√n) at best but O(n√n) at worst.

Finally, the **radix algorithm**, works with a high number of inputs set (around **X** numbers to sort to begin to see its true potential)

## Contributions

**kbrun** contributed by creating and completing his part of this README.md, did the Makefile, creating the double linked stack and applying all operations to them (ra, rb, rr...), implementing the simple *bubble sort algorithm*, making the basics for the bench and integrating it to the program and to all functions, modified ft_printf to ft_print_error to display on the standard error the result of the bench and finally fused / linked the functions altogether.

**kle-scor** contributed by comprehending and implementing some of the algorithms...
