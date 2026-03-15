#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int scores;
    printf("Enter how many scores you'll enter: ");
    scanf("%d", &scores);
    int* scoreArray = malloc(scores * sizeof(int));
    if (scoreArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < scores; i++) {
        printf("Enter score %d: ", i + 1);
        scanf("%d", &scoreArray[i]);
    }
    int sum = 0;
    for (int i = 0; i < scores; i++) {
        sum += scoreArray[i];
    }
    float average = (float)sum / scores;
    printf("The average score is: %.2f\n", average);
    free(scoreArray);
}