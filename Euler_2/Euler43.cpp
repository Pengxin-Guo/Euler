/*************************************************************************
	> File Name: Euler43.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 16时18分24秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int64_t is_pandigital(int64_t x) {
    int num[11] = {0};
    while (x) {
        if (num[x % 10]) return 0;
        num[x % 10] = 1;
        x /= 10;
    }
    return 1;
}

int64_t is_digits(int64_t x) {
    int num[11] = {0}, n = 10;
    for (int i = 10; i > 0; i--) {
        num[i] = x % 10;
        x /= 10;
    }
    for (int i = 1; i <= 10; i++) {
        printf("%d ",num[i]);
    }
    printf("\n");
    if ((num[2] * 100 + num[3] * 10 + num[4]) % 2) return 0;
    if ((num[3] * 100 + num[4] * 10 + num[5]) % 3) return 0;
    if ((num[4] * 100 + num[5] * 10 + num[6]) % 5) return 0;
    if ((num[5] * 100 + num[6] * 10 + num[7]) % 7) return 0;
    if ((num[6] * 100 + num[7] * 10 + num[8]) % 11) return 0;
    if ((num[7] * 100 + num[8] * 10 + num[9]) % 13) return 0;
    if ((num[8] * 100 + num[9] * 10 + num[10]) % 17) return 0;
    return 1;
}

int main() {
    int64_t ans = 0;
    for (int64_t i = 1023456789; i <= 9876543210; i++) {
        if (!is_pandigital(i)) continue;
        if (!is_digits(i)) continue;
        ans += i;
        printf("%" PRId64 "\n",i);
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
