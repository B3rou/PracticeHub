#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
void insertBeginning(struct node *head)
{
if (head != NULL)
{
printf("First node data: %d\n", head->data);
}
else
{
printf("List is empty!\n");
}
}
void display(struct node *head)
{
struct node *current = head;
while (current != NULL)
{
printf("%d ", current->data);
current = current->next;
}
printf("\n");
}
void search(struct node *head, int input)
{
struct node *current = head;
while (current != NULL)
{
if (current->data == input)
{
printf("Node with value %d found.\n", input);
return;
}
current = current->next;
}
printf("There's no matching!\n");
}

int main()
{
struct node *dugum0 = (struct node*)malloc(sizeof(struct node));
struct node *dugum1 = (struct node*)malloc(sizeof(struct node));
struct node *dugum2 = (struct node*)malloc(sizeof(struct node));
struct node *dugum3 = (struct node*)malloc(sizeof(struct node));
dugum0->data = 10; dugum0->next = dugum1;
dugum1->data = 20; dugum1->next = dugum2;
dugum2->data = 30; dugum2->next = dugum3;
dugum3->data = 40; dugum3->next = NULL;
struct node *head = dugum0;
insertBeginning(head);
printf("Updated list: ");
display(head);
search(head, 30);
search(head, 99);
struct node *current = head;
while (current != NULL)
{
struct node *temp = current;
current = current->next;
free(temp);
}
return 0;
}