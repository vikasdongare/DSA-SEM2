#include<iostream>
#include<math.h>
using namespace std;

typedef struct poly
{
   float coe;
   int exp;
}poly_term;
class polynomial
{
  public:
  poly_term p[100];
  int total_terms,i,j,k,x;
  polynomial()
  {
  	i=0;
    j=0;
    k=0;
    total_terms=0;
    p[i].coe=0;
    p[i].exp=0;
   }
  void get()
  {
    cout<<"\nEnter the total terms in the polynomial:";
    cin>>total_terms;
    for(i=0;i<total_terms;i++)
    {
       cout<<"Enter coefficient and exponent of polynomial:";
       cin>>p[i].coe>>p[i].exp;
    }
   }
   void disp()
   {
     for(i=0;i<total_terms;i++)
    {
       cout<<p[i].coe<<"x^"<<p[i].exp;
       if(i!=total_terms-1)
        cout<<"+";
    }
   }
   void eva()
   {
     float eva=0;
     cout<<"\nEnter the value of x:-";
     cin>>x;
     for(i=0;i<total_terms;i++)
     { 
       eva=(p[i].coe*(pow(x,p[i].exp)))+eva;
     }
     cout<<"Evaluation of polynomial="<<eva;
   }
};
int mul(polynomial,polynomial);
int add(polynomial,polynomial);

int main()
{
	int v,ch;
  polynomial p1,p2,p3;
  label:p1.get();
  p1.disp();
  p2.get();
  p2.disp();
  do
  {
     cout<<"\n1.Addition\t2.Multiplication\n3.Exit\nEnter your choice:";
     cin>>ch;
     switch(ch)
       {
          case 1:
  		        cout<<"\nAddition is:";
                add(p1,p2);
            break;
         case 2:
    	       cout<<"\nMultiplication is:";
               mul(p1,p2);
            break;
	     case 3:
		    exit (0);
       }
          cout<<"\nPress 1 to enter polynomial\nPress 2 to continue operations\nPress 0 to exit\nEnter choice:-";
		  cin>>v;
		  if(v==1)
		    goto label; 
   }while(v==2);
}

int add(polynomial o,polynomial ob)
{
	int i=0,j=0,k=0;
	 polynomial temp;
     while(i<o.total_terms || j<ob.total_terms)
     {
       if(o.p[i].exp==ob.p[j].exp)
        {
          temp.p[k].coe=o.p[i].coe+ob.p[j].coe;
          temp.p[k].exp=o.p[i].exp;
          i++;
          j++;
          k++;
        }
       else if(o.p[i].exp>ob.p[j].exp)
        {
          temp.p[k].coe=o.p[i].coe;
          temp.p[k].exp=o.p[i].exp;
          i++;
          k++;
        }
       else
        {
          temp.p[k].coe=ob.p[j].coe;
          temp.p[k].exp=ob.p[j].exp;
          j++;
          k++;
        }  
     temp.total_terms=k;
   }
   temp.disp();
}

int mul(polynomial o,polynomial ob)
{
	int k=0;
	polynomial temp;
	for(int i=0;i<o.total_terms;i++)
	{
		for(int j=0;j<ob.total_terms;j++)
		{
			temp.p[k].coe=o.p[i].coe*ob.p[j].coe;
			temp.p[k].exp=o.p[i].exp+ob.p[j].exp;
			k++;
		}	
	}	
	temp.disp();
}

