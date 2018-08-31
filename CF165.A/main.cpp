#include <iostream>

using namespace std;

int main()
{
    int t;
    long double a;
    cin >> t;
    cout.precision(10);
    for(int i = 0; i < t; ++i)
    {
        cin >> a;
        long double may;
        bool flag = false;
        for(int i = 3; i < 2000 && !flag; ++i)
        {
            long double p = i;
            may = (180*(p - 2))/p;
            //cout << "p = " << p << endl;
            //cout << "may = " << may << fixed << endl;
            //cout << "a = " << a << endl;
            if(may == a)
            {
                cout << "YES" << endl;
                flag = true;
            }
        }
        if(!flag)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
