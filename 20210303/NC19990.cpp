#include <bits/stdc++.h>
using namespace std;

//volum[i][j]表示的是在i此表演后能否到达音量j
//如果为1表示可以到达
//0表示无法到达
int volum[105][1005];

int main()
{
    int n, b, m;
    cin >> n >> b >> m;
    //未开始演出时可以到达初始音量，所以置为1
    volum[0][b] = 1;
    for (int i = 1; i <= n; i++)
    {
        //对于每一次的音量调节大小x
        int x;
        cin >> x;
        //注意枚举表演i首后能否到达音量j
        //因为还是二维0/1dp没有降维，所以j正序逆序都可以
        for (int j = 0; j <= m; j++)
        {
            //当且仅当j+x没有超出最大音量，且在表演i-1次后音量可以到达j时
            //表演第i首歌以后才可以到达j+x音量
            if (j + x <= m && volum[i - 1][j])
                volum[i][j + x] = 1;
            //当且仅当jxx没有超出最小音量，且在表演i-1次后音量可以到达j时
            //表演第i首歌以后才可以到达j-x音量
            if (j - x >= 0 && volum[i - 1][j])
                volum[i][j - x] = 1;
        }
    }
    //但是注意最终要求的是寻找表演n次后可以到达的最大音量
    //所以此时i必须为逆序的
    for (int i = m; i >= 0; i--)
    {
        //一定是volum[n][i]因为必须表演完n次
        if (volum[n][i])
        {
            //第一个出现的1值就是可以到达的最大音量
            //输出这个最大音量i即可
            cout << i << endl;
            system("pause");
            return 0;
        }
    }
    //如果整个第n行都是0，说明无法表演完n首歌，所以输出-1
    cout << "-1" << endl;
    system("pause");
    return 0;
}