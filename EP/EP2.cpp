/*************************************************************************
	> File Name: EP2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 14时08分06秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 4000000

int num[3] = {1, 0, 1};

int main() {
    int ans = 0, n = 0;
    while (num[n % 3] <= MAX_N) {
        if(!(num[n % 3] & 1))  ans += num[n % 3];
        n += 1;
        num[n % 3] = num[(n - 1) % 3] + num[(n - 2) % 3];
    }
    printf("%d\n", ans);
    return 0;
}
