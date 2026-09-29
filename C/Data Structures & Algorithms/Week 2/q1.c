#include <stdio.h>
struct node
{
int data;
struct node *next;
};
int main()
{
struct node dugum = {10,NULL};
printf("%d", dugum.data);
}