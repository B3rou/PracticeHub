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
struct node *head = &dugum0;
struct node *current = head;
while (current != NULL)
{
printf("%d ", current->data);
current = current->next;
}
struct node newNode = {5, &dugum0};
head = &newNode;
current = head;
printf("\n");
while (current != NULL)
{
printf("%d ", current->data);
current = current->next;
}
}