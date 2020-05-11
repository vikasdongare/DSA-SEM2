#include<iostream>
#include<iomanip>
#define MAX 10
using namespace std;

class order
{
	public:
		void menu()
		{
			cout<<"\n"<<setfill('-')<<setw(50)<<"\n";
    		cout<<"\n\t\t\t!!! MENU !!!";
			cout<<"\n\t----------------------------------------";
			cout<<"\n\t|Sr. No. | Types of pizza |\tPrice |";
			cout<<"\n\t----------------------------------------";
    		cout<<"\n\t|    1   |  Cheese pizza  |\t 120  |";
			cout<<"\n\t|    2   | Mashroom pizza |\t 100  |";
			cout<<"\n\t|    3   |  Paneer pizza  |\t 130  |";
			cout<<"\n\t|    4   |   Onion pizza  |\t 110  |";
			cout<<"\n\t|    5   |Capcisicum pizza|\t 110  |";
			cout<<"\n\t----------------------------------------";
    		cout<<"\n";
    		cout<<"\t!!! Once Order place you cannot cancel !!!\n";
    		cout<<"\n"<<setfill('-')<<setw(50)<<"\n";
		}	
		void getname(int ch)
		{
			switch(ch)
			{
				case 1:
					cout<<"Cheese pizza";
					break;
				case 2:
					cout<<"Mashroom pizza";
					break;
				case 3:
					cout<<"Paneer pizza";
					break;
				case 4:
					cout<<"Onion pizza";
					break;
				case 5:
					cout<<"Capcisicum pizza";
					break;
			}
		}
};
class pizza:public order
{
    int rear,front;
    int Q[MAX];
    int element;

public:
    pizza()
    {
        front=-1;
        rear=-1;
    }
    void is_full();
    void display();
    void delet();
    void insert(int);
};

void pizza::insert(int item)
{
    if((front==-1 && rear==MAX-1)||(front ==rear+1))
    {
        cout<<"\n!!! Overflow !!!";
    }
    else
	{
        if(front==-1)
        {
            front =0;
            rear=0;
        }
        else if(rear==MAX-1)
        {
            rear=0;
        }
        else
        {
            rear=rear+1;
        }
        Q[rear]=item;
    }
}

void pizza::is_full()
{
    if((front==-1 && rear==MAX-1)||(front ==rear+1))
    {
       cout<<"\n!!! Order are full !!!";
    }
    else
    {
        cout<<"\n!!! Order are not full !!!";
    }
}

void pizza::delet()
{
    if(front==-1)
    {
        cout<<"\n!!! No orders in the parlor !!!";
    }
    cout<<"\nOrder delevired is:";
	getname(Q[front]);
    {
        if(front==rear)
        {
            front=0;
            rear=0;
        }
        else if(front==MAX-1)
        {
            front=0;
        }
        else
        {
            front=front+1;
        }
    }

}

void pizza::display()
{
    int front_pos=front;
    int rear_pos=rear;
    if(front==-1)
    {
        cout<<"\n!!! No order in parlor !!!";
    }
    cout<<"\nOrders are:";
    if(front_pos<=rear_pos)
    {
        while(front_pos<=rear_pos)
        {
			getname(front_pos);
			cout<<"\n";
            front_pos++;
        }
    }
    else
    {
        while(front_pos<=MAX-1)
        {
            getname(front_pos);
			cout<<"\n";
            front_pos++;
        }
    }
    front_pos=0;
    /*while(front_pos<=rear_pos)
    {
        cout<<Q[front_pos]<<"\n";
        front_pos++;
    }*/

}

int main()
{
    pizza p;
	order d;
    int item,n,i,o,m,t;
   d.menu();
        cout<<"\nEnter no. of orders:";
        cin>>n;
        for(i=0;i<n;i++)
        {
            label:cout<<"Enter the choice:";
            cin>>item;
			if(item>0 && item<6)
            	p.insert(item);
			else
			{
				cout<<"\n\t!!! Item doesn't exist !!!\n";
				goto label;
			}
        }
    p.display();
    p.is_full();
    cout<<"\nHow many orders are deliverd:";
    cin>>o;
    for(i=0;i<o;i++)
    {
        p.delet();
    }
    cout<<"\nPending:";
    p.display();
    return 0;
}
