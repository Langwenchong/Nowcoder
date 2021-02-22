#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        int len = m + n - 1;
        int l = 1;
        int r = len - m + 1;
        char s[len + 5];
        for (int i = 0; i < (n - 1) / 2 + 1; i++)
        {
            memset(s, '.', sizeof(s));
            int ll = l;
            int rr = r;
            for (int i = 0; i < m; i++)
            {
                s[ll + i] = '*';
                s[rr + i] = '*';
            }
            for (int i = 1; i <= len; i++)
            {
                cout << s[i];
            }
            l++;
            r--;
            cout << endl;
        }
        // l = (n - 1) / 2;
        // r = (len - 1) / 2 + 1;
        l-=2;
        r+=2;
        if(m==1){
            r=(len+1)/2+1;
        }
        for (int i = 0; i < (n - 1) / 2; i++)
        {
            memset(s, '.', sizeof(s));
            int ll = l;
            int rr = r;
            for (int i = 0; i < m; i++)
            {
                s[ll + i] = '*';
                s[rr + i] = '*';
            }
            for (int i = 1; i <= len; i++)
            {
                cout << s[i];
            }
            l--;
            r++;
            cout << endl;
        }
    }
    // system("pause");
    return 0;
}