/*************************************************************************
	> File Name: Euler15.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 12时03分19秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int main() {

    int64_t num[22][22] = {0};
    for (int i = 1; i < 22; i++) {
        for (int j = 1; j < 22; j++) {
            if (i == 1 && j == 1) num[i][j] = 1;
            else num[i][j] = num[i - 1][j] + num[i][j - 1];
        }
    }
    printf("%" PRId64 "\n",num[21][21]);

    int64_t ans = 1, m = 20;
    for (int i = 40; i > 20; i--) {
        ans *= i;
        while (ans % m == 0 && m != 1) {
            ans /= m;
            m--;
        }
    }
    printf("%" PRId64 "\n", ans);
}
