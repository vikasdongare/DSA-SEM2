#include<iostream>
#include<stdlib.h>
using namespace std;

struct queue
{
	char jname[25];
	queue *next;
};
class queueq
{
	struct queue *head=NULL,*tail=NULL;
	queue *curr,*prev,*temp;
	public:
		bool isemptyq()
		{
			if(head==NULL)
				return true;
			else
				return false;
		}
		void add()
		{
				curr=new queue;
				cout<<"\n\tEnter job name:";
					cin.ignore();
				cin.getline(curr->jname,25);
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
				tail=curr;
		}
		int del()
		{
			if(isemptyq())
				cout<<"\n\t!!! Queue Underflow !!!";
			else
			{	
				temp=head;
				head=head->next;
				delete temp;
			}
		}
		int getfront()
		{
			if(isemptyq())
				cout<<"\n\t!!! Queue Underflow !!!";
			else
			{
				cout<<"\n\tJob name:"<<head->jname;
			}
		}
		int getrear()
		{
			if(isemptyq())
				cout<<"\n\t!!! Queue Underflow !!!";
			else
			{
				cout<<"\n\tJob name:"<<tail->jname;
			}
		}
		void dis()
		{
			if(isemptyq())
				cout<<"\n\t!!! Queue Underflow !!!";
			else
			{
				temp=head;
				cout<<"\n\t\t!!! Displaying job names !!!\n";
				while(temp!=NULL)
				{
					cout<<temp->jname<<"\n";
					temp=temp->next;
				}
			}
		}
};
int main()
{
	int ch;
	queueq q;
	do
	{
		
		cout<<"\n----------------------------------------------------------------------------\n";
		cout<<"\n\t\t!!! Menu !!!\n\t1.Add Job\n\t2.Delete job\n\t3.Display job\n\t4.Check 1st job\n\t5.Check last job\n\t6.Exit\nEnter choice:";
		cin>>ch;
		cout<<"\n----------------------------------------------------------------------------";
		switch(ch)
		{
			case 1:
				q.add();
				system("clear");
				cout<<"\t!!! Job added succesfully !!!";
				break;
			case 2:
				q.del();
				system("clear");
				cout<<"\n\t!!! Job deleted succesfully !!!";s
				break;
			case 3:
				system("clear");
				q.dis();
				break;
			case 4:
				system("clear");	
				q.getfront();
				break;
			case 5:
				system("clear");
				q.getrear();
				break;
			case 6:
				exit(0);
		}
		//system("pause");
	}while(ch<6);
}
