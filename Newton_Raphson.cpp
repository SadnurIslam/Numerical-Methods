#include<bits/stdc++.h>
using namespace std;
const double EP = 0.00001;
class Newton_Raphson{
public:
    double x0 = 1.0;
    double f(double x){
        return x*x*x-2*x-5;
    }

    double df(double x){
        return 3*x*x-2;
    }

    void set_initial_value(){
        srand(int(time(0)));
        while(df(x0)==0.0) {
            x0 = -9 + rand()%10;
        }

        cout<<x0<<endl;
    }

    void find_root(){
        set_initial_value();
        double x = x0;
        while(f(x)!=0.0){
            x = x0-(f(x0)/df(x0));
            double ep = abs((x-x0)/x);
            if(ep<=EP)break;
            x0=x;

        }
        cout<<"The root is "<<fixed<<setprecision(3)<<x<<endl;
    }

};
int main(){
    Newton_Raphson newton_raphson;
    newton_raphson.find_root();
}
