#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
    double x;
    cout << "Input X: ";
    cin >> x;
    double rounded = round(x);
    printf("%.0f", rounded);
    cout << endl;
    return 0;
}
