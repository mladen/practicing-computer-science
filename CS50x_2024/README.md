
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
\text{Bubble sort} &\rightarrow (n-1)\times(n-1)=n^2+2n+1
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
