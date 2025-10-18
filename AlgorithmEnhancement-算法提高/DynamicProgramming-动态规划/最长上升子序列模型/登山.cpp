// 五一到了，ACM队组织大家去登山观光，队员们发现山上一共有N个景点，并且决定按照顺序来浏览这些景点，即每次所浏览景点的编号都要大于前一个浏览景点的编号。
// 同时队员们还有另一个登山习惯，就是不连续浏览海拔相同的两个景点，并且一旦开始下山，就不再向上走了。
// 队员们希望在满足上面条件的同时，尽可能多的浏览景点，你能帮他们找出最多可能浏览的景点数么？

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int h[N];
int f[N], g[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &h[i]);

    for (int i = 0; i < n; i ++ )
    {
        f[i] = 1;
        for (int j = 0; j < i; j ++ )
            if (h[i] > h[j])
                f[i] = max(f[i], f[j] + 1);
    }

    for (int i = n - 1; i >= 0; i -- )
    {
        g[i] = 1;
        for (int j = n - 1; j > i; j -- )
            if (h[i] > h[j])
                g[i] = max(g[i], g[j] + 1);
    }

    int res = 0;
    for (int i = 0; i < n; i ++ ) res = max(res, f[i] + g[i] - 1);

    printf("%d\n", res);

    return 0;
}