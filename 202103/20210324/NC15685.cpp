#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int fa[maxn];
//板子
int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

void merge(int x, int y)
{
    int i = find(x);
    int j = find(y);
    fa[i] = j;
}

int main()
{
    //初始化，默认每一个孤立点都是一个连通块
    for (int i = 0; i < maxn; i++)
    {
        fa[i] = i;
    }
    int n, m;
    cin >> n >> m;
    //合并
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }
    int ans = 0;
    //统计连通块个数，属于同一个i的是一个连通块
    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
            ans++;
    }
    //需要ans-1个边
    cout << ans - 1 << endl;
    system("pause");
    return 0;
}