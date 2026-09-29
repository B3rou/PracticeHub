#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
int main()
{
int input;
printf("Please enter the number to check if it's matching: ");
scanf("%d", &input);
struct node *dugum0 = (struct node*)malloc(sizeof(struct node));
struct node *dugum1 = (struct node*)malloc(sizeof(struct node));
struct node *dugum2 = (struct node*)malloc(sizeof(struct node));
struct node *dugum3 = (struct node*)malloc(sizeof(struct node));
dugum0->data = 10; dugum0->next = dugum1;
dugum1->data = 20; dugum1->next = dugum2;
dugum2->data = 30; dugum2->next = dugum3;
dugum3->data = 40; dugum3->next = NULL;
struct node *head = dugum0;
struct node *current = head;
struct node *prev = NULL;
int found = 0;
while (current != NULL)
{
if (current->data == input)
{
found = 1;
if (prev == NULL)
{

head = current->next;
}
else
{
prev->next = current->next;
}
free(current);
printf("Node with value %d deleted successfully.\n\n", input);
break;
}
prev = current;
current = current->next;
}
if (!found)
{
printf("\nThere's no matching!\n\n");
}
printf("Updated list: ");
current = head;
while (current != NULL)
{
struct node *temp = current;
printf("%d ", current->data);
current = current->next;
free(temp);
}
}