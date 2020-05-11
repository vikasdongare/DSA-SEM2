#include<iostream>
using namespace std;
int get(int,int,int mat[][10]);
int dsp(int,int,int mat[][10]);
int upr(int,int,int mat[][10]);
int trans(int,int,int mat[][10]);
int add();
int sub();
int mul();
int ch,v,mat1[10][10],mat2[10][10],ans[10][10],count=0,count1=0,i,j,k,r,c,r1,c1,r2,c2;

int main()
{
  do
  {
  cout<<"\n1.Upper triangular\t\t2.Transpose\n3.Addition of matrix\t\t4.Substraction of matrix\n5.Multiplication of matrix\t6.Exit\nEnter the choice:";
  cin>>ch;
  cout<<"\n-----------------------------------------------------------------------------------\n";
  switch(ch)
  {
    case 1:
      cout<<"Enter the rows and column :-\n";
      cin>>r>>c;
      get(r,c,mat1);
      dsp(r,c,mat1); 
      upr(r,c,mat1);
      break;
    case 2:
    	cout<<"Enter the rows and column :-\n";
        cin>>r>>c;
        get(r,c,mat1);
        dsp(r,c,mat1); 
        trans(r,c,mat1);
    break;
    case 3:
          add();
	break;
	case 4:
          sub();
	break;
	case 5:
           mul();
	break;
	case 6:
	exit(0);	
  }
  cout<<"\n-----------------------------------------------------------------------------------\n";
  cout<<"\nPress 1 to continue\nPress 0 to exit\nEnter choice:";
  cin>>v;
  cout<<"\n-----------------------------------------------------------------------------------\n";
}while(v==1);
cout<<"\n-----------------------------------------------------------------------------------\n";
}
int get(int r,int c,int mat[][10])
{
  int i,j,k;
  
  cout<<"Enter elements of matrix:\n";
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      cout<<"("<<i+1<<","<<j+1<<"):-";
      cin>>mat[i][j];
    }
  }
}
int dsp(int r,int c,int mat[][10])
{
  int i,j,k; 
  cout<<"\nThe elements of the matrix:\n";
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    { 
	  if(j==0)
         cout<<"|"<<mat[i][j]<<"\t";
      else if(j==c-1)
         cout<<mat[i][j]<<"|\t";
      else
         cout<<mat[i][j]<<"\t";
    }
      cout<<"\n";
  }
}
int upr(int r,int c,int mat[][10])
{ 
    int count=0;
	for(i=2;i<=r;i++)
         {
           for(j=1;j<i;j++)
              {
                 if(mat[i][j]!=0)
                    count++;
              }
          }
      if(count==0)
      cout<<"\nMatrix is upper triangular";
      else
      cout<<"\nMatrix is not upper triangular";
}
int trans(int r,int c,int mat[][10])
{
	cout<<"The transpose of matrix is:\n";
		for(i=0;i<c;i++)
          {
            for(j=0;j<r;j++)
               {
                  if(j==0)
                     cout<<"|"<<mat[j][i]<<"\t";
                  else if(j==c-1)
                     cout<<mat[j][i]<<"|\t";
                  else
                      cout<<mat[j][i]<<"\t";
               }
                  cout<<"\n";
         }
}
int add()
{
	  cout<<"Enter the rows and column for matrix 1:-\n";
        cin>>r1>>c1;
        get(r1,c1,mat1);
        dsp(r1,c1,mat1); 
	    cout<<"Enter the rows and column for matrix 2:-\n";
        cin>>r2>>c2;
        get(r2,c2,mat2);
        dsp(r2,c2,mat2); 
        if(r1==r2||c1==c2)
        {
	      for(i=0;i<r2;i++)
           {
           	 for(j=0;j<c2;j++)
        	  {
        		ans[i][j]=mat1[i][j]+mat2[i][j];
			  }
		   }
		cout<<"Addition of matrix is:-\n";
		dsp(r2,c2,ans);
		}
	    else
	      cout<<"\nAddition of matrix is not possible\n";
}
int sub()
{
	cout<<"Enter the rows and column for matrix 1:-\n";
        cin>>r1>>c1;
        get(r1,c1,mat1);
        dsp(r1,c1,mat1); 
	    cout<<"Enter the rows and column for matrix 2:-\n";
        cin>>r2>>c2;
        get(r2,c2,mat2);
        dsp(r2,c2,mat2); 
        if(r1==r2||c1==c2)
        {
        	for(i=0;i<r1;i++)
             {
        	    for(j=0;j<c1;j++)
        	     {
        	     	ans[i][j]=mat1[i][j]-mat2[i][j];
		       	 }
		     }
		cout<<"Substraction of matrix is:-\n";
		dsp(r1,c1,ans);
		}
	    else
	      cout<<"\nSubstraction of matrix is not possible\n";
}
int mul()
{
	cout<<"Enter the rows and column for matrix 1:-\n";
        cin>>r1>>c1;
        get(r1,c1,mat1);
        dsp(r1,c1,mat1); 
	    cout<<"Enter the rows and column for matrix 2:-\n";
        cin>>r2>>c2;
        get(r2,c2,mat2);
        dsp(r2,c2,mat2); 
        if(c1==r2)
        {
	      for(i=0;i<r1;i++)
            {
        	   for(j=0;j<c2;j++)
        	     {
        		   ans[i][j]=0;
        		   for(k=0;k<c1;k++)
        		    {
        		      ans[i][j]+=mat1[i][k]*mat2[k][j];
			        }
			     }
		    }
		cout<<"Multiplication of matrix is:-\n";
		dsp(r1,c2,ans);
		}
	    else
	      cout<<"\nMultiplication of matrix is not possible\n";
}
