/*************************************************************************
	> File Name: EP44.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 15时49分22秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
int64_t pentagonal(int64_t n) {
    return n * (3 * n - 1) / 2;
}

int is_valid(int x, int n) {
    int low = 0, high = n, mid;
    while (low <= high) {
        mid = (low + high) >> 1;
        if (pentagonal(mid) == x) return 1;
        if (pentagonal(mid) > x) high = mid - 1;
        else low = mid + 1;
    }
    return 0;
}

int main() {
    int64_t k = 1, j = 2;
    int64_t ans = INT64_MAX;
    while (pentagonal(j) - pentagonal(j - 1) < ans) {
        k = j - 1;
        while (k > 0 && pentagonal(j) - pentagonal(k) < ans) {
            if (is_valid(pentagonal(j) + pentagonal(k), 2 * j)) {
                if (is_valid(pentagonal(j) - pentagonal(k), j)) {
                    ans = pentagonal(j) - pentagonal(k);
                    // printf("%" PRId64 "\n", ans);
                }
            }
            k--;
        }
        j++;
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
