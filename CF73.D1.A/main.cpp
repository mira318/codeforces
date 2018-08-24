#include <iostream>
#include <map>
using namespace std;
map<string, int> M;
bool flag;
bool check(int a, int b, int c)
{
    //cout << "check(" << a << ", " << b << ", " << c << ")" << endl;
    int r1, r2;
    if(a <= b)
    {
        r1 = b - a;
    }
    else
    {
        r1 = 12 - a + b;
    }
    if(b <= c)
    {
        r2 = c - b;
    }
    else
    {
        r2 = 12 - b + c;
    }
    //cout << "r1 = " << r1 << endl;
    //cout << "r2 = " << r2 << endl;
    if(r1 == 4 && r2 == 3)
    {
        cout << "major";
        flag = true;
    }
    if(r1 == 3 && r2 == 4)
    {
        cout << "minor";
        flag = true;
    }
}
int main()
{
    M["C"] = 1;
    M["C#"] = 2;
    M["D"] = 3;
    M["D#"] = 4;
    M["E"] = 5;
    M["F"] = 6;
    M["F#"] = 7;
    M["G"] = 8;
    M["G#"] = 9;
    M["A"] = 10;
    M["B"] = 11;
    M["H"] = 12;
    string X, Y, Z;
    cin >> X >> Y >> Z;
    int x, y, z;
    x = M[X];
    y = M[Y];
    z = M[Z];
    //cout << "x = " << x << endl;

    //cout << "y = " << y << endl;

    //cout << "z = " << z << endl;
    flag = false;
    check(x, y, z);

    check(x, z, y);

    check(y, x, z);

    check(y, z, x);

    check(z, y, x);

    check(z, x, y);
    if(!flag)
    {
        cout << "strange";
    }
    return 0;
}
