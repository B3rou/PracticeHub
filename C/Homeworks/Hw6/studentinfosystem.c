#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct {
    char name[30];
    int id;
    float midterm;
    float final;
} student;

int main(void)
{

    FILE* save = fopen("ogrenciler.txt", "a+");
    if (save == NULL)
    {
        printf("Something went wrong, please try again.");
        return 1;
    }
    student students[MAX];
    fseek(save, 0, SEEK_SET);

    int i = 0;
    char choice = '\0';

    while (i < MAX && fscanf(save, "%29[^,],%d,%f,%f", students[i].name, &students[i].id, &students[i].midterm, &students[i].final) == 4)
    {
        i++;
    }
    
    fclose(save);
    printf("Would you like to enter students through the program? \"y\" for yes. ");
    scanf(" %c", &choice);
    getchar();
    if (choice == 'y') {
        for(i = 0;i < MAX; i++)
        {
            printf("Please enter %d. Student's name: ", i);
            fgets(students[i].name, 30, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';
            printf("Please enter %d. Student's id: ", i);
            scanf("%d", &students[i].id);
            printf("Please enter %d. Student's midterm score: ", i);
            scanf("%f", &students[i].midterm);
            printf("Please enter %d. Student's final score: ", i);
            scanf("%f", &students[i].final);
            getchar();
        }
    }

    printf("Here are your students:\n");
    printf("--------------------------------\n");
    for(i = 0; i < MAX; i++)
    {
        printf("%s\n", students[i].name);
        printf("\tId: %d\n", students[i].id);
        printf("\tMidterm: %f\n", students[i].midterm);
        printf("\tFinal: %f\n", students[i].final);
        printf("\tAvarage: %f\n", ((students[i].midterm * 0.4) + (students[i].final * 0.6)));
    }
    FILE *overwrite = fopen("ogrenciler.txt", "w");
    for (int i = 0; i < MAX; i++) {
        fprintf(overwrite, "%s,%d,%.2f,%.2f\n", students[i].name, students[i].id, students[i].midterm, students[i].final);
    }
    fclose(overwrite);
    getchar();
    getchar();
    return 0;
}