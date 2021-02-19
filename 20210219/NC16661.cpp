#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    //获取火星人的手指排列顺序
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //m次全排列后就是要输出的结果（就是字典序排列）
    for (int i = 0; i < m; i++)
    {
        next_permutation(a, a + n);
    }
    //输出结果
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}