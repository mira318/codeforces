#include <iostream>
using namespace std;
int Hercol[12];
int Morcol[12];
int main()
{
    int n;
    cin >> n;
    string H, M;
    cin >> H >> M;
    for(int i = 0; i < n; ++i)
    {
        Hercol[H[i] - '0']++;
        Morcol[M[i] - '0']++;
    }
    int ans1 = 0;
    int j = 0;
    for(int i = 0; i < 10; ++i)
    {

        //cout << "Hercol[" << i << "] = " << Hercol[i] << endl;
        //cout << "Morcol[" << j << "] = " << Morcol[j] << endl;
        while(Hercol[i] > 0 && j < 10)
        {
            while((j < i || Morcol[j] == 0) && j < 10)
            {
                j++;
            }
            if(j < 10)
            {
                if(Morcol[j] < Hercol[i])
                {
                    Hercol[i] = Hercol[i] - Morcol[j];
                    Morcol[j] = 0;
                }
                else
                {
                    Morcol[j] = Morcol[j] - Hercol[i];
                    Hercol[i] = 0;
                }
                //cout << "Hercol[" << i << "] = " << Hercol[i] << endl;
                //cout << "Morcol[" << j << "] = " << Morcol[j] << endl;
            }
        }
        ans1 = ans1 + Hercol[i];
        //cout << "ans1 = " << ans1 << endl;
    }
    for(int i = 0; i < 10; ++i)
    {
        Hercol[i] = 0;
        Morcol[i] = 0;
    }
    for(int i = 0; i < n; ++i)
    {
        Hercol[H[i] - '0']++;
        Morcol[M[i] - '0']++;
    }
    int ans2 = 0;
    j = 0;
    for(int i = 0; i < 10; ++i)
    {

        //cout << "Hercol[" << i << "] = " << Hercol[i] << endl;
        //cout << "Morcol[" << j << "] = " << Morcol[j] << endl;
        while(Hercol[i] > 0 && j < 10)
        {
            while((j <= i || Morcol[j] == 0) && j < 10)
            {
                j++;
            }
            if(j < 10)
            {
                if(Morcol[j] < Hercol[i])
                {
                    ans2 = ans2 + Morcol[j];
                    Hercol[i] = Hercol[i] - Morcol[j];
                    Morcol[j] = 0;
                }
                else
                {
                    ans2 = ans2 + Hercol[i];
                    Morcol[j] = Morcol[j] - Hercol[i];
                    Hercol[i] = 0;
                }
          //      cout << "Hercol[" << i << "] = " << Hercol[i] << endl;
            //    cout << "Morcol[" << j << "] = " << Morcol[j] << endl;
              //  cout << "ans2 = " << ans2 << endl;
            }
        }
    }
    cout << ans1 << endl << ans2;
    return 0;
}
