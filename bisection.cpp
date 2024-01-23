#include<bits/stdc++.h>
using namespace std;
const double EP = 0.00001;
class Bisection{
public:
    double a,b;

    double f(double x){
        return x*x*x-2*x-5;
    }

    void set_initial_value(){
        srand(int(time(0)));
        while(true) {
            a = -9 + rand()%10;
            b = rand()%10;

            if(f(a) * f(b) < 0.0) break;
        }

        cout<<a<<" "<<b<<endl;
    }

    void find_root(){
        set_initial_value();
        double c = (a+b)/2;
        double c0 = c;
        while(true){
            if(f(a)*f(c)<0.0){
                b=c;
            }
            else if(f(a)*f(c)>0.0){
                a=c;
            }
            else{
                break;
            }

            c = (a+b)/2;

            double ep = abs((c-c0)/c);
            if(ep<=EP)break;
            c0=c;

        }
        cout<<"The root is "<<fixed<<setprecision(3)<<c<<endl;
    }

};
int main(){
    Bisection bisection;
    bisection.find_root();
}
