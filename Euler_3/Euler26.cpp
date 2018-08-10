/*************************************************************************
	> File Name: Euler26.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 10时03分35秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_N 1000

int dnum[MAX_N + 5] = {0};

int get_length(int d) {
    int n = 0, y = 1;
    memset(dnum, 0, sizeof(dnum));
    while (y != 0 && dnum[y] == 0) {
        dnum[y] = n;
        y = y * 10 % d;
        n += 1;
    }
    return y ? n - dnum[y] : 0;
}


int main() {
    int ans = 0, length = 0;
    for (int d = 2; d < MAX_N; d++) {
        if (length < get_length(d)) {
            length = get_length(d);
            ans = d;
        }
    }
    printf("%d\n", ans);
    return 0;
}
