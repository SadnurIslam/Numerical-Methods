#include <bits/stdc++.h>

using namespace std;

class DividedDifference {

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

        // creating divided difference table

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n-i; j++) {
                y[j][i] = (y[j+1][i-1] - y[j][i-1]) / (x[i+j] - x[j]);
            }
        }

        cout << "Enter the value of where find the interpolation: ";
        double xx;
        cin >> xx;


        double ans = y[0][0];

        for(int i = 1; i < n; i++) {
            double temp = 1;
            for(int j = 0; j < i; j++) {
                temp *= (xx - x[j]);
            }
            ans += (temp * y[0][i]);
        }

        cout << "\n\nResult: " << ans << endl << endl;
    }

};


int main() {

    DividedDifference ddf;
    ddf.solve();

    return 0;

}
