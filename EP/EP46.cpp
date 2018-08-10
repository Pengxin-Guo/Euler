/*************************************************************************
	> File Name: EP46.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 14时26分48秒
 ************************************************************************/

#include <stdio.h>

int is_prime(int x) {
    for (int n = 2; n * n < x; n++) {
        if (x % n == 0) return 0;
    }
    return 1;
}

int main() {
    for (int i = 3; i; i += 2) {
        if (is_prime(i)) continue;
        int flag = 1;
        for (int j = 1; 2 * j * j < i && flag; j++) {
            if (is_prime(i - 2 * j * j)) flag = 0;
        }
        if (flag) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
