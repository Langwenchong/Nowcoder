#include <bits/stdc++.h>
using namespace std;
string book[1005];

bool cmp(string a, string b)
{
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }
    return a < b;
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> book[i];
    }
    sort(book + 1, book + 1 + n, cmp);
    while (q--)
    {
        int len;
        string s;
        cin >> len >> s;
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
            if (book[i].length() >= s.length())
            {
                if (book[i].substr(book[i].length() - len) == s)
                {
                    cout << book[i] << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
        {
            cout << -1 << endl;
        }
    }
    system("pause");
    return 0;
}