//Programme to check a linked list is palindrome or not
#include <stdio.h>
#include <stdlib.h>

//structure declaration
struct node
{
    char data;
    struct node *next;
};
//create function to create the linked list
void create(struct node **start1,char num)
{
    struct node *temp,*curr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=(char)num;
    temp->next=NULL;
    if((*start1)==NULL)
    {
        (*start1)=temp;
    }
    else
    {
        curr=(*start1);
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=temp;
    }
}
//function to reverse the linked list
void reverse(struct node **start2)
{
    struct node *sprev=NULL,*prev=NULL,*curr;
    curr=(*start2);
    while(curr!=NULL)
    {
        sprev=prev;
        prev=curr;
        curr=curr->next;
        prev->next=sprev;
    }
    (*start2)=prev;
}
 // function to check the list is palindrome or not
void check(struct node *start1,struct node *start2)
{
    int flag=0;
    while(start1!=NULL&&start2!=NULL)
    {
       if(start1->data!=start2->data)
       {
           flag=1;
           break;
       }
       start1=start1->next;
       start2=start2->next;
    }
    if(flag==0)
        printf("\nPalindrome\n\n\n\n\n");
    else
        printf("\nNon-palindromic\n\n\n\n\n");
}
//display function to print the list
void display(struct node *start1)
{

    struct node *curr=start1;
    printf("\nThe list is:-\n");
    while(curr!=NULL)
    {
        printf("%c\t",(char)curr->data);
        curr=curr->next;
    }
    printf("\n");
}
//copy function to copy one linked list to another
void copy(struct node *start1)
{
    struct node *curr1=start1,*start2=NULL,*last;
    while(curr1!=NULL)
    {
        if(start2==NULL)
        {
            start2=(struct node*)malloc(sizeof(struct node));
            start2->data=(char)curr1->data;
            start2->next=NULL;
            last=start2;
        }
        else
        {
            last->next=(struct node*)malloc(sizeof(struct node));
            last=last->next;
            last->data=(char)curr1->data;
            last->next=NULL;
        }
        curr1=curr1->next;
    }

    reverse(&start2);      //calling reverse function
    check(start1,start2);  //calling check function
}
int main()
{
    struct node *start1=NULL;
    int n,i;
    char str[50];
    printf("\nEnter the string:- ");   //takes string from user
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++)
    {
       create(&start1,str[i]);   // calls create function
    }

    display(start1);  //calling display function
    copy(start1);    //calling copy function
}
