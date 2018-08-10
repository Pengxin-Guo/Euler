/*************************************************************************
	> File Name: Euler45.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 09时49分33秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int64_t triangle(int64_t n) {
    return n * (n + 1) / 2;
}

int64_t pentagonal(int64_t n) {
    return n * (3 * n - 1) / 2;
}

int64_t hexagonal(int64_t n) {
    return n * (2 * n - 1);
}

int binary_search(int64_t (*num)(int64_t), int64_t n, int64_t x) {
    int64_t low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) >> 1;
        if (num(mid) == x) return mid;
        if (num(mid) < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int64_t n = 144;
    while (binary_search(pentagonal, 2 * n, hexagonal(n)) == -1) n++;
    printf("%" PRId64 "\n", hexagonal(n));
    return 0;
}
