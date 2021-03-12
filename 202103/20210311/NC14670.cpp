#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
int a[N];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,s;
        cin>>n>>k>>s;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        //排序
        sort(a+1,a+1+n);
        int i=n;
        int ans=0;
        //每一个桶的最小高度分别是下面的i
        for(int i=n-k+1;i>=1;i-=k){
            ans+=a[i]*s;
        }
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}