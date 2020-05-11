#include<iostream>
using namespace std;
int n;
class marks
{
    float a[20];
public:
    void read();
    void display();
    void selection_sort();
    void bubble_sort();
    void insertion_sort();
    void shell_sort();
    void score();
};
void marks::read()
{
    int i;
    cout<<"enter the no. of students:";
    cin>>n;
    cout<<"\nEnter the marks of students:\n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

void marks::selection_sort()
{
    int i,j,minpos;
    float temp;
    for(i=0;i<n;i++)
    {
        minpos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[minpos])
            {
                minpos=j;
            }
        }
        if(minpos!=i)
        {
            temp=a[i];
            a[i]=a[minpos];
            a[minpos]=temp;
        }
    }
}

void marks:: display()
{
    int i;
    for(i=n-1;i>=0;i--)
    {
        cout<<a[i]<<"\n";
    }
}

void marks::bubble_sort()
{
    int i,j;
    float temp;
    for(i=1;i<n-1;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void marks :: shell_sort()
{
	int gap, i, j, k=1;
	float temp;
	for(gap=n/2;gap>0;gap/=2)
	{
		for(i=gap;i<n;i++)
		{
			for(j=i-gap;j>=0 && a[j]>a[j+gap];j-=gap)
			{
				temp=a[j];
				a[j]=a[j+gap];
				a[j+gap]=temp;
				//To display passes
				cout<<"\nPass "<<k<<" : \n";
				display();
				k++;
			}
		}
	}
}

void marks::insertion_sort()
{
    int i,j;
    float ele;
    for(i=1;i<n;i++)
    {
        ele=a[i];
        j=i;
        while((j>0) && (a[j-1]>ele))
        {
            a[j]=a[j-1];
            j=j-1;
        }
        a[j]=ele;
    }
}

void marks::score()
{
    {
        int i;
        for(i=n-1;i>n-6;i--)
        {
            cout<<a[i]<<"\n";
        }
    }
}


int main()
{
    int ch,i;
    float a[20];
    marks m;
    m.read();
    cout<<"Marks of students are:\n";
    m.display();
    do
    {
        cout<<"\n=======================================\n";
        cout<<"MENU:\n\t1.Selection Sort\n\t2.Bubble Sort\n\t3.Insertion Sort\n\t4.Shell Sort\n\t5.Top five Students marks\n\t6.Exit\n";
        cout<<"\nEnter the choice:";
        cin>>ch;
        cout<<"\n=======================================\n";
        switch(ch)
        {
        case 1:
        m.selection_sort();
        cout<<"Selection Sort according to marks:\n";
        m.display();
        break;

        case 2:
        m.bubble_sort();
        cout<<"Bubble Sort according to marks:\n";
        m.display();
        break;

        case 3:
        m.insertion_sort();
        cout<<"Insertion Sort according to marks:\n";
        m.display();
        break;

	  case 4:
        m.shell_sort();
        cout<<"Shell Sort according to marks:\n";
        m.display();
        break;

	  case 5:
	  cout<<"\nThe first five marks of the students in the FE class are:\n";
        m.score();
	  break;

	  default:
		cout<<"\nProgram Exited.\n";
        }
    }while(ch<6);

    return 0;
}
