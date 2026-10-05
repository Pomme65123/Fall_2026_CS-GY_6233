#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned int)time(NULL));    // Seeding for random number generator

    int random_number = rand() % 100;

    printf("Hello world! This is Introduction to Operating Systems, CS6233, Fall2026!\n");
    printf("Shan Qureshi %d\n", random_number);

    return 0;
}