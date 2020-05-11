
#include<iostream>

#define MAX 40
#include<cstring>
using namespace std;

template <class T>
class stack
{
  T stk[MAX];
  int top;
public:
  stack()
  {
    top=-1;
  }
  void push(T ele);
  T pop();
  T get_top();
  int isempty();
  int isfull();
};
template <class T>
void stack<T>::push(T ele)
{
  if(top==MAX)
  {
    cout<<"\nStack is full";
  }
  else
  {
    top++;
    stk[top]=ele;
  }
}//end of push
template <class T>
T stack<T>::pop()
{
  T p;
  if(top==-1)
  {
    cout<<"\nStack is empty";
  }
  else
  {
    p=stk[top];   // return (stk[top--]);
    top--;
    return p;
  }
}//end of pop
template <class T>
T stack<T>::get_top()
{
  if(top==-1)
  {
    cout<<"\nempty";
  }
  else
  {
    return stk[top];
  }
}
template <class T>
int stack<T>::isempty()
{
  if(top==-1)
    return 1;
  else
    return 0;
}//end of isempty
template <class T>
int stack<T>::isfull()
{
  if(top==MAX-1)
    return 1;
  else
    return 0;
}

int icp(char ch)
{
	switch(ch)
    	{
		case '+':
		case '-':
		            return(1);
            case '*':
		case '/':
		            return(2);

		case '^':
		            return(3);

		case '(':
		case ')':
		            return(4);
    	}
}
int isp(char ch)
{
	switch(ch)
    	{
		case '+':
		case '-':
		            return(1);

		case '*':
		case '/':
		            return(2);

		case '^':
		            return(3);

		case '(':
		case ')':
		            return(0);
	}
}
void inToPost(char b[MAX])
{
	stack <char> s;
	char infix[MAX],ch,x;
	int k=0;
	cout<<"\nEnter infix expression: ";
	cin>>infix;
	int i=0;
    	while(infix[i]!='\0')
    	{
		ch=infix[i];
		i++;
		if(ch>='a' && ch<='z')
		{
		    //cout<<ch;
		    b[k]=ch;
		    k++;
		}
		else if(ch==')')
		{
		    while(s.get_top()!='(')
		    {
		        x=s.pop();
		        //cout<<x;
		        b[k++]=x;
		    }
		    s.pop();
        	}
       	 	else
        	{
		    if (!s.isempty())
			    while(isp(s.get_top())>=icp(ch))
			    {
				x=s.pop();
				//cout<<x;
				b[k++]=x;
			    }
            	s.push(ch);
        	}
    	}
	while(!s.isempty())
    	{
		x=s.pop();
		//cout<<x;
		b[k++]=x;
    	}
    	b[k]='\0';
}
void inToPre(char a[MAX])
{
	stack <char> s;
	int k=0;
	char infix[MAX], ch, x,b[MAX];
	cout<<"\nEnter infix expression:";
	cin>>infix;
	int i=strlen(infix)-1;
    	while(i>=0)
    	{
		ch=infix[i];
		i--;
		if(ch>='a' && ch<='z')
		{
			b[k++]=ch;
		}
		else if(ch=='(')
		{
			while(s.get_top()!=')')
		   	{
				x=s.pop();
				b[k++]=x;
		    	}
		    	s.pop();
		}
		else
		{
		  	if (!s.isempty())
		    	while(isp(s.get_top())>icp(ch))
		    	{
				x=s.pop();
				b[k++]=x;
		    	}
		  	s.push(ch);
		}
    	}
    	while(!s.isempty())
   	{
		x=s.pop();
		b[k++]=x;
    	}
    	int j=0;
    	for(i=k-1;i>=0;i--)
	{
		a[j]=b[i];
		j++;
	}
	a[j]='\0';
}
string postToIn()
{
    stack <string> s;
    string postfix, str, str1, str2;
    cout<<"\nEnter postfix string: ";
    cin>>postfix;
    for (int i=0; postfix[i]!='\0'; i++)
    {
        //if (isOperand(postfix[i]))
        if(postfix[i]>='a' && postfix[i]<='z')
        {
           string str(1, postfix[i]);
           s.push(str);
        }
        else
        {
            str1 = s.pop();
            str2 = s.pop();
            s.push("(" + str2 + postfix[i] +  str1 + ")");
        }
    }
    return s.get_top();
}

string preToIn()
{
	stack <string> s;
	string prefix, str, str1, str2;
	int i, j;
	cout<<"\nEnter prefix string: ";
	cin>>prefix;
    	for(j=0;prefix[j]!='\0';j++);
    	for(i=j-1;i>=0;i--)
   	 {
        	if(prefix[i]>='a' && prefix[i]<='z')
        	{
		    string str(1, prefix[i]);
		    s.push(str);
        	}
        	else
        	{
		    str1=s.pop();
		    str2=s.pop();
		    s.push("(" + str1 + prefix[i] + str2 + ")");
        	}
    	}
    	return s.get_top();
}

string postToPre()
{
	stack <string> s;
	string postfix, str, str1, str2;
	cout<<"\nEnter postfix string: ";
	cin>>postfix;
	int i;
    	for(i=0;postfix[i]!='\0';i++)
    	{
        	if(postfix[i]>='a' && postfix[i]<='z')
        	{
		    string str(1, postfix[i]);
		    s.push(str);
        	}
        	else
        	{
		    str2=s.pop();
		    str1=s.pop();
		    s.push(postfix[i] + str1 + str2);
        	}
    	}
    	return s.get_top();
}

string preToPost()
{
	stack <string> s;
	string prefix, str, str1, str2;
	cout<<"\nEnter prefix string: ";
	cin>>prefix;
	int i,j;
    	for(j=0;prefix[j]!='\0';j++);
   	for(i=j-1;i>=0;i--)
    	{
        	if(prefix[i]>='a' && prefix[i]<='z')
        	{
		    string str(1,prefix[i]);
		    s.push(str);
        	}
       		else
        	{
		    str1=s.pop();
		    str2=s.pop();
		    s.push(str1 + str2 + prefix[i]);
        	}
    	}
    	return s.get_top();
}
void evaluate()
{
	stack<int> s;
	
	char postfix[50],ch;
	int op1,op2,value,ans;
	int i=0;
	cout<<"\nEnter the postfix expression";
	cin>>postfix;
	while(postfix[i]!='\0')
	{
		ch=postfix[i];
		if(ch>='a' && ch<='z')
		{
			cout<<"\nEnter value";
			cin>>value;
			s.push(value);
		}
		else
		{
			op2=s.pop();
			op1=s.pop();
			switch(ch)
			{
				case '+':
					ans=op1+op2;
				break;
				case'-' :
					ans=op1-op2;
				break;
				case '*':
					ans=op1*op2;
				break;
				case '/':
					ans=op1/op2;
				break;
				case '^':
					ans=op1^op2;
				break;
				
			}
			s.push(ans);
		}
		i++;
	}
	cout<<"Answer is:"<<s.pop();
}
int main()
{
	char b[MAX],ans, a[MAX];
	int ch;
    	do
    	{
		cout<<"\nMENU";
		cout<<"\n1.Infix to Postfix \n2.Infix to Prefix \n3.Postfix to Infix \n4.Prefix to Infix";
		cout<<" \n5.Postfix to Prefix \n6.Prefix to Postfix\n7.Postfix evaluation";
		cout<<"\nEnter your choice: ";
		cin>>ch;
        	switch(ch)
        	{
		    case 1:
		            inToPost(b);
		            cout<<"\nConverted(in to post): "<<b;
		            break;

		    case 2:
		            inToPre(a);
		            cout<<"\nConverted (in to pre): "<<a;
		            break;

		    case 3:
		            cout <<"\nConverted:(post to in) "<< postToIn();
		            break;

		    case 4:
		            cout<<"\nConverted: "<<preToIn();
		            break;

		    case 5:
		            cout<<"\nConverted: "<<postToPre();
		            break;

		    case 6:
		            cout<<"\nConverted: "<<preToPost();
		            break;
	            case 7:
	            	   evaluate();
	            	   break;
	            
	            	
		        
        	}
		
    }while(ch<8);
    return 0;
}
