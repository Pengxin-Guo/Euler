/*************************************************************************
	> File Name: EP5.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 15时25分18秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int64_t gcb(int64_t a, int64_t b) {
    if (b == 0) return a;
    return gcb(b, a % b);
}

int main() {
    int64_t ans = 2520;
    for (int64_t i = 11; i <= 20; i++) {
        ans = ans * i / gcb(ans, i);
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
