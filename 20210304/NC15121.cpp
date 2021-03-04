#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int fa[N];

int find(int x)
{
    return (fa[x] == x ? x : find(fa[x]));
}

void merge(int x, int y)
{
    fa[find(x)] = find(y);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        //唯一变式，必须是学生拥有老师的号码
        //所以当老师知道学生号码时不能使得两人连通
        //所以当a为老师时跳过
        if (a != n)
            merge(a, b);
    }
    if (find(1) == find(n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    system("pause");
    return 0;
}