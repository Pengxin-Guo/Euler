/*************************************************************************
	> File Name: Euler44_2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 17时13分57秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <math.h>
#define MAX_N 1000000

int64_t is_cublic(int64_t n) {
    int64_t low = 1, high = MAX_N, mid;
    while (low <= high) {
        mid = (low + high) >> 1;
        if (pow(mid, 3) == n) return 1;
        if (pow(mid, 3) < n) low = mid + 1;
        else high = mid - 1;
    }
    return 0;
}

int main() {
    int64_t n;
    while (scanf("%" PRId64,&n) != EOF) {
        printf("%" PRId64 " %s cublic\n", n, is_cublic(n) ? "is" : "is not");
    }
    return 0;
}
