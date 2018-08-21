#include <iostream>

using namespace std;

int main()
{
    long long l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    for(int i = l; i < r + 1; ++i)
    {
        if(i % k == 0)
        {
            if(i/k >= x && i/k <= y)
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
