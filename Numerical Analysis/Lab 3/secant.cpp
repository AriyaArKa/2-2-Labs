#include<bits/stdc++.h>
 
using namespace std;

double equation(double x,double y, double z, double i){
    return ((i*i*x) + (y*i) + z);
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double x,y,z;
    cin>>x>>y>>z;
    double x1=0,x2=1,x3;
    int i = 0;
    double fx1,fx2;
    while(true){
        cout<<"iteration no "<<i<<": "<<x2<<endl;
        fx1 = equation(x,y,z,x1);
        fx2 = equation(x,y,z,x2);
        x3 = x2 - ((fx2*(x2-x1))/(fx2-fx1));
        cout<<"Error: "<<fabs(x2-x1)<<endl;
        if(fx2>(-1e-9) && fx2<(1e-9)){
            cout<<"The root is "<<x2<<endl;
            break;
        }
        swap(x1,x2);
        swap(x2,x3);
        i++;
    }
    

}