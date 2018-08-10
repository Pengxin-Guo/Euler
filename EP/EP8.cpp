/*************************************************************************
	> File Name: EP8.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 15时43分04秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include "8.h"
#define MAX_N 1000

int main() {
    int64_t ans = 0, zero = 0, p = 1;
    for (int64_t i = 0; i < MAX_N; i++) {
        if (num[i] == '0') zero += 1;
        else p *= (num[i] - '0');
        if (i >= 13) {
            if (num[i - 13] == '0') {
                zero -= 1;
            }
            else {
                p /= (num[i - 13] - '0');
            }
        }
        if (zero == 0 && ans < p) ans = p;
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
