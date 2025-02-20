#include<bits/stdc++.h>
 
using namespace std;

#define max_iteration 100

double equation(double x,double y, double z, double i){
    return ((i*i*x) + (y*i) + z);
}

void falseposition(double a, double b,double x,double y, double z){
    double fa = equation(x,y,z,a), fb = equation(x,y,z,b);
    double x0 = ((a*fb)-(b*fa))/(fb-fa);
    double fx0,xold;
    int count = 0;
    while(true){
        cout<<count<<" : "<<x0<<endl;
        fx0 = equation(x,y,z,x0);
        fa = equation(x,y,z,a);
        if(fx0<1e-9 && fx0>(-1e-9)){
            cout<<"The root is "<<x0<<endl;
            break;
        }
        if((fx0 * fa) < 0){
            cout<<x0<<endl;
            xold = x0;
            x0 = ((a*fx0)-(x0*fa))/(fx0-fa);;
            b = xold;
        }
        else{
            cout<<x0<<endl;
            xold = x0;
            x0 = ((x0*fb)-(b*fx0))/(fb-fx0);
            a = xold;
        }
        count++;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<setprecision(9);
    bool flag = 0,found=0;
    double x,y,z;
    cin>>x>>y>>z;
    double a,b,fa,fb,fx;
    for(int i = 0;i<max_iteration;i++){
        fa = equation(x,y,z,i);
        fb = equation(x,y,z,i+1);
        if(fa<1e-9 && fa>(-1e-9)){
            cout<<"The root is "<<i<<endl;
            found=1;
            break;
        }
        if(fb<1e-9 && fb>(-1e-9)){
            cout<<"The root is "<<i+1<<endl;
            found=1;
            break;
        }
        if((fa*fb)<0){
            a = i;
            b = i+1;
            flag = 1;
            break;
        }
    }
    if(flag==0){
        for(int i = 0;i>(-max_iteration);i--){
        fa = equation(x,y,z,i);
        fb = equation(x,y,z,i-1);
        if(fa<1e-9 && fa>(-1e-9)){
            cout<<"The root is "<<i<<endl;
            found=1;
            break;
        }
        if(fb<1e-9 && fb>(-1e-9)){
            cout<<"The root is "<<i-1<<endl;
            found=1;
            break;
        }
        if((fa*fb)<0){
            a = i;
            b = i-1;
            break;
        }
    }
    }
    if(found==0) falseposition(a,b,x,y,z);
}