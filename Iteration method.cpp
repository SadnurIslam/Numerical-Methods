#include<bits/stdc++.h>
using namespace std;
const double EP = 0.00001;
class Iteration_Method{
public:
    double x0 = 0.5;
    double f(double x){
        return 1/sqrt(1+x);
    }

    void find_root(){
        double x = x0;
        while(f(x)!=0.0){
            x = f(x0);
            double ep = abs((x-x0)/x);
            if(ep<=EP)break;
            x0=x;

        }
        cout<<"The root is "<<fixed<<setprecision(3)<<x<<endl;
    }

};
int main(){
    Iteration_Method iteration_method;
    iteration_method.find_root();
}

