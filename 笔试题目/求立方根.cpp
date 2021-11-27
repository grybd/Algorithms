#include <bits/stdc++.h>
using namespace std;

double cuberoot(double x) {
    double left = INT_MIN, right = INT_MAX;
    while (left <= right) {
        double mid = (left + right) / 2;
        double temp = mid * mid * mid;
        if (temp > x) {
            right = mid - 0.01;
        } else if (temp < x) {
            left = mid + 0.01;
        } else return mid;
    }
    return left;
}

int main() {
    double n;
    cin >> n;
    cout << fixed << setprecision(2) << cuberoot(n) << endl;
    return 0;
}
