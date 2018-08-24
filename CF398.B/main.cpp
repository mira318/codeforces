#include <iostream>
#include <queue>
using namespace std;
const int N = int(1e5) + 7;
long long T[N];
queue<long long> Q;
int main()
{
    long long topen, tclose, onet;
    int n;
    cin >> topen >> tclose >> onet >> n;
    if(n == 0)
    {
        cout << topen;
        return 0;
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> T[i];
    }
    long long twait = 1e12 + 7;
    long long bestans;
    if(T[0] > 0)
    {
        twait = topen - T[0] + 1;
        bestans = T[0] - 1;
    }
    Q.push(max(T[0] + onet, topen + onet));
    for(int i = 1; i < n; ++i)
    {
        //cout << "i = " << i <<endl;
        //cout << "Q.back() = " << Q.back() << endl;
        //cout << "twait = " << twait << endl;
        //cout << "T[" << i << "] - 1 = " << T[i] - 1 << endl;
        if((T[i] - 1 >= 0) && (Q.back() > T[i] - 1) && (twait > Q.back() - T[i] + 1) && (Q.back() - T[i] + 1 + onet <= tclose))
        {
            twait = Q.back() - T[i] + 1;
            bestans = T[i] - 1;
        }
        if((T[i] - 1 >= 0) && (Q.back() <= T[i] - 1) && (twait > 0) && (T[i] - 1 + onet <= tclose))
        {
            twait = 0;
            bestans = T[i] - 1;
        }
        if(T[i] >= Q.back())
        {
            Q.push(T[i] + onet);
        }
        else
        {
            Q.push(Q.back() + onet);
        }
        //cout << "res:" << endl;
        //cout << "twait = " << twait << endl;
        //cout << "bestans = " << bestans << endl;
    }
    cout << bestans;
    return 0;
}
