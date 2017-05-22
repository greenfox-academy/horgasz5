#include <stdio.h>
#include <string.h>
#include <stdint.h>

// TODO: Include needed header files
#include "another_file.c"
#include "another_file.h"

int main() {
    // Set the default state of the variable
    an_example_number = 10;

    // Create variables
    char str[] = "Multiple file inclusion example project string";
    int number = 10;

    // Manipulate numbers
    StringManipulator(str);
    IntegerManipulator(&number);

    // See the results
    printf("Result of StringManipulator(): %s\n", str);
    printf("Result of IntegerManipulator(): %d\n", number);

    return 0;
}