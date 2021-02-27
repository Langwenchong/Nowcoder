#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, n, j = 1;
    cin >> n;
    cin >> a;
    for (int i = 1; i < n; i++)
    {
        cin >> b;
        //找出所有小于mei积分的人数
        if (b <= a)
            j++;
    }
    //最后求出取2对数的向下取整即为答案，小美可以进行的最多轮数
    cout << (int)log2(j) << endl;
    system("pause");
    return 0;
}