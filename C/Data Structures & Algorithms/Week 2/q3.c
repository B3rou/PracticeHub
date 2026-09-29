#include <stdio.h>
struct node
{
int data;
struct node *next;
};
int main()
{
struct node dugum2 = {30, NULL};
struct node dugum1 = {20, &dugum2};
struct node dugum0 = {10, &dugum1};
struct node *current = &dugum0;
while (current != NULL)
{
printf("%d ", current->data);
current = current->next;
}
}