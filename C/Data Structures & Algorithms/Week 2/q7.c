#include <stdio.h>
struct node
{
int data;
struct node *next;
};
int main()
{
int input;
printf("Please enter the number to check if it's matching.\n");
scanf("%d",&input);
struct node dugum3 = {40, NULL};
struct node dugum2 = {30, &dugum3};
struct node dugum1 = {20, &dugum2};
struct node dugum0 = {10, &dugum1};
struct node *current = &dugum0;
while (current != NULL)
{
if (current->data == input)
{
printf("\nThere is a \"%d\" matching in the linked list!", current->data);
return 0;
}
current = current->next;
}
printf("\nThere's no matching!");
}