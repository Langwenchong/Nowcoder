#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int x;
    while (T--)
    {
        cin >> x;
        bool flag = true;
        vector<int> ans;
        //i从2到根号x枚举检验
        int n = sqrt(x);
        for (int i = 2; i <= n; ++i)
        {
            //如果当前的最小i是因子，那么就一定是质因子
            if (x % i == 0)
            {
                flag = false;
                ans.push_back(i);
                //关键步骤，循环除去i，这样保证下一个因子仍然是质因子
                while (x % i == 0)
                    x /= i;
            }
            //退出代码，不要忘记
            if (x == 1)
                break;
        }
        if (flag)
        {
            cout << "isprime" << endl;
            cout << x << endl;
        }
        else
        {
            cout << "noprime" << endl;
            for (int i = 0; i < ans.size() - 1; ++i)
            {
                cout << ans[i] << " ";
            }
            cout << ans.back();
            if (x != 1)
                //注意最后一个质因子没有存到答案数组中
                //比如10，那么i从2到根号10
                //i无法检验到5，所以10/2=5最后一个质因子5还赋值在x上，未存储到答案数组中
                cout << " " << x;
            cout << endl;
        }
    }
    system("pause");
    return 0;
}