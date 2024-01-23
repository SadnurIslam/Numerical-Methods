#include<bits/stdc++.h>
using namespace std;
const double EP = 0.00001;
class False_Position{
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
        double x = ((a*f(b))-(b*f(a)))/(f(b)-f(a));
        double x0 = x;
        while(f(x)!=0.0){
            if(f(a)*f(x)<0.0){
                b=x;
            }
            else if(f(a)*f(x)>0.0){
                a=x;
            }
            else{
                break;
            }

            x = ((a*f(b))-(b*f(a)))/(f(b)-f(a));

            double ep = abs((x-x0)/x);
            if(ep<=EP)break;
            x0=x;

        }
        cout<<"The root is "<<fixed<<setprecision(3)<<x<<endl;
    }

};
int main(){
    False_Position false_position;
    false_position.find_root();
}
