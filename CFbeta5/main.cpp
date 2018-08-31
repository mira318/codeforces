#include <iostream>
#include <vector>
using namespace std;
vector<string> All;
int main()
{
    string S;
    int maxx = 0;
    while(getline(cin, S))
    {
        int l = S.length();
        maxx = max(maxx, l);
        All.push_back(S);
    }
    for(int i = 0; i < maxx + 2; ++i)
    {
        cout << '*';
    }
    cout << endl;
    bool flag = true;
    for(int j = 0; j < All.size(); ++j)
    {
        cout << '*';
        if((maxx - All[j].size()) % 2 == 0)
        {
            for(int i = 0; i < (maxx - All[j].size())/2; ++i)
            {
                cout << ' ';
            }
            cout << All[j];
            for(int i = 0; i < (maxx - All[j].size())/2; ++i)
            {
                cout << ' ';
            }
        }
        else
        {
            if(flag)
            {
                for(int i = 0; i < (maxx - All[j].size())/2; ++i)
                {
                    cout << ' ';
                }
                cout << All[j];
                for(int i = 0; i < (maxx - All[j].size())/2 + 1; ++i)
                {
                    cout << ' ';
                }
                flag = false;
            }
            else
            {
                for(int i = 0; i < (maxx - All[j].size())/2 + 1; ++i)
                {
                    cout << ' ';
                }
                cout << All[j];
                for(int i = 0; i < (maxx - All[j].size())/2; ++i)
                {
                    cout << ' ';
                }
                flag = true;
            }
        }
        cout << '*' << endl;
    }
    for(int i = 0; i < maxx + 2; ++i)
    {
        cout << '*';
    }
    return 0;
}
