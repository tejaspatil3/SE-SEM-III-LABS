
#include<iostream>
#include<string.h>
#define MAX 100
using namespace std;

 struct stack
 {
     char data[MAX];
     int top;
 };

 void init(stack *stck)
 {
     int i;
     for(i=0;i<MAX;i++)
     {
         stck->data[i]='\0';
         stck->top=-1;
     }
 }

 void print(stack stck)
 {
     int i;
     cout<<"\n Stack elements are";
     for(i=0;i<MAX;i++)
     {
         cout<<"stck.data[i]";
         cout<<"\t top="<<stck.top;
     }
 }

 int isempty(stack stck)
 {
     return stck.top==-1?1:0;
 }

 int isfull(stack stck)
 {
     return stck.top==MAX-1?1:0;

 }

 void push(stack *stck,char data[MAX])
 {
     int i;
     for(i=0;data[i]!='\0';i++)
     {
     stck->top+=1;
     stck->data[stck->top]=data[i];
     }
 }

 void pop(stack *stck)
 {
     char rev[MAX];
     int i=0;
     while(!isempty(*stck))
     {
     rev[i]=stck->data[stck->top];
     stck->top-=1;
     i++;
     }
     rev[i]='\0';
     cout<<"\n Original string is="<<stck->data;
     cout<<"\n reverse string is=";
     cout<<rev;
     
 }
void Palin(stack *stck)
{
     char rev[MAX];
     int i=0;
     while(!isempty(*stck))
     {
     rev[i]=stck->data[stck->top];
     stck->top-=1;
     i++;
     }
     rev[i]='\0';
     cout<<"\n Original string is="<<stck->data;
     cout<<"\n reverse string is=";
     cout<<rev;
     if(strcmp(rev,stck->data))
     {
     cout<<"\n string is not palindrome";
     }
     else
     {
     cout<<"\n String is palindrome";
     }

}
 int main()
 {
     stack stck;
     char data[MAX];
     init(&stck);
     int ch,i,j=0;
     cout<<"Enter String:";
     cin>>data;
     while(ch!=3)
     {
     cout<<"\n1.Print reverse string\n";
     cout<<"2.palindrome or not";
     cout<<"\n3.Exit";

     cout<<"\n Enter your choice:";
     cin>>ch;

     switch(ch)
     {
     case 1:
         if(isfull(stck))
         {
         cout<<"\n Stack is full";
         }
         else
         {
         push(&stck,data);
         }
         if(isempty(stck))
         {
         cout<<"\n Stack is empty";
         }
         else
         {
         pop(&stck);
         }
         break;

     case 2:
         init(&stck);
         if(isfull(stck))
         {
         cout<<"\n Stack is full";
         }
         else
         {
            push(&stck,data);
         }
         Palin(&stck);
         break;
         }
     }
     return (0);
 }
