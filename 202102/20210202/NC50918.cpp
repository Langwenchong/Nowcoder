#include <bits/stdc++.h>
using namespace std;
int n, m, answer[30];

void dfs(int start, int num)
{
    if (num == m + 1)
    //到达了叶子节点就是一组解输出
    {
        for (int i = 1; i <= m; i++)
            cout << answer[i] << " ";
        cout << endl;
        return;
    }
    if (start > n)
    //数值超出1~n范围了，退出
        return;
    //这个值
    answer[num] = start;
    //以这个节点的下一位为起点开始搜索
    dfs(start + 1, num + 1);
    //没有选这个节点，继续搜索
    dfs(start + 1, num);
}
int main()
{
    cin >> n >> m;
    //根节点就是从1开始
    dfs(1, 1);
    system("pause");
    return 0;
}