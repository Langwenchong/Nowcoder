#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int ans = 0;
//存取学生的颜值
int s[N];

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        ans = 0;
        //每次都要初始化为全0
        memset(s, 0, sizeof(s));
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        //排序
        sort(s, s + n);
        for (int i = 0; i < n - 1;)
        {
            //当相邻的两个可以组合（最好情况了）
            if (s[i + 1] - s[i] < m)
            {
                //这两个人不再参与选拔
                i += 2;
                //组数加一
                ans++;
            }
            else
            {
                //没有人可以和他组合了，所以跳过他
                i++;
            }
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}