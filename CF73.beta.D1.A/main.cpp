#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool P[1000007];
vector<pair<long long, char> > Train;
int main()
{
    long long a, b;
    cin >> a >> b;
    for(int i = 2; i < 1000007; ++i)
    {
        P[i] = true;
    }
    for(int i = 2; i < 1000007; ++i)
    {
        if(P[i])
        {
            int k = 1;
            while(k * i <= 1000004)
            {
                P[k*i] = false;
                k++;
            }
        }
    }
    //cout << "hey" << endl;
    long long nod = 1;
    long long a2 = a;
    long long b2 = b;
    for(int i = 2; i < 1000007; ++i)
    {
        while((a2 % i == 0) && (b2 % i == 0))
        {
            nod = nod*i;
            a2 = a2/i;
            b2 = b2/i;
        }
    }
    //cout << "nod = " << nod << endl;
    long long nok = a*b/nod;
    //cout << "nok = " << nok << endl;
    int j = 1;
    while(a*j < nok)
    {
        Train.push_back(make_pair(a*j, 'D'));
        j++;
    }
    //cout << "j = " << j << endl;
    j = 1;
    while(b*j < nok)
    {
        Train.push_back(make_pair(b*j, 'M'));
        j++;
    }
    //cout << "j = " << j << endl;
    sort(Train.begin(), Train.end());
    //cout << "Train.size() = " << Train.size() << endl;
   // cout << "Train:" << endl;
    //for(int i = 0; i < Train.size(); ++i)
    //{
      //  cout << Train[i].first << " " << Train[i].second << endl;
    //}
    //cout << endl;
    long long D = 0;
    long long M = 0;

    //cout << "D = " << D << endl;
    //cout << "M = " << M << endl;
    if(Train[0].second == 'D')
    {
        D = D + Train[0].first;
    }
    else
    {
        M = M + Train[0].first;
    }
    //cout << "D = " << D << endl;
    //cout << "M = " << M << endl;
    for(int i = 1; i < Train.size(); ++i)
    {
        if(Train[i].second == 'D')
        {
            D = D + Train[i].first - Train[i - 1].first;
        }
        else
        {
            M = M + Train[i].first - Train[i - 1].first;
        }
        //cout << "D = " << D << endl;
        //cout << "M = " << M << endl;
    }
    if(a < b)
    {
        M = M + nok - Train[Train.size() - 1].first;
    }
    else
    {
        D = D + nok - Train[Train.size() - 1].first;
    }
    //cout << "D = " << D << endl;
    //cout << "M = " << M << endl;
    if(D > M)
    {
        cout << "Dasha";
    }
    if(M > D)
    {
        cout << "Masha";
    }
    if(M == D)
    {
        cout << "Equal";
    }
    return 0;
}
