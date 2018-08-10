/*************************************************************************
	> File Name: EP37.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 15时18分43秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int is_prime(int x) {
    if (x == 0 || x == 1) return 0;
    for (int n = 2; n * n <= x; n++) {
        if (x % n == 0) return 0;
    }
    return 1;
}

int digit(int n) {
    return floor(log10(n)) + 1;
}

int is_valid(int n) {
    int temp = n / 10;
    while (temp) {
        if (!is_prime(temp)) return 0;
        temp /= 10;
    }
    while(n) {
        int num = digit(n);
        if (!is_prime(n)) return 0;
        n = n % (int)pow(10, num - 1);
    }
    return 1;
}

int main() {
    int n = 0, ans = 0;
    for (int i = 11; i && n < 11; i++) {
        if (!is_prime(i)) continue;
        if (!is_valid(i)) continue;
        ans += i;
        n++;
    }
    printf("%d\n", ans);
    return 0;
}
