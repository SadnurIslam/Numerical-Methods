#include<bits/stdc++.h>
using namespace std;
class Least_Square_For_Curve_Fitting{
public:

    void find_curve(){
        ifstream file;
        double a,b;
        int  n;
        double x[100],y[100];
        double sum_x=0,sum_y=0,sum_xx=0,sum_yy=0,sum_xy=0;
        file.open("input.txt");
        if(file.is_open()){
            file>>n;
            int i = 0;
            while(file>>x[i]>>y[i]){
                sum_x+=x[i];
                sum_y+=y[i];
                sum_xx+=(x[i]*x[i]);
                sum_yy+=(y[i]*y[i]);
                sum_xy+=(x[i]*y[i]);
                i++;
            }
        }
        file.close();
        b = (n*sum_xy-sum_x*sum_y)/(n*sum_xx-(sum_x*sum_x));
        a = (sum_y/n)-b*(sum_x/n);

        cout<<"The equation: "<<fixed<<setprecision(5)<<a<<"+"<<b<<"x"<<endl;
    }

};

int main(){
    Least_Square_For_Curve_Fitting least_square;
    least_square.find_curve();
}
