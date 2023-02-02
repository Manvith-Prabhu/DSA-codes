#include <iostream>
using namespace std;

int main()
{
    float A[3][5];
    int i, j;
    for(i=0;i<3;i++)
    {
        cout<<"Enter the coefficients of row "<<i+1<<" :"<<endl;
        for(j=0;j<3;j++)
            cin>>A[i][j];
            cout<<endl;
    }   

     cout<<"The matrix is :"<<endl;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            cout<<A[i][j]<<"   ";
            cout<<endl;
    }   

    float B[3][4];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
          B[i][j]= A[i][j];

    }   
    cout<<endl;
    cout<<endl;

    //rref format 
    //lower triangular 

    if(A[1][0]!=0)
    {
 
    for(i=0;i<3;i++)
        A[1][i]=A[1][i]-(B[1][0]/B[0][0])*A[0][i];
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
          B[i][j]= A[i][j];
    }     
       
   if(A[2][0]!=0 && A[0][0]!=0)
    {

     for(i=0;i<3;i++)
        A[2][i]=A[2][i]-(B[2][0]/B[0][0])*A[0][i];
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
          B[i][j]= A[i][j];
    }   
       
   if(A[2][1]!=0 && A[1][1]!=0)
   {
     for(i=0;i<3;i++)
        A[2][i]=A[2][i]-(B[2][1]/B[1][1])*A[1][i];
   }
 for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
          B[i][j]= A[i][j];
    }   

  //upper triangle 
 if(A[0][2]!=0 && A[1][2]!=0)
    {
     for(i=0;i<3;i++)
        A[0][i]=A[1][i]-(B[1][2]/B[0][2])*A[0][i];
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
          B[i][j]= A[i][j];
    }   
       
if(A[1][2]!=0 && A[2][2]!=0)
{
     for(i=0;i<3;i++)
        A[1][i]=A[2][i]-(B[2][2]/B[1][2])*A[1][i];
}

for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
          B[i][j]= A[i][j];
    }   

if(A[0][1]!=0)
{
     for(i=0;i<3;i++)
        A[0][i]=A[1][i]-(B[1][1]/B[0][1])*A[0][i];
}
for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
          B[i][j]= A[i][j];
    }   
          
    for(i=0;i<3;i++)
    {
          if(A[i][i]!=0)
        for(j=0;j<3;j++)
           A[i][j]= A[i][j]/B[i][i];
    }   
 
       
            cout<<"The Reduced row Echelon form of matrix is :"<<endl;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            cout<<(int)A[i][j]<<"   ";
            cout<<endl;
    }   

    
return 0;
}