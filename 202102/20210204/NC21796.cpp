//参考了大佬的代码，这里给出几个知识点：
// rfind从字符串a末尾开始寻找包含字符串b的第一个位置，没有就返还::npos
// substr(i,j)截取字符串c的起始位置i到结束位置j的部分子串
#include <bits/stdc++.h>
using namespace std;
string arr[5];
void work(string &a, string b)
{
    if (a.find(b) != string::npos)
        return; //a中包含b,不用拼接了
    for (int i = b.size() - 1; i >= 0; i--)
    {
        if (a.rfind(b.substr(0, i)) != string::npos && a.rfind(b.substr(0, i)) == a.size() - i) //a的后缀等于b的前缀
        {
            a += b.substr(i, b.size() - i); //a加上b前缀之外的部分
            break;
        }
    }
}

int main()
{
    for (int i = 0; i < 4; i++)
        cin >> arr[i];
    int r = 60; //随便设一个必定大于最短公共串长度的数字
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                for (int l = 0; l < 4; l++)
                {
                    if (i == j || i == k || i == l || j == k || j == l || k == l)
                    {
                        //如果是这种情况，那么没有选出4个不同的直接跳过字符串
                        continue;
                    }
                    //应该一共会有4！个情况
                    string tmp = arr[i];
                    //tmp分别和另外三个比较寻找，tmp是最开始的串，其他的拼到后面
                    work(tmp, arr[j]);
                    work(tmp, arr[k]);
                    work(tmp, arr[l]);           //暴力，把每种组合都试一遍//题目说了只有4个串，其实也可以写4个循环
                    r = min(r, (int)tmp.size()); //必须要把长度化为整型
                }
            }
        }
    }
    cout << r << endl;
    system("pause");
    return 0;
}