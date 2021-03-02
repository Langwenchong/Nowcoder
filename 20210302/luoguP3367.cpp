#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int fa[N];
//寻找祖先板子
int find(int x)
{
    return (fa[x] == x ? x : fa[x] = find(fa[x]));
}
//合并板子
void merge(int x, int y)
{
    fa[find(x)] = find(y);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    while (m--)
    {
        int a, b, z;
        cin >> z >> a >> b;
        if (z == 1)
        {
            merge(a, b);
        }
        else if (z == 2)
        {
            //核心代码
            if (find(a) == find(b))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
        else
        {
            //注意排除报错情况
            cout << "Error!" << endl;
            system("pause");
            return 0;
        }
    }
    system("pause");
    return 0;
}