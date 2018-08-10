/*************************************************************************
	> File Name: EP45.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 16时12分03秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int64_t pentagonal(int64_t n) {
    return n * (3 * n - 1) / 2;
}

int64_t hexagonal(int64_t n) {
    return n * (2 * n - 1);
}

int64_t binary_search(int64_t (*func)(int64_t), int64_t n, int64_t x) {
    int64_t low = 0, high = n, mid;
    while (low <= high) {
        mid = (low + high) >> 1;
        if (func(mid) == x) return mid;
        if (func(mid) > x) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main() {
    int64_t n = 144;
    while (binary_search(pentagonal, 2 * n, hexagonal(n)) == -1) n++;
    printf("%" PRId64 "\n", hexagonal(n));
    return 0;
}
