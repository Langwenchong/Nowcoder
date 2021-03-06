#include <bits/stdc++.h>
using namespace std;

//分别记录最大收益，物品重量，物品价值，物品所属组号
int dp[1005], w[1005], v[1005], g[1005];
using namespace std;
int main()
{
	int n, m;
	cin >> m >> n;
	int group = -1;
	for (int i = 1; i <= n; ++i)
	{
		cin >> w[i] >> v[i] >> g[i];
		group = max(group, g[i]);
	}
	//现规定本次所要打印的是第几组的物品
	for (int i = 1; i <= group; ++i)
	{
		//注意在分组背包中先讨论容量，在讨论物品，这是一个特殊顺序
		//可以保证每一个组只会选择一个物品
		//具体缘由见背包九讲
		//然后j逆序打印降维
		for (int j = m; j >= 0; --j)
		{
			//物品枚举范围正序
			for (int k = 1; k <= n; ++k)
			{
				//不是所要组号或者装不下跳过
				if (g[k] != i || j < w[k])
					continue;
				//否则更新值
				dp[j] = max(dp[j], dp[j - w[k]] + v[k]);
			}
		}
	}
	cout << dp[m] << endl;
	system("pause");
	return 0;
}

