#include <iostream>

using namespace std;
const int N = int(1e5) + 7;
bool Was[N];
int main()
{
    int n, a;
    cin >> n;
    int wait = n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a;
        Was[a] = true;
        if(a == wait)
        {
            int i = 0;
            while(Was[a - i] == true)
            {
                cout << a - i << " ";
                i++;
                wait--;
            }
        }
        cout << endl;
    }
    return 0;
}
