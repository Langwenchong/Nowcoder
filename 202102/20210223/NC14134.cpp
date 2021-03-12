#include <bits/stdc++.h>
using namespace std;

int p[505]; //记录各个点的边数

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        //两个点各加一条边
        p[u]++;
        p[v]++;
    }
    //对1到n顶点排序，按照边数从小到大排序
    sort(p + 1, p + n + 1);
    int min = p[1];
    int max = p[n];
    //非法的几种情况
    //1.有的点无边相连，孤立点，非法
    //2.中心点边数大于4
    //3.X,Y中心点都有，或者有多个X中心点
    //4.有多个Y中心点
    if (min == 0 || max > 4 || (max == 4 && p[n - 1] >= 3) || (max == 3 && p[n - 1] >= 3))
    {
        cout << "NotValid" << endl;
        system("pause");
        return 0;
    }
    else
    {
        //否则就是X,Y,I中的一个
        if (max == 4)
            cout << "X" << endl;
        else if (max == 3)
            cout << "Y" << endl;
        else
            cout << "I" << endl;
    }
    system("pause");
    return 0;
}