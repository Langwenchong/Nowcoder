#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        //记录四个字符出现的坐标
        int l = -1, o = -1, v = -1, e = -1;
        long long ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'L')
                l = i;
            else if (s[i] == 'O')
                o = i;
            else if (s[i] == 'V')
                v = i;
            else if (s[i] == 'E')
                e = i;
            //取一个含有字符串的love的子串并且比较四个坐标取最小值
            int cnt = min(min(l, o), min(v, e));
            if (cnt != -1)
            {
                //包含本次子串的情况数量为左边的字符数+1
                ans += cnt + 1;
            }
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}