/*************************************************************************
	> File Name: Euler14.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 15时44分26秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define MAX_N 1000000
#define KEEP_RANGE 2000000

int keep_ans[KEEP_RANGE + 5] = {5};

int get_length(int64_t x) {
    if (x == 1) return 1;
    if (x <= KEEP_RANGE && keep_ans[x]) return keep_ans[x];
    int temp_ans;
    if (x & 1) temp_ans = get_length(x * 3 + 1) + 1;
    else temp_ans = get_length(x >> 1) + 1;
    if (x <= KEEP_RANGE) keep_ans[x] = temp_ans;
    return temp_ans;
}

int main() {
    int ans = 0, ans_length = 0;
    for (int i = 1; i < MAX_N; i++) {
        int temp_length = get_length(i);
        if (temp_length > ans_length) {
            ans = i;
            ans_length = temp_length;
        }
    }
    printf("%d(%d)\n",ans, ans_length);
    return 0;
}
