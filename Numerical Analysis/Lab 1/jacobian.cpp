#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int arr[3][4];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>arr[i][j];
        }
    }
    double x,y,z;
    x=arr[0][3]/arr[0][0];
    y=arr[1][3]/arr[1][1];
    z=arr[2][3]/arr[2][2];
    double arrx[20],arry[20],arrz[20];
    double arrxd[20],arryd[20],arrzd[20];
    
    arrx[0]=x;
    arry[0]=y;
    arrz[0]=z;

   for(int i=0;i<19;i++)
   {
        for(int j=0;j<3;j++)
        {
            if(j==0)
            {
                arrx[i+1]=(arr[0][3]-arr[0][1]*arry[i]-arr[0][2]*arrz[i])/arr[0][0];
                arrxd[i]=arrx[i+1]-arrx[i];
            }
            else if(j==1)
            {
                arry[i+1]=(arr[1][3]-arr[1][0]*arrx[i]-arr[1][2]*arrz[i])/arr[1][1];
                arryd[i]=arry[i+1]-arry[i];
            }
            else if(j==2)
            {
                arrz[i+1]=(arr[2][3]-arr[2][0]*arrx[i]-arr[2][1]*arry[i])/arr[2][2];
                 arrzd[i]=arrz[i+1]-arrz[i];
            }
        }
        
   }
   for(int i=0;i<20;i++)
   {
    cout<<"x"<<i+1<<"="<<arrx[i]<<endl;
    cout<<"difference"<<i+1<<" "<<arrxd[i]<<endl;
    cout<<endl;

    cout<<"y"<<i+1<<"="<<arry[i]<<endl;
    cout<<"difference"<<i+1<<" "<<arryd[i]<<endl;
    cout<<endl;

    cout<<"z"<<i+1<<"="<<arrz[i]<<endl;
    cout<<"difference"<<i+1<<" "<<arrzd[i]<<endl;
    cout<<endl;
   }
   cout<<arrx[19]<<" "<<arry[19]<<" "<<arrz[19]; 
    
}