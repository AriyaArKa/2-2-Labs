#include<bits/stdc++.h>
 
using namespace std;

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double matrix[3][4] {{1,5,-1,10},{1,1,8,20},{4,2,1,14}};
        
    if(matrix[0][0]< (abs(matrix[0][1])+abs(matrix[0][2]))){
        cout<<"The equations are not diagonally dominant"<<endl;
    }
    else if(matrix[1][1]< (abs(matrix[1][0])+abs(matrix[1][2]))){
        cout<<"The equations are not diagonally dominant"<<endl;
    }
    else if(matrix[2][2]< (abs(matrix[2][0])+abs(matrix[2][1]))){
        cout<<"The equations are not diagonally dominant"<<endl;
    }
    

    for(int i = 0;i<4;i++){
        swap(matrix[0][i],matrix[2][i]);
    }
    for(int i = 0;i<4;i++){
        swap(matrix[1][i],matrix[2][i]);
    }

    for(int i = 0;i<3;i++){
        for(int j = 0;j<4;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    double x1[100],x2[100],x3[100];
    double errsum;
    double ex1[100],ex2[100],ex3[100];
    x1[0] = matrix[0][3] / (-matrix[0][0]);
    x2[0] = matrix[1][3] / (-matrix[1][1]);
    x3[0] = matrix[2][3] / (-matrix[2][2]);
    int i = 0;
    while(true){
        x1[i+1]= (matrix[0][3] - (matrix[0][1] * x2[i]) - (matrix[0][2] * x3[i]))/(-matrix[0][0]);
        x2[i+1]= (matrix[1][3] - (matrix[1][0] * x1[i])- (matrix[1][2] * x3[i]))/(-matrix[1][1]);
        x3[i+1]= (matrix[2][3] - (matrix[2][0] * x1[i]) - (matrix[2][1] * x2[i]))/(-matrix[2][2]);
        ex1[i] = (x1[i+1]-x1[i])*(x1[i+1]-x1[i]);
        ex2[i] = (x2[i+1]-x2[i])*(x2[i+1]-x2[i]);
        ex3[i] = (x3[i+1]-x3[i])*(x3[i+1]-x3[i]);
        errsum = sqrt((ex1[i]+ex2[i]+ex3[i])/3.0);
        cout<<"itr "<<i<<" x1: "<<x1[i+1]<<" x2: "<<x2[i+1]<<" x3: "<<x3[i+1]<<" error: "<<errsum<<endl;
        if(errsum>=(-1e-4) && errsum<=(1e-4)){
            cout<<"The roots are "<<"x1: "<<x1[i+1]<<"x2: "<<x2[i+1]<<"x3: "<<x3[i+1]<<endl;
            break;
        }
        i++;
        if(i==98){
            break;
        }
    }
    
}