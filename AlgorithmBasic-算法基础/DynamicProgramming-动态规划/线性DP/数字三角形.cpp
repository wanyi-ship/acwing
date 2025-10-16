// 给定一个如下图所示的数字三角形，从顶部出发，在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点，一直走到底层，要求找出一条路径，使路径上的数字的和最大。
//         7
//       3   8
//     8   1   0
//   2   7   4   4
// 4   5   2   6   5
// 输入格式
// 第一行包含整数n,表示数字三角形的层数。

// 接下来n行,每行包含若干整数,其中第i行表示数字三角形第i层包含的整数。

// 输出格式
// 输出一个整数，表示最大的路径数字和。

// 数据范围
// 1≤n≤500,
// −10000≤三角形中的整数≤10000


#include <iostream>

using namespace std;

const int N=510;
int f[N][N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>f[i][j];

    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
            if(j==1)f[i][j]=f[i-1][j]+f[i][j];
            else if(j==i)f[i][j]=f[i-1][j-1]+f[i][j];
            else f[i][j]=f[i][j]+max(f[i-1][j-1],f[i-1][j]);

    int res=-1e9;
    for(int i=1;i<=n;i++)res=max(res,f[n][i]);
    cout<<res<<endl;
}