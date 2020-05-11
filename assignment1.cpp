#include<iostream>
using namespace std;
int main()
{
 int a[10],v,ch,i,n,sum=0,count=0;
 char Ab;
 label:cout<<"Enter the no of students:";
 cin>>n;
 cout<<"\nNote:- Please enter -1 if student is absent\n";
 cout<<"\nEnter the Marks of student:\n ";
 

 //ACEEPTING ELEMENTS OF THE ARRAY//

 for(i=0;i<n;i++)
 {
  cin>>a[i];
  if(a[i]!=-1) 
     sum=a[i]+sum;
  else
     sum=sum+0;
 }
 for(i=0;i<n;i++)
 {
 	if(a[i]==-1)
 	count=count+1;
 }
 cout<<"\n----------------------------------------------------------\n";

 int min=a[0],max=a[0],temp[10]={0},k,max1=0,m[i]={0},max2=0,j,count1=0,count2=0;;
do
{
     
       cout<<"\n1.Display marks table\t2.Sum of the marks\n3.Average of the marks\t4.Minimum mark\n5.Maximum mark\t\t6.Absent student\n7.Reapeated Mark\t8.Exit\nEnter choice:";
       cin>>ch;
       cout<<"\n----------------------------------------------------------\n";

   switch(ch)
     {
       case 1:
           cout<<"\n|Roll No."<<"|Marks obtained|\n";
           for(i=0;i<n;i++)
            {
	           cout<<"\n|    "<<(i+1)<<"   |      "<<a[i]<<"     |\n";
            }
        break;
       case 2:
        //CALCULATING SUM AND AVERAGE OF THE ARRAY//
         cout<<"\nThe Sum of Marks of student is "<<sum;
       break;

       case 3:
         cout<<"\nThe average of marks of student is "<<(sum/(n-count));
       break;

       case 4:
         //CALCULATING MINIMUM ELEMENT OF THE ARRAY//

         for(i=0;i<n;i++)
           {
               if(a[i]<min && a[i]!=-1)
               min=a[i];
           }
         cout<<"\nThe minimum mark of the student is "<<min;
       break;
       case 5:
         //CALCULATING MAXIMUM ELEMENT OF THE ARRAY//

        for(i=0;i<n;i++)
          {
             if(max<a[i])
              max=a[i];
          }
        cout<<"\nThe maximum mark of the student is "<<max; 
       break;
       case 6:
       	 cout<<"No of absent student :"<<count<<"\n";
          	 if(count==0)
              cout<<"\nAll students are present";
              else
         cout<<"\nThe roll no of absent student are:-"; 
         for(i=0;i<n;i++)
          {
          	if(a[i]==-1)
              cout<<"\n"<<(i+1); 
          }
       break;
       case 7:
         for(i=0;i<n;i++)
          {    
		       count1=1;
	           for(j=i+1;j<n;j++)
	              if(a[i]==a[j])
	                {
	                   temp[i]=a[i];
	                   m[i]=count1++;
                    }
          }
         for(i=0;i<n;i++)
          {
                if(m[i]>max2&&temp[i]>max1)
	              {
	                   max2=m[i];
	                   max1=temp[i];
	                   k=i;
                  }   
          }
         for(i=0;i<n;i++)
          {
  	            if(max1==a[i])
  	            count2++;
          }     
         cout<<count2<<" no of students got "<<temp[k]<<" marks";
       break;
       case 8:
	   exit(0);
       default:
        cout<<"Invalid Choice";
     }
  cout<<"\n----------------------------------------------------------\n";
  cout<<"\nPress 1 to continue from menu\nPress 2 to enter student marks again\nPress 0 to exit\n";
  cin>>v;
  cout<<"\n----------------------------------------------------------\n";
}while(v==1);  
if(v==2)
goto label;
}




