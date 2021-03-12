#include <bits/stdc++.h>
using namespace std;

int a[55] = {};

struct enemy
//定义敌人结构体数组
{
    //敌人的战斗力
    int power;
    //power战斗力的人数
    long long num;
} b[55];

bool cmp(enemy x, enemy y)
{
    //重置比较规则为将敌人按照战斗力从小到大排序
    return x.power < y.power;
}

int main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    //将我方按战斗力从小到大排序
    sort(a + 1, a + 1 + n);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i].power;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i].num;
    }
    //排序
    sort(b + 1, b + 1 + m, cmp);
    //敌方人数，我方中比敌方战斗力大的人，平均值
    long long sum = 0, s = 0, exper = -1;
    if (a[n] < b[m].power)
    //我方最强都打不过敌方直接退出
        cout << "-1" << endl;
    else
    {
        for (int i = m; i > 0; i--)
        {
            //每次都加上之前的敌人数量重新算平均经验值
            sum += b[i].num;
            //lower——bound返还不小于敌方战斗力的我方伙伴
            s = n + 1 - (lower_bound(a + 1, a + 1 + n, b[i].power) - a);
            //如果刚好平均分配
            if (sum % s == 0)
            {
                //记录平均数大的
                exper = max(exper, sum / s);
            }
            else
            {
                //如果不能平均分配，那么要+1
                exper = max(exper, sum / s + 1);
            }
        }
        cout << exper << endl;
    }
    system("pause");
    return 0;
}