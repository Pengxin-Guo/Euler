/*************************************************************************
	> File Name: EP3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 14时17分47秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int main() {
    int64_t n = 2, ans, num = 600851475143;
    while (n * n < num) {
        if (num % n == 0) ans = n;
        while (num % n == 0) num /= n;
        n++;
    }
    if (num != 1) ans = num;
    printf("%" PRId64 "\n", ans);
    return 0;
}
