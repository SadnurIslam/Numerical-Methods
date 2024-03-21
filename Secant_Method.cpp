#include<bits/stdc++.h>
using namespace std;
const double EP = 0.00001;
class Secant_Method{
public:
    double x0,x1;

    double f(double x){
        return x*x*x-2*x-5;
    }

    void set_initial_value(){
        srand(int(time(0)));
        while(true) {
            x0 = -9 + rand()%10;
            x1 = rand()%10;

            if(f(x0) * f(x1) < 0.0) break;
        }
        if(x0>x1)swap(x0,x1);
        cout<<x0 <<" "<<x1<<endl;
    }

    void find_root(){
        set_initial_value();
        double x = ((x0*f(x1))-(x1*f(x0)))/(f(x1)-f(x0));
        while(f(x)!=0.0){
            x = ((x0*f(x1))-(x1*f(x0)))/(f(x1)-f(x0));
            double ep = abs((x-x1)/x);
            if(ep<=EP)break;
            double t = x1;
            x1=x;
            x0=t;
        }
        cout<<"The root is "<<fixed<<setprecision(3)<<x<<endl;
    }

};
int main(){
    Secant_Method secant_method;
    secant_method.find_root();
}
