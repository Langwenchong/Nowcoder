#include <bits/stdc++.h>
using namespace std;

struct Gun
{
    //枪的初始战斗力
    double num;
    //枪支持的配件数
    int len;
    //枪支持的配件号
    int a[1005];
} gun[1005];
//配件加强数值数组
double plugin[1005];

//计算每把枪的最理想战斗力
double Count(int x)
{
    double sum = 1;
    for (int i = 1; i <= gun[x].len; i++)
    {
        //这里要注意，较难想
        sum += plugin[gun[x].a[i]];
    }
    return gun[x].num * sum;
}

int main()
{
    int n, m;
    cin >> n >> m;
    //存储枪的初始数据
    for (int i = 1; i <= n; i++)
    {
        cin >> gun[i].num;
        cin >> gun[i].len;
        for (int j = 1; j <= gun[i].len; j++)
        {
            cin >> gun[i].a[j];
        }
    }
    //记录每一个型号的枪件最强属性
    for (int i = 1; i <= m; i++)
    {
        int index;
        double tmp;
        cin >> index >> tmp;
        plugin[index] = max(plugin[index], tmp);
    }
    double ans = 0.0;
    for (int i = 1; i <= n; i++)
    {
        if (ans < Count(i))
            ans = Count(i);
    }
    cout << fixed << setprecision(4) << ans << endl;
    system("pause");
    return 0;
}