#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
const int M = 105;

int a[M] = {}; //存储水龙头结束时间
int w[N] = {}; //存储每一个学生用水时间

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        //将每一个学生都分给当下最早结束(即a[i]最小)的水龙头
        int idx = 1; //一定要注意是1
        for (int j = 1; j <= m; j++)
        {
            if (a[j] < a[idx])
                idx = j;
        }
        a[idx] += w[i];
    }
    //遍历所有水龙头
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        //寻找最晚结束的时间
        ans = max(ans, a[i]);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}