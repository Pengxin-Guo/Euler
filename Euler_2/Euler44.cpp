/*************************************************************************
	> File Name: Euler44.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 16时23分07秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int64_t pentagonal(int64_t n) {
    return n * (3 * n - 1) / 2;
}

int64_t is_valid(int64_t x) {
    int64_t low = 1, high = 1000000000, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (pentagonal(mid) == x) return 1;
        if (pentagonal(mid) > x) high = mid -1;
        else low = mid + 1;
    }
    return 0;
}

int main() {
    int64_t j = 1, k = 1, ans = INT64_MAX;
    while (pentagonal(k + 1) - pentagonal(k) < ans) {
        k += 1;
        j = k - 1;
        while (j >= 1 && pentagonal(k) - pentagonal(j) < ans) {
            if (is_valid(pentagonal(k) + pentagonal(j))) {
                if (is_valid(pentagonal(k) - pentagonal(j))) {
                    if (ans > pentagonal(k) - pentagonal(j)) {
                        ans = pentagonal(k) - pentagonal(j);
                    }
                }
            }
            j--;
        }
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
