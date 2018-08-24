#include <iostream>

using namespace std;
int A[107];
int B[107];
int ColA[15];
int ColB[15];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> B[i];
    }
    for(int i = 0; i < n; ++i)
    {
        ColA[A[i]]++;
        ColB[B[i]]++;
    }
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 1; i < 6; ++i)
    {
        //cout << "i = " << i << endl;
        //cout << "ColA[" << i << "] = " << ColA[i] << endl;
        //out << "ColB[" << i << "] = " << ColB[i] << endl;
        if(ColA[i] > ColB[i])
        {
            if((ColA[i] - ColB[i]) % 2 != 0)
            {
                cout << "-1";
                return 0;
            }
            else
            {
                sum1 = sum1 + (ColA[i] - ColB[i])/2;
                sum2 = sum2 + (ColA[i] - ColB[i])/2;
            }
        }
        if(ColA[i] < ColB[i])
        {
            if((ColB[i] - ColA[i]) % 2 != 0)
            {
                cout << "-1";
                return 0;
            }
            else
            {
                sum1 = sum1 - (ColB[i] - ColA[i])/2;
                sum2 = sum2 + (ColB[i] - ColA[i])/2;
            }
        }
        //cout << "sum1 = " << sum1 << endl;
        //cout << "sum2 = " << sum2 << endl;

    }
    if(sum1 != 0)
    {
        cout << "-1";
        return 0;
    }
    else
    {
        cout << sum2/2;
    }
    return 0;
}
