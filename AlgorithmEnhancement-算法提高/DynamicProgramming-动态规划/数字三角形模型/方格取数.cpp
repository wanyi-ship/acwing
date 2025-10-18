// 设有 N×N 的方格图，我们在其中的某些方格中填入正整数，而其它的方格中则放入数字0。如下图所示：
// 某人从图中的左上角 A 出发，可以向下行走，也可以向右行走，直到到达右下角的 B 点。
// 在走过的路上，他可以取走方格中的数（取走后的方格中将变为数字0）。
// 此人从 A 点到 B 点共走了两次，试找出两条这样的路径，使得取得的数字和为最大。
//
// 输入格式
// 第一行为一个整数N，表示N×N的方格图。
// 接下来的每行有三个整数，第一个为行号数，第二个为列号数，第三个为在该行、该列上所放的数。行和列编号从1开始。
// 一行“0 0 0”表示结束。
//
// 输出格式
// 输出一个整数，表示两条路径上取得的最大的和。
//
// 数据范围
// N≤10

#include <iostream>

using namespace std;

const int N = 15;

int n;
int w[N][N];
int f[2 * N][N][N];

int main() {
    cin >> n;
    while (1) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;
        w[a][b] = c;
    }
    
    for (int k = 1; k <= 2 * n; k ++ ) {
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                int x1 = i, y1 = k - i;
                int x2 = j, y2 = k - j;
                if (y1 < 1 || y1 > n || y2 < 1 || y2 > n) continue;

                int val = w[x1][y1];
                if (x1 != x2) val += w[x2][y2];

                int &x=f[k][i][j];
                x=max(x,f[k-1][i-1][j-1]+val);
                x=max(x,f[k-1][i][j-1]+val);
                x=max(x,f[k-1][i-1][j]+val);
                x=max(x,f[k-1][i][j]+val);
            }
        }
    }
    cout << f[2 * n][n][n] << endl;
    return 0;
}