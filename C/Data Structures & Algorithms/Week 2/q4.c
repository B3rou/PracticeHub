#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
int main()
{
struct node *dugum0 = (struct node*)malloc(sizeof(struct node));
struct node *dugum1 = (struct node*)malloc(sizeof(struct node));
struct node *dugum2 = (struct node*)malloc(sizeof(struct node));
dugum0->data = 10;
dugum0->next = dugum1;
dugum1->data = 20;
dugum1->next = dugum2;
dugum2->data = 30;
dugum2->next = NULL;
printf("%d %d %d", dugum0->data,dugum1->data,dugum2->data);
free(dugum0); free(dugum1); free(dugum2);
}