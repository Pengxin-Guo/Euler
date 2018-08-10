/*************************************************************************
	> File Name: Euler8.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 11时25分17秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
//#include "Euler8.h"

int main() {
    int64_t ans = 0, p = 1, zero = 0;
    char num[1005] = {0}, temp[1005] = {0};
    while(scanf("%s",temp) != EOF) {
        strcat(num, temp);
    }
    for (int i = 0; num[i]; i++) {
        if (num[i] == '0') {
            zero += 1;
        } else {
            p *= (num[i] - '0');
        }
        if (i >= 13) {
            if (num[i - 13] == '0') {
                zero -= 1;
            } else {
                p /= (num[i - 13] - '0');
            }
        }
        if (ans < p && zero == 0) ans = p;
    }
    printf("%" PRId64 "\n",ans);
    return 0;
}
