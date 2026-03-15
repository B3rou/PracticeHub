#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int howManyLowerFive(int* array, int len);

int main(void) {
    srand((unsigned int)time(NULL));
    int* randomNumbers = calloc(10, sizeof(int));
    if (randomNumbers == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        randomNumbers[i] = rand() % 10;
    }
    printf("There are %d numbers lower than 5 in the array.\n", howManyLowerFive(randomNumbers, 10));
    free(randomNumbers);
}

int howManyLowerFive(int* array, int len) {
    int count = 0;
    int i;
    for (i = 0; i < len; i++) {
        if (array[i] < 5) {
            count++;
        }
    }
    return count;
}