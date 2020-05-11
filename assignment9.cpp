#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
class stack
 {
	int top;
    public:
       char a[25];
       stack()
       {
          top=-1;
       }
	bool push(char x);
	char pop();
	bool isempty();
 };
bool stack::push(char x)
 {
	if(top>=24)
	{
		cout<<"Stack overflow";
		return false;
	}
	else
	{
		a[++top]=x;
		return true;
	}
 }
char stack::pop()
 {
   if(top<0)
   {
         cout<<"Stack Underflow";
   }
   else
   {
         char x=a[top--];
 	  return x;
   }
 }
bool stack::isempty()
 {
	return (top<0);
 }
int main()
 {
   stack s;
   int i;
   char str[25],rev[25];
   cout<<"\nEnter string:";
   cin>>str;
   for(i=0;str[i]!='\0';i++)
    {
       s.push(str[i]);
    }
  for(i=0;s.isempty()==false;i++)
    {
       rev[i]=s.pop();
    }
	int x=strcmp(str,rev);
   cout<<str<<endl;
   cout<<rev<<endl;
   cout<<x<<endl;
   if(x==0)
    {
        cout<<"String is palindrome";
    }
   else
    {
      cout<<"String is not palindrome";
    }
 }
