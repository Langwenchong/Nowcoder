#include <bits/stdc++.h>
using namespace std;

int solve(int N)
{
    int n = sqrt(N);
    int flag = 1;
    for (int i = 2; i <= n; i++)
    {
        if (N % i == 0)
        {
            flag = 0;
            break;
        }
    }
    //如果字数就是质数
    if (flag)
        //一块钱就行
        return 1;
    flag = 1;
    //如果是合数且是9,49这种减去一个2后就变成了质数，那么就两块钱
    for (int i = 2; i <= n; i++)
    {
        if ((N - 2) % i == 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag || N % 2 == 0)
        return 2;
    //否则像51这种合数，需要减去2个2才能变成质数，就需要三块钱，没有其他情况了
    return 3;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}