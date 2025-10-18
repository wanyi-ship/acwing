// 给定一个长度为N的数列，求数值严格单调递增的子序列的长度最长是多少。1<=N<=100000
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int a[N];
int q[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    int len = 0;
    for (int i = 0; i < n; i ++ )
    {
        int l = 1, r = len + 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] >= a[i]) r = mid;
            else l = mid + 1;
        }
        len = max(len, l);
        q[l] = a[i];
    }

    printf("%d\n", len);

    return 0;
}