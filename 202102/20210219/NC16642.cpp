#include <bits/stdc++.h>
using namespace std;

//大数运算模拟，摘自https://ac.nowcoder.com/acm/contest/profile/827921411大佬
void trunc_zero(vector<int> &num)
{
    while (num.empty() == false && num.back() == 0)
    {
        num.pop_back();
    }
}

class Big_uint
{
    friend ostream &operator<<(ostream &os, Big_uint const &a);
    vector<int> digits;

public:
    Big_uint(string const &str)
    {
        digits.resize(str.size());
        auto i = digits.begin();
        auto ed = digits.end();
        auto j = str.rbegin();
        while (i != ed)
        {
            *i++ = *j++ - '0';
        }
    }
    Big_uint(vector<int> &&n) : digits(n) {}

    Big_uint operator*(int const a) const
    {
        vector<int> num(digits.size() + 10, 0);
        size_t i = 0;
        for (; i < digits.size(); ++i)
        {
            num[i] += digits[i] * a;
            if (num[i] >= 10)
            {
                num[i + 1] += num[i] / 10;
                num[i] %= 10;
            }
        }
        while (num[i] >= 10)
        {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
            ++i;
        }
        trunc_zero(num);
        return {std::move(num)};
    }
    Big_uint &operator-=(int const a)
    {
        digits[0] -= a;
        size_t i = 0;
        while (digits[i] < 0)
        {
            digits[i] += 10;
            --digits[++i];
        }
        trunc_zero(digits);
        return *this;
    }
};

ostream &operator<<(ostream &os, Big_uint const &a)
{
    if (a.digits.empty())
    {
        os << '0';
    }
    else
    {
        auto i = a.digits.rbegin(), j = a.digits.rend();
        while (i != j)
        {
            os << *i++;
        }
    }
    return os;
}

int main()
{
    int n;
    cin>>n;
    Big_uint ans("2");
    //使用前面的递推式an=2^n+1-2,大数模拟运算就是解决n>=64时超过了long long int后计算结果输出的问题
    for(int i=0;i<n;i++){
        ans=ans*2;
    }
    ans-=2;
    cout<<ans<<endl;
    system("pause");
    return 0;
}