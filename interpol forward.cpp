#include <bits/stdc++.h>

using namespace std;

class NewtonsForwardDifferenceFormula {

public:

    void solve() {
        double x[100], y[100][100];

        int n;
        cout << "Number of data: ";
        cin >> n;

        cout << "Enter data: " << endl;

        for(int i = 0; i < n; i++) {
            cout << "x[" << i << "] = ";
            cin >> x[i];
            cout << "y[" << i << "] = ";
            cin >> y[i][0];
        }

        // creating forward difference table

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n-1; j++) {
                y[j][i] = y[j+1][i-1] - y[j][i-1];
            }
        }

        // displaying forward difference table
        cout << "\n\nFORWARD DIFFERENCE TABLE\n\n";
        for(int i = 0; i < n; i++) {
            cout << x[i];
            for(int j = 0; j < n-i; j++) {
                cout << "\t" << y[i][j];
            } cout << endl;
        }
        cout << "Enter the value of where find the interpolation: ";
        double xx;
        cin >> xx;
        // step size
        double h = x[1] - x[0];
        double p = (xx - x[0]) / h;

        double yy = 0.0;
        double pp = p;
        yy = y[0][0] + p*y[0][1];
        double fact = 1;
        for(int i = 2; i < n; i++) {

            pp = pp*(p-(i-1));
            fact = fact*i;

            yy += (pp*y[0][i]) / fact;
            cout << "p = "<< pp << endl;
            cout << "fact = "<< fact << endl;

        }

        cout << "\n\nResult: " << yy << endl << endl;
    }

};


int main() {

    NewtonsForwardDifferenceFormula nfd;
    nfd.solve();

    return 0;

}
