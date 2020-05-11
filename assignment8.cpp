#include<iostream>
#include<math.h>
using namespace std;
struct node {
	int bit;
	node *next,*back;
};
struct node *head=NULL,*head1=NULL,*head2=NULL;
struct node *tail=NULL,*tail1=NULL,*tail2=NULL;
node *get() {
	int n,i,x;
	node *prev,*head=NULL;
	cout<<"\nEnter no of bits: ";
	cin>>n;
	for(i=0; i<n; i++) {
		node  *newn=new node();
label:
		cout<<"Enter data: ";
		cin>>x;
		if(x!=0 && x!=1) {
			cout<<"!!! Enter correct bit !!!\n";
			goto label;
		}
		newn->bit=x;
		newn->next=NULL;
		newn->back=NULL;
		if(head==NULL) {
			head=newn;
			prev=newn;
		} else {
			newn->back=prev;
			prev->next=newn;
			prev=newn;
		}
	}
	return(head);
}
node display(node *temp) {
	while(temp!=NULL) {
		cout<<temp->bit<<"\t";
		tail=temp;
		temp=temp->next;
	}
}
node *comp1(node *curr) {
	while(curr!=NULL) {
		if(curr->bit==1) {
			curr->bit=0;
		} else {
			curr->bit=1;
		}
		curr=curr->next;
	}
	return(curr);
}
node *comp2(node *curr) {
	while(curr!=NULL) {
		tail=curr;
		curr=curr->next;
	}
	while(tail!=NULL) {
		if(tail->bit==1) {
			tail=tail->back;
			while(tail!=NULL) {
				if(tail->bit==1) {
					tail->bit=0;
				} else {
					tail->bit=1;
				}
				tail=tail->back;
			}
			break;
		}
		tail=tail->back;
	}
}
int bindec(node *curr)
{
	int sum=0,j=0;
	while(curr!=NULL) 
	{
		tail=curr;
		curr=curr->next;
    }
	while(tail!=NULL)
	{
		if(tail->bit==1)
		sum=sum+pow(2,j);
	
		j++;
		tail=tail->back;
	}
	return(sum);
}
int decbin(int n)
{
	int i=0,m,bit[100];
	for(i=0; n>0; i++)    
	 {    
		bit[i]=n%2;    
		n= n/2;  
	 }
	for(i=i-1 ;i>=0 ;i--)    
	{    
		cout<<bit[i]<<"\t";    
	}    
}
int main() {
	int ch,no1,no2,res;
	do {
		cout<<"\n1.1's compliment\n2.2's compliment\n3.Addition\n4.Exit\nEnter your choice:";
		cin>>ch;
		switch(ch) {
			case 1:
                            head=get();
				cout<<"You entered:\t";
				display(head);
				comp1(head);
				cout<<"\n1's Compliment:\t";
				display(head);
				break;
			case 2:
                            head=get();
				cout<<"You entered:\t";
				display(head);
				comp2(head);
				cout<<"\n2's Compliment:\t";
				display(head);
				break;
			case 3:
				head1=get();
				cout<<"You entered:\t";
				display(head1);
				head2=get();
				cout<<"You entered:\t";
				display(head2);
				no1=bindec(head1);
				no2=bindec(head2);
				res=no1+no2;
				cout<<"\nAddition:\t";
				decbin(res);
		}
       cout<<"\n---------------------------------------------\n";
	} while(ch<3);
}
