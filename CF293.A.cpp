#include <iostream>

using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;
    int j = A.length() - 1;
    while(j >= 0 && A[j] == 'z')
    {
        j--;
    }
    if(j == -1)
    {
        cout << "No such string";
    }
    else
    {
        A[j] = char(A[j] + 1);
        for(int i = j + 1; i < A.length(); ++i)
        {
            A[i] = 'a';
        }
    }
    if(A == B)
    {
        cout << "No such string";
    }
    else
    {
        cout << A;
    }
    return 0;
}
