#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int x, y, n, m, ans;
//win[i][j]==1表示i赢了j
//lose[i][j]==1表示i输给了j
int win[N][N], lose[N][N];

int main()
{
    cin >> n >> m;
    while (m--)
    {
        //存入x，y一定是x赢y
        cin >> x >> y;
        win[x][y] = lose[y][x] = 1;
    }
    //floyd算法模拟并查集思想
    //这里不适用并查集是因为并查集记录的都是节点A和节点B是否具有共同祖先节点的关系来间接表示A和B的关系
    //但是这里只是用来记录两个相邻节点A,B的直接关系
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
        {
            //当i和k相同时跳过
            if (i == k)
                continue;
            for (int j = 1; j <= n; j++)
            {
                //同理i==j或者j==k也跳过总之就是必须是三头不同的牛
                if (i == j || j == k)
                    continue;
                //i赢了j当前仅当i赢了k且k赢了j，一定要注意这里是取或
                win[i][j] |= (win[i][k] && win[k][j]);
                //i输给j当且仅当i输给k且k输给j
                lose[i][j] |= (lose[i][k] && lose[k][j]);
            }
        }
    for (int i = 1; i <= n; i++)
    {
        int num = 0;
        for (int j = 1; j <= n; j++)
            //统计i赢的场数和输的场数
            num += win[i][j] + lose[i][j];
        //如果刚好和为n-1，表示排名先于i的人数和排名落后于i的人数之和为n-1，那么随之i的排名就确定了
        //可以用排队来理解，已知5个人，A前面有3个人，后面有1个人，那么就确定了A位于从前往后数第4个
        if (num == n - 1)
            ans++;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}