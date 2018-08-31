#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long double r, x, y, x2, y2;
    cin >> r >> x >> y >> x2 >> y2;
    long double S = sqrt((x - x2)*(x - x2) + (y - y2)*(y - y2));
    int k;
    k = S/(2*r);
    if(k*2*r < S)
    {
        cout << k + 1;
    }
    else
    {
        cout << k;
    }
    return 0;
}
