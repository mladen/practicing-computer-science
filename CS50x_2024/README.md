
# CS50x 2024

Check out the course [here](https://cs50.harvard.edu/x/2024/).

Documentation for the course, and what to install can be found [here](https://cs50.readthedocs.io/).

## Lecture 1 - C
- Data types:
  - `bool`: boolean (true or false), 1 byte
  - `int`: integer (whole number), 4 bytes
  - `long`: long integer (whole number), 8 bytes
  - `float`: floating-point number (real number), 4 bytes
  - `double`: double-precision floating-point number (real number), 8 bytes
  - `char`: character (single character), 1 byte
  - `string`: string of characters (a sequence of characters), n bytes
  - ...
- We can *compile the program* using the following command:
    ```bash
    make hello
    ```

    > NOTE: What is "make"? Make is a program that automates the build process.

- We can *run the program* using the following command:
    ```bash
    ./hello
    ```

- When we include a library like cs50.h, we need to compile the program using the following command:
    ```bash
    make hello
    # OR
    clang -o hello hello.c -lcs50
    ```

## Lecture 2 - Arrays
- Debugging:
  ```bash
  debug50 ./hello
  ```
  NOTE: `debug50` is a tool that allows us to debug our code.

## Lecture 3 - Algorithms
### Time and space complexity
#### BigO notation (worst-case scenario)
  > DEFINITION: Describes the _worst-case_ scenario for an algorithm. It gives the upper bound on time or space complexity. \
  > Example: Sorting with Bubble Sort is $O(n^2)$, meaning it can take at most $n^2$  steps. \
  > In short: $O$ - Ceiling (worst-case)
  - $O(n^2)$ - Selection sort, Bubble sort \
    Why? It's because we're taking the biggest term:
```math
\begin{align*}
\text{Selection sort} &\rightarrow (n-1)\times(n-2)\times(n-3)+...+1=\dfrac{n^2}{2}-\dfrac{n}{2}\\
&(\text{The biggest term, for Selection sort, is} \space n^2)\\
\text{Bubble sort} &\rightarrow (n-1)\times(n-1)=n^2+2n+1 \\
&(\text{The biggest term, for Bubble sort, is also} \space n^2)\\
\end{align*}
```
#### BigOmega (best-case scenario)
  > DEFINITION: Describes the best-case scenario. It gives the lower bound on time or space complexity. \
  > Example: Bubble sort is $\Omega(n)$, as it might only take $n$ steps for an already sorted list. \
  > In short: $\Omega$ - Floor (best-case).
  - $\Omega(n^2)$ - Selection sort
  - $\Omega(n)$ - Bubble sort (the _best-case_ would be to go through the whole array only once - that would happen if the array was already sorted)
#### BigTheta (average-case scenario)
  > DEFINITION: Describes the exact complexity when the upper and lower bounds are the same. \
  > Example: Merge sort is $\Theta(n \space log \space n)$, as it always takes $n \space log \space n$ steps. \
  > In short: $\Theta$ - exact match.c
  - $\Theta(n^2)$ - Selection sort
  - For bubble sort we cannot say anything here, because the best-case and worst-case scenarios are different (upper and lower bound are different).

## Lecture 4 - Memory
### Hexadecimal numbers/notation
...

### Memory
**Ampersand (&)** - we can pronounce it the ***"address of"*** operator.
With it, we're asking the computer "at what address is this variable". \
**Asterisk (*)** - we can pronounce it ***"dereference operator"***.
It allows us to take an address and go to it. It takes us to a location in memory, so we can see what's actually there.

A **pointer** is just an ***address of some variable***, that we can store in another variable (called itself a pointer). \
A pointer does not contain a regular value, but the address of some value. \
*p (without the type, like "int", in front) means ***"go to that address - but don't print it"***

My visual explanation

| Memory address |   Variable    |     Value      | (comments)                                       |
| -------------- | :-----------: | :------------: | ------------------------------------------------ |
| 0x7ffe462988c8 |       n       |  5 (0b11...)   |                                                  |
| ...            |               |   (...0010)    |                                                  |
| ...            |               |      ...       |                                                  |
| ...            |               |      ...       |                                                  |
| (some address) | *pointer_to_n | 0x7ffe462988c8 | (pointer to memory location where 50 is located) |

```c
#include <stdio.h>

int main(void) {
    int n = 50; // int is typically 4 Bytes, on most systems

    // If we want *pointer_to_n to be a pointer (a variable that stores an address), we do this (int *)
    int *pointer_to_n = &n;

    printf("The computer has put the value n = %i somewhere in memory.\n\n", n);
    printf("Address of value %i is pointer_to_n = 0x%p, or &n = 0x%p\n\n", n, pointer_to_n, &n);
    printf("Dereferencing the pointer %p, using *p (without putting 'int' type in front), we get the value %i.\n\n", &n, *pointer_to_n);

    return 0;
}
```

#### How much memory space do pointers take?
**Pointers take up more space (than variables)** - by convention. They typically take 8 Bytes nowadays, rather than just 4.
Why is that?
Well, if we've got 8 Bytes we can count even higher. We can have even more addresses. We can have even more memory.

> Detailed explanation
> 1. Pointer Size and Address Space: \
> Pointers store memory addresses. The size of a pointer depends on the system architecture:
> - On *32-bit systems*, pointers typically use *4 Bytes (32 bits)* (to represent addresses), allowing access to $2^{32}$ memory addresses (*4 GB*).
> - On *64-bit systems*, pointers use *8 Bytes (64 bits)* (to represent addresses), allowing access to $2^{64}$ memory addresses (*16 exabytes*).
>
> 2. Why 8 Bytes Today? \
> Most modern systems use a 64-bit architecture for better performance and support for large amounts of memory. This requires pointers to be 8 bytes to reference the larger address space.
>
> 3. Impact on Memory Usage: \
> Pointers do take up more space compared to regular variables like int or float, which are usually 4 bytes on many platforms.

### Strings

The pointer actually points to the first character of a string.
Each string, in memory, ends with the null terminate character ('\0') which takes 8 bits (all zeros).

```c
#include <stdio.h>

int main(void)
{
    char *sentence = "Hello World and some other words!"; // *sentence is a pointer (a variable that stores an address)
                                                          // to a string called "Hello World and some other words!".
                                                          // By convention, that pointer contains the address of the first character of the string.
                                                          // By convention, the string ends with a null character '\0', which is not printed (it is implied).

    printf("Pointer to sentence is %p\n", sentence);
    printf("%s\n", sentence); // %s is a format specifier for strings

    // Printing out the sentence/string
    int counter = 0;
    while (sentence[counter] != '\0')
    {
        printf("%c", sentence[counter]);

        counter++;
    }

    printf("\n");
}
```