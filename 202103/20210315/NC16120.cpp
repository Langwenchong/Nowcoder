#include <bits/stdc++.h>
using namespace std;

bool v[1000009];
int a[100005];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        //存入数列
        cin >> a[i];
    }
    //枚举打表
    //初始位置从i开始
    for (int i = 1; i <= n; i++)
    {
        //子数列长度最大也就到6了，再长表示不出来了
        for (int l = 1; l <= 6; l++)
        {
            int ans = 0;
            //j最长只能到n和i+l-1的最小值，即可能j到不了n，如果超出n了那么就停止
            for (int j = i; j <= min(n, i + l - 1); j++)
            {
                ans = ans * 10 + a[j];
            }
            v[ans] = 1;
        }
    }
    for (int i = 0; i <= 1e6; i++)
    {
        //找道第一个表示不出来的数
        if (!v[i])
        {
            cout << i << endl;
            system("pause");
            return 0;
        }
    }
}