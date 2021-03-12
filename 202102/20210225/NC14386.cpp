#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string num;
        cin >> num;
        int len = num.size();
        int ans = 0;
        for (int i = 0; i < len; i++)
        {
            ans = ans + pow(num[i] - '0', len);
            //自己在本地vscode上测试153居然会输出No!
            // cout << "pow:" << pow(num[i] - '0', len) << endl;
            // cout << ans << endl;
        }
        string s = to_string(ans);
        if (s == num)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    system("pause");
    return 0;
}