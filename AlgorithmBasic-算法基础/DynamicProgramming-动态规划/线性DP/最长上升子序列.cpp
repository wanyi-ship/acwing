//给定一个长度为N的数列，求数值严格单调递增的子序列的长度最长是多少。1<=N<=1000

#include<iostream>

using namespace std;

const int N=1010;

int f[N],a[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n;i++)
    {
        f[i]=1;
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i])f[i]=max(f[i],f[j]+1);
        }
    }

    int res=0;
    for(int i=1;i<=n;i++)res=max(res,f[i]);
    cout<<res;
}