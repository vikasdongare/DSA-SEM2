#include<iostream>
using namespace std;
class sparse
{
  public:
   int mat[10][3],r,c,n,i,j;
 
  
   void get()
    {
      cout<<"\nEnter rows and column of matrix:";
      cin>>r>>c;
      cout<<"Enter no of non-zero elements:";
      cin>>n;
      mat[0][0]=r;
      mat[0][1]=c;
      mat[0][2]=n;
      for(i=1;i<=n;i++)
       {
          cout<<"Enter position and non-zero element of("<<i<<"):";
          for(j=0;j<3;j++)
            {
              if(j==0)
               {
                   label:cout<<"\nr=";
                   cin>>mat[i][j]; 
                    if(mat[i][j]>r)
                     {
                       cout<<"Enter valid row position";
                       goto label;
                     }
               }
              else if(j==1)
               {
                   lab:cout<<"c=";
                   cin>>mat[i][j];
                   if(mat[i][j]>c)
                    {
                     cout<<"Enter valid column position";
                     goto lab;
                    } 
               }
             else 
               {
                   cout<<"Non-zero element=";
                   cin>>mat[i][j]; 
               }
            } 
        }
      }
     void disp()
       {
              cout<<"\nSaparse matrix is:\n";
              for(i=0;i<=n;i++)
                {
                   for(j=0;j<3;j++)
                     {
                        cout<<mat[i][j]<<"\t";
                     }
                        cout<<"\n";
                }
       }
   sparse add(sparse ob)
    {
        sparse temp;
        temp.r=ob.r;
        temp.c=ob.c;
        temp.mat[0][0]=r;
        temp.mat[0][1]=c;
        temp.mat[0][2]=n;
        int i=1,j=1,k=1;
        while(i<=n && j<=ob.n)
            {
                if(mat[i][0]==ob.mat[j][0])
                  {
                    if(mat[i][1]==ob.mat[j][1])
                     {
                       temp.mat[k][2]=mat[i][2]+ob.mat[j][2];
                       temp.mat[k][0]=mat[i][0];
                       temp.mat[k][1]=mat[i][1];
                       i++;
                       j++;
                       k++;
                     }
                    else if(mat[i][1]>ob.mat[j][1])
                     {
                       temp.mat[k][2]=ob.mat[j][2];
                       temp.mat[k][0]=ob.mat[j][0];
                       temp.mat[k][1]=ob.mat[j][1];
                       j++;
                       k++;
                     } 
                    else
                     {
                       temp.mat[k][2]=mat[i][2];
                       temp.mat[k][0]=mat[i][0];
                       temp.mat[k][1]=mat[i][1];
                       i++;
                       k++;
                     }
                 }
             else if(mat[i][0]>ob.mat[j][0])
                     {
                       temp.mat[k][2]=ob.mat[j][2];
                       temp.mat[k][0]=ob.mat[j][0];
                       temp.mat[k][1]=ob.mat[j][1];
                       j++;
                       k++;
                     } 
            else
                     {
                       temp.mat[k][2]=mat[i][2];
                       temp.mat[k][0]=mat[i][0];
                       temp.mat[k][1]=mat[i][1];
                       i++;
                       k++;
                     }
               temp.n=(k-1);        
       }
   
    return temp;
  }
  
  sparse trans()
  {
  	sparse temp;
  	for(i=0;i<=n;i++)
  	{
  		temp.mat[i][1]=mat[i][0];
		temp.mat[i][0]=mat[i][1];
	    temp.mat[i][2]=mat[i][2];       
	}
	return temp;
  }
  };
  sparse fast_transpose(sparse s)
  {
     int i,total=s.n,freq[20],start_pos[20],k,temp=0,b[20][20];
     s.mat[0][1]=s.r;
     s.mat[0][0]=s.c;
     s.mat[0][2]=total;
     
      if(total!=0)
      {
         for(i=0;i<s.c;i++)
         {
            freq[i]=0;
         }
         for(i=1;i<s.c;i++)
         {
            temp=s.mat[i][1];
            freq[temp]++;
         }
         start_pos[0]=1;
         for(i=1;i<s.c;i++)
         {
           start_pos[i]=start_pos[i-1]+freq[i-1];
         }
         for(i=1;i<=total;i++)
         {
           k=start_pos[s.mat[i][1]];
           b[k][0]=s.mat[i][1];
           b[k][1]=s.mat[i][0];
           b[k][2]=s.mat[i][2];
         }
         for(i=1;i<=total;i++)
         {
           for(k=0;k<20;k++)
           {
             s.mat[i][k]=b[i][k];
           }
         }
       }cout<<"transposed succesfully";
       s.disp();
      } 


int main()
{
	int ch,v;
  sparse s1,s4,s2,s3;
  do
  {
     cout<<"\n-------------------------------------------------------------------------------\n";
     cout<<"\n1.Addition\t\t2.Simple Transpose\n3.Fast Transpose\t4.Exit\nEnter choice:";
     cin>>ch;
     cout<<"\n-------------------------------------------------------------------------------\n";
     switch(ch)
     {
     	case 1:
     		cout<<"\nEnter details of matrix 1:";
            s1.get();
            s1.disp();
            cout<<"\nEnter details of matrix 2:";
			s2.get();
            s2.disp();
            cout<<"\nAddition of matrix:";
            s3=s1.add(s2);
            s3.disp();
            cout<<"\n---------------------------------------------\n";
        break;
        case 2:
        	cout<<"\nEnter details of matrix :";
        	s1.get();
        	s1.disp();
            cout<<"\nTranspose is:";
            s3=s1.trans();
            s3.disp();
        break;
        case 3:
        	cout<<"\nEnter details of matrix :";
        	s1.get();
        	s1.disp();
            cout<<"\nFast Transpose is:";
            s2=fast_transpose(s1);
           // s2.disp();
        break;
        case 4:
        	goto label;
        default:
        	cout<<"\n\t\t!! Enter valid choice !!";
     }
        cout<<"\n\nPress 1 to continue\nPress 0 to exit\n";
        cin>>v;
  }while(v==1);
       label: cout<<"\n**************************!! THANK YOU !!*******************************\n";
}
