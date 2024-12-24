
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
    NOTE: We'll actually use the VSCode editor on cs50.dev, so we don't have to do the linking etc. locally

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

#### About **string** type we've used so far

In CS50x, so far, we've used the **string** type. That's because we had help from cs50.h where they've put
```c
typedef char *string;
```

That line "teaches" Clang to think of the word **string** as being synonymous with **char \***.

```c
#include <stdio.h>

// typedef char *string;
typedef char * string; // Creating a custom data type

int main(void)
{
    // char *sentence = "Hello World and some other words!"; // This is the same as the line below
    string sentence = "Hello World and some other words!";

    printf("Pointer to sentence is %p\n", sentence);
    printf("%s\n", sentence);
}
```

#### Pointer arithmetic

We generally don't care about the specific value of the pointer but we care that they do exist. And if they do exist, we can do some arithmetic on them - like, "add 1" to go to the next byte etc.
```c
#include <stdio.h>

int main(void)
{
    char * string = "Hi!";

    // EXPLANATIONS:
    // string - pointer to the first character of the string literal "Hi!". It holds the memory address where the string begins.
    // * string (or *string) - dereferences the pointer string to get the value it points to, which is the first character of the string ('H' in "Hi!").
    // (void *)string - This is the string pointer (which points to the first character of the string) explicitly cast to a void *.
        // The cast ensures compatibility with the %p format specifier in printf, which expects a void *. It doesn't change the address stored in string, only how the pointer is interpreted for printing or generic use.
        // For example:
        // If string = 0x1000, then (void *)string is also 0x1000, but now treated as a generic pointer type.

    printf("\n\n1. Address of %c is %p, which is the same as %p\n", * string, (void *)string, &string[0]);

    printf("2. Address of %c is %p\n", string[1],  &string[1]);
    // How does string[1] give us the value? Isn't "string" supposed to be a pointer?
    // EXPLANATION: string[1] is equivalent to *(string + 1)!!! The pointer arithmetic (string + 1) advances
    // the pointer by one position, pointing to the second character. The dereference
    // operator * retrieves the value at that memory address, which is the character 'i'.
    // EXAMPLE: &string[0]
    // string[0] gives us the value of the first character (which has index = 0).
    // Then the & operator gives us the value of that character.
}
```
NOTE: Once again, we even have an ability to ask "where those things are" by using an Ampersand (&) operator.