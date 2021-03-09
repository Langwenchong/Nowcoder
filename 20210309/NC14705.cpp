#include <bits/stdc++.h>
using namespace std;

int a[105];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    //甜度
    int tmp = 0;
    //次数
    int ans = 0;
    int j = 1;
    while (j <= n)
    {
        tmp += a[j];
        //甜度大于m了，说明不吃j时是本次可以吃的最大程度
        if (tmp > m)
        {
            //将第j个甜品吐出来不吃可以承受
            tmp -= a[j];
            //tmp归零为下一次吃初始化
            tmp = 0;
            //吃的次数+1
            ans++;
            //j就不加了，因为j还没吃呢
            continue;
        }
        j++;
    }
    //坑点，如果最后一次吃完还没到最大承受度
    //那么也算一次吃了
    if (tmp != 0)
        ans++;
    cout << ans << endl;
    system("pause");
    return 0;
}