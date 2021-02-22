#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w, m, n;
    while (cin >> w >> m >> n)
    {
        if (m > n)
        {
            int tmp = n;
            n = m;
            m = tmp;
        }
        if (m == n)
        {
            cout << 0 << endl;
            return 0;
        }
        int i = 0;
        int j = 0;
        int num = 1;
        int a, b, c, d;
        bool dirr = true;
        while (num <= n)
        {
            if (num == m)
            {
                a = i;
                b = j;
            }
            if (num == n)
            {
                c = i;
                d = j;
            }
            num++;
            if (dirr)
            {
                j++;
            }
            else
            {
                j--;
            }
            if (j == w)
            {
                dirr = false;
                i++;
                j = w - 1;
            }
            if (j == -1)
            {
                j = 0;
                dirr = true;
                i++;
            }
        }
        cout << abs(a - c) + abs(b - d) << endl;
    }
    // system("pause");
    return 0;
}