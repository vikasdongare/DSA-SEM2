#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
#include<string>
using namespace std;
struct node
{
	int s_prn;
	char s_name[25];
	node *next;
};
struct node *head=NULL;
class club
{
	public:
		int name[25],i=0;
		struct node *curr,*prev=head,*sec,*nexn=NULL,*temp=head,*newn=NULL;
		void get()
		{
			   if(i==0)
	            {
		            cout<<"\n***Details of President***\n";
		            i++;
 	            }
 	            else
	            {
		            cout<<"\n***Details of Members***\n";
			        cin.ignore();
		            i++;
 	            }
		        curr=new node;
			    cout<<"Enter name:";
		        cin.getline(curr->s_name,25);
			    cout<<"Enter PRN:";
			    cin>>curr->s_prn;
			    curr->next=NULL;
			    if(head==NULL)
		    	{
			    	head=curr;
				    prev=curr;
			    }
			    else
			    {
			    	prev->next=curr;
		    	    prev=curr;
				}		    	
		}
		void display()
		{
			int tem;
			sec=head;
			cout<<"\n\t\t\t\t _____________________";
			cout<<"\n\t\t\t\t|*********************|";
			cout<<"\n\t\t\t\t|****PINNACLE CLUB****|";
			cout<<"\n\t\t\t\t|_____________________|";
			cout<<"\n\t\t-------------------------------------------------------";
			cout<<"\n\t\t|    Post"<<setw(13)<<"|  Name"<<setw(22)<<"|  PRN"<<setw(11)<<"|";
			cout<<"\n\t\t-------------------------------------------------------";
			while(sec!=NULL)
			{
				int count=0,fw=23,fw1=14;
				tem=sec->s_prn;
				while(tem)
				{
					tem=(tem/10);
					count++;
				}
				    if(count<fw1)
					{
						fw1=fw1-count;
					}
			   	    if(strlen(sec->s_name)<fw)
			   	    {
					    fw=fw-strlen(sec->s_name);   
					}
			   if(sec==head)
			   {
			   	    cout<<"\n\t\t|  President"<<setw(6)<<"|  "<<sec->s_name<<setw(fw)<<"|  "<<sec->s_prn<<setw(fw1)<<"|";
			   }
			   else if(sec->next==NULL)
			   {
			   	    cout<<"\n\t\t|  Secretary"<<setw(6)<<"|  "<<sec->s_name<<setw(fw)<<"|  "<<sec->s_prn<<setw(fw1)<<"|";
			   }
			   else
			   {
			   	    cout<<"\n\t\t|    Member"<<setw(7)<<"|  "<<sec->s_name<<setw(fw)<<"|  "<<sec->s_prn<<setw(fw1)<<"|";
			   }
			   sec=sec->next;
		    }
		}
		void insert(int pos)
		{
			struct node *temp;
			prev=head;
			int i=0;
			while(prev!=NULL)
		    {
		    	if((pos-1)==i)
		    	{
		    		temp=new node;
		    		cout<<"Enter name:";
		            cin.ignore();
					cin.getline(temp->s_name,25);
			        cout<<"Enter PRN:";
			        cin>>temp->s_prn;
		    		temp->next=prev->next;
		    		prev->next=temp;
				}
				else if(pos==0&&pos==-1)
				{
					cout<<"\nInvalid Position";
				}
				i++;
				prev=prev->next;
			}
			if(prev==NULL&&pos>i)
			{
				cout<<"\n!!! Invalid Position !!!";
			}
		}
		void dlete(int pos)
		{
			if(pos==head->s_prn)
			{
				cout<<"\n\t\t!!! President is deleted !!!";
				head->s_prn=00;
				strcpy(head->s_name," ");
			}
			curr=head;
			prev=head;
			while(curr!=NULL)
			{
				if(pos==curr->s_prn)
				{
					prev->next=curr->next;
					free(curr);
				}
				
				if(curr==head)
				{
					curr=curr->next;
				}
				else
				{
			    	prev=prev->next;
				    curr=curr->next;
			    }
			}
		}
		int count()
		{
			int cnt=0;
			struct node *temp;
			temp=head;
			cout<<"\n\t*Count of Club Members:";
			while(temp!=NULL)
			{
				temp=temp->next;
				cnt++;
			}
			return cnt;
		}
		void rev()
		{
		    label:while(temp!=NULL)
		    {
			if(temp==head)
		      {
		    	temp=temp->next;
			  }
			else
			  {  
				temp=temp->next;
				prev=prev->next;
				goto label;
			  }
		    }
		        if(nexn==NULL)
		        {
		        	nexn=temp;
				}
				else
				{
					newn=temp;
					nexn->next=newn;
					nexn=newn;
				}
		        prev->next=NULL;
		        if(prev==head)
		        {
		        	head=nexn;
				}
				else
		           rev();
		}
};
int main()
{
	char ch;
	int chi,prn,pos,count;
	club c;
	cout<<"\n NOTE:- SECRETARY SHOULD ENTER AT THE LAST OR THE LAST MEMBER BY DEFAULT WILL COSNIDER AS SECRETARY.....\n";
	cout<<"\tAFTER DELETING SECRETARY LAST MEMBER IS SET AS SECRETARY\n";
	label:c.get();
	cout<<"Enter member(y/n):";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	   goto label;
	do
	{
	cout<<"\n----------------------------------------------------------------------------------------\n";
	cout<<"\n1.Insert members\t2.Delete members\n3.Display members\t4.Total count of members\n5.Reverse List\t\t6.Exit\nEnter your choice:";
	cin>>chi;
	cout<<"\n----------------------------------------------------------------------------------------\n";
	switch(chi)
	{
	    case 1:
	    	   cout<<"\nEnter position after whitch the data should enterd:";
	    	   cin>>pos;
	           c.insert(pos);
	           c.display();
	           break;
		case 2:
			   cout<<"\nEnter PRN of member to be deleted:";
			   cin>>prn;
			   c.dlete(prn);
			   c.display();
		       break;
	    case 3:
		       c.display();
			   break;
	    case 4:
	    	   count=c.count();
	    	   cout<<"\n\t\tPresident      = 1";
	    	   cout<<"\n\t\tMembers        = "<<(count-2);
	    	   cout<<"\n\t\tSecretary      = 1";
	    	   cout<<"\n\t\t--------------------";
	    	   cout<<"\n\t\tTotal members= "<<count;
		       break;	
		case 5:
			   c.rev();
			   c.display();
			   break;
		case 6:
			   exit (0);
		default:
			   cout<<"\nEnter valid choice\n";
			   chi=1;
	}
}while(chi<6);
	return 0;
}
