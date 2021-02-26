#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            //就是个简单的字符值的ASCII码计算
            ans += s[i] - 'A' + 1;
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}