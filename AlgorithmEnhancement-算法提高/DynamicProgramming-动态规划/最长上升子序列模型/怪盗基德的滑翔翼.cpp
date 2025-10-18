// 怪盗基德是一个充满传奇色彩的怪盗，专门以珠宝为目标的超级盗窃犯。
// 而他最为突出的地方，就是他每次都能逃脱中村警部的重重围堵，而这也很大程度上是多亏了他随身携带的便于操作的滑翔翼。
// 有一天，怪盗基德像往常一样偷走了一颗珍贵的钻石，不料却被柯南小朋友识破了伪装，而他的滑翔翼的动力装置也被柯南踢出的足球破坏了。
// 不得已，怪盗基德只能操作受损的滑翔翼逃脱。
// 假设城市中一共有N幢建筑排成一条线，每幢建筑的高度各不相同。
// 初始时，怪盗基德可以在任何一幢建筑的顶端。
// 他可以选择一个方向逃跑，但是不能中途改变方向（因为中森警部会在后面追击）。
// 因为滑翔翼动力装置受损，他只能往下滑行（即：只能从较高的建筑滑翔到较低的建筑）。
// 他希望尽可能多地经过不同建筑的顶部，这样可以减缓下降时的冲击力，减少受伤的可能性。
// 请问，他最多可以经过多少幢不同建筑的顶部(包含初始时的建筑)？

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int h[N];
int f[N];

int main()
{
    int T;
    scanf("%d", &T);
    while (T -- )
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++ ) scanf("%d", &h[i]);

        int res = 0;
        for (int i = 0; i < n; i ++ )
        {
            f[i] = 1;
            for (int j = 0; j < i; j ++ )
                if (h[i] < h[j])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }

        memset(f, 0, sizeof f);
        for (int i = n - 1; i >= 0; i -- )
        {
            f[i] = 1;
            for (int j = n - 1; j > i; j -- )
                if (h[i] < h[j])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }

        printf("%d\n", res);
    }

    return 0;
}