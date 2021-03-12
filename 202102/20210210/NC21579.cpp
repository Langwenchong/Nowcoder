#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    //以字符串形式存入
    char s[2505];
    //结果初始化为1
    int sum = 1;
    cin >> s;
    //声明一个栈p
    stack<char> p;
    //先放入一个左括号
    p.push(s[0]);
    //剩下的位置进行检验
    for (int i = 1; i < strlen(s); i++)
    {
        //如果是左括号就加入栈中
        if (s[i] == '(')
        {
            p.push(s[i]);
        }
        else
        {
            //如果是右括号，那么他可以与栈中的任意一个左括号相抵消，所以可选择的方法数就是此时栈中左括号的数量
            sum = (sum * p.size()) % mod;
            //因为抵消了一个左括号，所以栈中弹出一个左括号，数量减一
            p.pop();
        }
    }
    cout << sum << endl;
    system("pause");
    return 0;
}