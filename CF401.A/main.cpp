#include <iostream>

using namespace std;
bool A[3];
int main()
{
    int n, pos, check;
    cin >> n >> pos;
    check = n;
    n = n % 6;
    A[pos] = true;
    //or(int i = 0; i < 3; ++i)
    //{
      //  cout << A[i] << " ";
    //}
    //cout << endl;
    for(int i = n; i > 0; --i)
    {
        if(i % 2 == 0)
        {
            swap(A[1], A[2]);
        }
        else
        {
            swap(A[1], A[0]);
        }
        //for(int j = 0; j < 3; ++j)
        //{
          //  cout << A[j] << " ";
       // }
        //cout << endl;
    }
    for(int i = 0; i < 3; ++i)
    {
        if(A[i])
        {
            cout << i;
            return 0;
        }
    }
    for(int j = 0; j < 3; ++j)
    {
        A[0] = false;
        A[1] = false;
        A[2] = false;
        A[j] = true;
        for(int i = 0; i < 3; ++i)
        {
            cout << A[i] << " ";
        }
        cout << endl;
        for(int i = 1; i <= check; ++i)
        {
            if(i % 2 == 0)
            {
                swap(A[1], A[2]);
            }
            else
            {
                swap(A[1], A[0]);
            }
            for(int i = 0; i < 3; ++i)
            {
                cout << A[i] << " ";
            }
            cout << endl;
        }
        cout << "did" << endl;

    }
    return 0;
}
