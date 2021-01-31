#include <bits/stdc++.h>
using namespace std;

//假设y=x+r1,y=-x+r2
int main()
{
    int n;
    int sum = 0;
    cin >> n;
    int x[1000] = {};
    int y[1000] = {};
    int vis[1000] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
    }
    int r1, r2;
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        r1 = y[i] - x[i]; //任取一个点计算出斜率为1的r1值
        for (int j = 0; j < n; j++)
        {
            tmp = 0;
            r2 = y[j] + x[j]; //任取一个点计算出斜率为-1的r2值
            for (int k = 0; k < n; k++)
            {
                if (x[k] + y[k] == r2 || y[k] - x[k] == r1)
                {
                    tmp++; //统计在这两条上的点
                }
            }
            if (sum < tmp)
            {
                sum = tmp; //记录最大值
            }
        }
    }
    cout << sum << endl;
    system("pause");
    return 0;
}