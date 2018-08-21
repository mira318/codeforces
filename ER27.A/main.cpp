#include <iostream>
#include <algorithm>
using namespace std;
int A[2000];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < 2*n; ++i)
    {
        cin >> A[i];
    }
    sort(A, A + 2*n);
    if(A[n - 1] < A[n])
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
