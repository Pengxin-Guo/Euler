/*************************************************************************
	> File Name: EP43.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 15时39分41秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include <algorithm>

int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int prime[8] = {0, 2, 3, 5, 7, 11, 13, 17};

int is_valid(int i) {
    int temp = num[i] * 100 + num[i + 1] * 10 + num[i + 2];
    if (temp % prime[i] == 0) return 1;
    return 0;
}

int main() {
    int64_t ans = 0;
    while(std::next_permutation(num, num + 10)) {
        if (num[0] == 0) continue;
        int flag = 1;
        for (int i = 1; i < 8 && flag; i++) {
            if (!is_valid(i)) flag = 0;
        }
        if (flag) {
            int64_t t = 0;
            for (int i = 0; i < 10; i++) {
                t = t * 10 + num[i];
            }
            ans += t;
        }
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
