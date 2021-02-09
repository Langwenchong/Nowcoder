#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    char s;
    int num = 0;
    for (int i = 0; i < n*m; i++)
    {
        cin >> s;
        if (s == '.')
        {
            num++;
        }
    }
    int cnt = num - n - m + 1;
    if (cnt % 2 == 1)
        cout << "niuniu" << endl;
    else
        cout << "niumei" << endl;
    system("pause");
    return 0;
}