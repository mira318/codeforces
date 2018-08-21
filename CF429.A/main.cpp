#include <iostream>

using namespace std;
int Let[27];
int main()
{
    int n, k;
    cin >> n >> k;
    string S;
    cin >> S;
    for(int i = 0; i < n; ++i)
    {
        Let[S[i] - 'a']++;
    }
    for(int i = 0; i < 26; ++i)
    {
        if(Let[i] > k)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
