#include<iostream>
#include<string.h>
using namespace std;
class string
{
  public:
  int i=0,count=0;
  char str[20];
  void get()
  {
    cout<<"Enter string:";
    cin>>str;
  }
  void dis()
  {
    cout<<"String is :"<<str;
  }
  int length()
  {
    for(i=0;str[i]!='\0';i++)
    {
       count++;
    }
     
   return count;
  }
 
}s,s1,s2;
int main()
{
  int ch,i,j=0,l1,l2,st,len,count=0;
  cout<<"1.length of string\t2.Copy string\n3.Concaneate string\t4.Reverse string\n5.Sub String\t\t6.Compare\n7.Exit\nEnter choice:";
  cin>>ch;
  
  switch(ch)
  {
    case 1:
     s.get();
     l1=s.length();
     cout<<"Length of string is :"<<l1;  
     break;
    case 2:
     s1.get();
     s2.get();
     for(i=0;i<20;i++)
     {
      s1.str[i]=s2.str[i];
     }
     cout<<"Strng 2 is copied in string 1:\n";
     s1.dis();
     break;
    case 3:
     s1.get();
     l1=s1.length(); 
     s2.get();
     l2=s2.length();
     for(i=l1;i<20;i++)
     {
         s1.str[i]=s2.str[j];
       j++;
     }
    s1.dis();
     break;
    case 4:
     s1.get();
     l1=s1.length();
     for(i=l1;i>=0;i--)
      cout<<s1.str[i];  
     break;
    case 5:
     s1.get();
     l1=s1.length();
     cout<<"Length of string is:"<<l1;
     cout<<"\nEnter starting position and length of substring";
     cin>>st>>len;
     if(l1>(len-st))
     for(i=st;i<=len;i++)
      cout<<s1.str[i];
     else
      cout<<"Total length of string less than you entered";
     break;
    case 6:
     s1.get();
     s2.get();
     for(i=0;i<20;i++)
     {
       if(s1.str[i]!=s2.str[i])
        count++;
     }
     if(count>0)
       cout<<"The strings are not equal";
     else
      cout<<"Strings are equal";
     break;
    case 7:
      exit (0);
  } 
}
