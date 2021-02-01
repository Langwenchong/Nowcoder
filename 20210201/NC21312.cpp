#include <bits/stdc++.h>
using namespace std;

const int N = 55; //一次性开到最大的数组
int n, m, budget; //天数，每天的菜品数量
string s[N];      //存储一天的各个菜品价格的字符串数组
int meat[7][N];   //星期i选择第j份菜品的总花费
int cost[7];      //已知的最便宜的菜品花费

int main()
{
    cin >> n >> m >> budget;
    for (int i = 0; i < n; i++)
    {
        //记录数据并且计算出每一个字符所代表的的相对应的第i天第j份菜品的费用
        cin >> s[i];
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] >= '0' && s[i][j] <= '9')
                s[i][j] = s[i][j] - '0';
            if (s[i][j] >= 'A' && s[i][j] <= 'Z')
                s[i][j] = s[i][j] - 'A' + 10;
            if (s[i][j] >= 'a' && s[i][j] <= 'z')
                s[i][j] = s[i][j] - 'a' + 36;
        }
    }
    //已知的最省钱的花费
    int money = 0;
    //统计n天的最多吃饭次数
    for (int i = 0; i < n; i++)
    {
        //计算前先减掉这次菜品组合，比如样例2中的星期1我们
        //优先选择了花费小的菜品1(即此时会吃两次菜品2花费分别是（2,9），那么现在到了第8天即又到
        //了周一我们假设现在有更好的更省钱的菜品组合（后面确实有更好的即周一时选择菜品2（6,1），
        //所以减去之前的花费（2,9）重新统计星期i的选餐组合
        money -= cost[i % 7];
        for (int j = 0; j < m; j++)
        {
            //统计选择了第j件菜品时所有吃第j个菜品的花费
            meat[i % 7][j] += s[i][j];
        }
        //假设选择每天的第一个菜品吃最省钱
        cost[i % 7] = meat[i % 7][0];
        for (int j = 1; j < m; j++)
        {
            //统计若选择吃第j件菜品是否比选择吃第1件菜品更省钱
            cost[i % 7] = min(cost[i % 7], meat[i % 7][j]);
            //保证每一次选择的都一定是一直当前的最省钱组合
        }

        money += cost[i % 7];

        if (money > budget)
        {
            //在餐厅关闭前花完钱了，那么返还吃了几次
            cout << i << endl;
            system("pause");
            return 0;
        }
    }
    //如果花完钱之前餐厅关闭了，那么必定每天都吃了一次，返还n
    cout << n << endl;
    system("pause");
    return 0;
}