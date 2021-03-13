#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i % 4 == 0)
            continue;
        bool v = true;
        int k = i;
        //逐位取最后一位
        while (k != 0)
        {
            if (k % 10 == 4)
            {
                v = false;
                break;
            }
            k /= 10;
        }
        if (v)
        {
            cout << i << endl;
        }
    }
    system("pause");
    return 0;
}