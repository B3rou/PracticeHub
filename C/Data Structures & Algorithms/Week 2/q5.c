#include <stdio.h>
struct node
{
int data;
struct node *next;
};
int main()
{
struct node dugum3 = {40, NULL};
struct node dugum2 = {30, &dugum3};
struct node dugum1 = {20, &dugum2};
struct node dugum0 = {10, &dugum1};
struct node *current = &dugum0;
int count = 0;
while (current != NULL)
{
count++;
printf("%d. %d\n", count, current->data);
current = current->next;
}
printf("\nTotal Nodes = %d", count);
}