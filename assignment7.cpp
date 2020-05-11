#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

struct node
{
    int start;
    int end;
    char name[30];
    node* next;
    node* back;
};
class list
{
    node* head;
public:
    list()
    {
        head=NULL;
    } 
    void makeapp();
    void display();
    void freeslot();
    void deleteapp();
};
void list::makeapp()
{
    node *curr,*prev,*temp;
    char n[30];
    int s,flag=0;
    cout<<"PLEASE ENTER YOUR NAME\n";
    cin.ignore();
    cin.getline(n,30);
    while(flag==0)
    {
        cout<<"PLEASE ENTER THE START TIME OF YOUR APPOINTMENT\n";
        cin>>s;
        try
        {
            if(s>=9&&s<=16)
                flag=1;
            else
                throw s;
        }
        catch(int s)
        {
            cout<<"ENTER TIME BETWEEN 9 AND 16 HRS!!\n";

        }
    }
    flag=0;
    curr=new node;
    curr->next=NULL;
    curr->back=NULL;
    strcpy(curr->name,n);
    curr->start=s;
    curr->end=s+1;

    if(head==NULL)
    {
        head=curr;
        prev=curr;
    }
    else
    {
        if(curr->start < head->start)
        {
            curr->next=head;
            head->back=curr;
            head=curr;
        }
        else
        {
            temp=head;
            while(temp!=NULL)
            {
                if(curr->start > temp->start)
                {
                    prev=temp;
                    temp=temp->next;
                }
                else
                {
                    if(curr->start==temp->start)
                    {
                        cout<<"APPOINTMENT ALREADY EXISTS PLEASE REBOOK!\n";
                        //delete(curr);
                        flag=1;
                        break;
                    }
                    else
                        break;
                }
            }
            if(temp!=NULL&&flag==0)
            {
                prev->next=curr;
                curr->back=prev;
                curr->next=temp;
                temp->back=curr;
            }
            else if(temp==NULL&&flag==0)
            {
                prev->next=curr;
                curr->back=prev;
            }
        }
    }
    if(flag==0)
        cout<<"APPOINTMENT BOOKED SUCCESSFULLY\n";
}
void list::display()
{
    node *temp;
    temp=head;
    cout<<"NAME"<<setw(26)<<"START"<<setw(5)<<"END"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->name<<setw(30-strlen(temp->name))<<temp->start<<setw(5)<<temp->end<<endl;
        temp=temp->next;
    }
}
void list::freeslot()
{
    node *temp,*prev;
    temp=head;
    cout<<"THE FREE SLOTS ARE:-\n";
    if(head!=NULL)
    {
        if(head->start!=9)
        {
            int time=(head->start)-9;
            int s=9;
            while(time!=0)
            {
                cout<<s<<"  to  "<<s+1<<endl;
                s++;
                time--;
            }
        }
        while(temp!=NULL)
        {

            if(temp->next!=NULL)
            {
                if(temp->end!=temp->next->start)
                {
                    int time=(temp->next->start)-temp->end;
                    int s=temp->end;
                    while(time!=0)
                    {
                        cout<<s<<"  to  "<<s+1<<endl;
                        s++;
                        time--;
                    }

                }
            }
            prev=temp;
            temp=temp->next;
        }
        if(prev->end!=17)
        {
            int time=17-prev->end;
            int s=prev->end;
            while(time!=0)
            {
                cout<<s<<"  to  "<<s+1<<endl;
                s++;
                time--;
            }
        }
    }

    else
    {
        cout<<"COMPLETE DAY IS FREE\n";
    }
}
void list::deleteapp()
{
    char dname[30];
    int s,e;
    cout<<"ENTER DETAILS OF APPOINTMENT TO CANCEL\n";
    cout<<"ENTER YOUR NAME:";
    cin.ignore();
    cin.getline(dname,30);
    cout<<"\n";
    cout<<"ENTER THE START TIME:";
    cin>>s;
    cout<<"\n";
    cout<<"END TIME:";
    cin>>e;

    node *temp;
    temp=head;
    int flag=0;
    while(temp!=NULL)
    {
        if(strcmp(temp->name,dname)==0&&temp->start==s&&temp->end==e)
        {
            if(temp==head)
            {
                node *newhead;
                newhead=temp->next;
                delete(head);
                head=newhead;
                flag=1;
                break;
            }
            if(temp->next==NULL)
            {
                node *pre;
                pre=temp->back;
                delete(temp);
                pre->next=NULL;
                flag=1;
                break;
            }
            else
            {
                node *pre,*succ;
                pre=temp->back;
                succ=temp->next;
                pre->next=succ;
                succ->back=pre;
                delete(temp);
                flag=1;
                break;
            }
        }
        temp=temp->next;
    }
    if(flag==0)
        cout<<"ENTER CORRECT APPOINTMENT DETAILS TO CANCEL APPOINTMENT\n";
    else
        cout<<"APPOINTMENT SUCCESSFULLY CANCELLED\n";
}
int main()
{
    list l[7];
    int day=0;
    int ch,e=0;
    while(e==0)
    {
        cout<<"1.BOOK APPOINTMENT\n";
        cout<<"2.DISPLAY APPOINTMENTS\n";
        cout<<"3.DISPLAY FREE SLOTS\n";
        cout<<"4.CANCEL APOINTMENT\n";
        cout<<"5.EXIT\n";
        cout<<"ENTER YOUR CHOICE\n";
        cin>>ch;

        switch(ch)
        {
        case 1:
            cout<<"ENTER THE DAY OF WHICH YOU WANT APPOINTMENT\n";
            cin>>day;
            l[day-1].makeapp();
            break;
        case 2:
            for(int i=0; i<7; i++)
            {
                cout<<"DAY"<<i+1<<":"<<endl;

                l[i].display();
            }
            break;
        case 3:
            for(int i=0; i<7; i++)
            {
                cout<<"DAY"<<i+1<<":"<<endl;
                l[i].freeslot();
            }
            break;
        case 4:
            cout<<"ENTER THE DAY OF APPOINTMENT TO CANCEL\n";
            cin>>day;
            l[day-1].display();
            l[day-1].deleteapp();
            break;
        case 5:
            e=1;
        }
    }
}
