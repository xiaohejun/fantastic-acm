#include <stdio.h>
#include <stdlib.h>
/*
下标从1开始
------------|---------|---------
            x         y
[1, x) <= [x, y) <= [y, n]
2 <= x < y <= n
2 <= x <= n-1
3 <= y <= n
x < y
枚举y,当y固定，求满足的x的最小值位置是i,最大值位置是j，方案贡献(j - i + 1)
----|------------------|---------
    i                  y

-----------------|-----|---------
                 j     y
y向右移动一格
[y+1, n] 变小

*/

// get sum [begin, end)
int sumRange(int *sum, int begin, int end)
{
    return sum[end - 1] - sum[begin - 1];
}

int leftBinary(int *sum, int begin, int end, int rightSum)
{
    int l = begin;
    int r = end - 1;
    int ans = -1;
    int leftSum, midSum;
    while (l <= r) {
        int mid = (l + r) >> 1;
        leftSum = sumRange(sum, 1, mid);
        midSum = sumRange(sum, mid, end);
        if (leftSum <= midSum) {
            if (midSum <= rightSum) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int rightBinary(int *sum, int begin, int end, int rightSum)
{
    int l = begin;
    int r = end - 1;
    int ans = -1;
    int leftSum, midSum;
    while (l <= r) {
        int mid = (l + r) >> 1;
        leftSum = sumRange(sum, 1, mid);
        midSum = sumRange(sum, mid, end);
        if (leftSum <= midSum) {
            if (midSum <= rightSum) {
                ans = mid;
            }
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int waysToSplit(int* a, int n){
    const int MOD = 1e9 + 7;
    int *sum = malloc(sizeof(int) * (n + 1));
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + a[i];
    }
    int ans = 0;
    for (int y = 3; y <= n; ++y) {
        //printf("y=%d\n", y);
        int rightSum = sumRange(sum, y, n + 1);
        int lMin = leftBinary(sum, 2, y, rightSum);
        //printf("lMin=%d\n", lMin);
        int lMax = rightBinary(sum, 2, y, rightSum);
        //printf("lMax=%d\n", lMax);
        if (lMin != -1 && lMax != -1) {
            ans = (ans + (lMax - lMin + 1)) % MOD;
        }
    }   
    free(sum);
    return ans;
}

/*
7,2,5,5,6,2, 10,9

3 (-1, -1)
4 (2, 2) 1
5 (2, 3) 2
6 (2, 3) 2
7 (3, 3) 1

*/

int main()
{
    int a[] = {7,2,5,5,6,2,10,9};
    printf("return ans = %d", waysToSplit(a, sizeof(a)/ sizeof(a[0])));
}
/*
7,2,5,5,6,2, 10,9

3 (-1, -1)
4 (2, 2) 1
5 (2, 3) 2
6 (2, 3) 2
7 (3, 3) 1

*/