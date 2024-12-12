
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

