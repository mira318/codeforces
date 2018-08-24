#include <iostream>

using namespace std;
int A[107];
int main()
{
    int n, k;
    cin >> n >> k;
    int sum = 0;
    int give = 0;
    for(int i = 0; i < n; ++i)
    {
        //cout << "i = " << i << endl;
        cin >> A[i];
        sum = sum + A[i];
        give = give + min(sum, 8);
        if(sum > 8)
        {
            sum = sum - 8;
        }
        else
        {
            sum = 0;
        }
        //cout << "give = " << give << endl;
        if(give >= k)
        {
            cout << i + 1;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}
