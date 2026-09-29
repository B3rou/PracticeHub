#include <stdio.h>
struct node
{
int data;
struct node *next;
};
int main()
{
struct node dugum1 = {20, NULL};
struct node dugum0 = {10, &dugum1};
printf("%d", dugum0.next->data);
}