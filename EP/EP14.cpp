/*************************************************************************
	> File Name: EP14.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 16时03分41秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define MAX_N 1000000

int selength[MAX_N + 5] = {0};

int sequ_length(int64_t i) {
    if (i == 1) return 1;
    if (i <= MAX_N && selength[i]) return selength[i];
    int temp;
    if (i & 1) temp = sequ_length(3 * i + 1) + 1;
    else temp = sequ_length(i / 2) + 1;
    if (i <= MAX_N) selength[i] = temp;
    return temp;
}

int main() {
    int ans = 0, length = 0;
    for (int i = 1; i < MAX_N; i++) {
        if (length < sequ_length(i)) {
            length = sequ_length(i);
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
