/*************************************************************************
	> File Name: EP15.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 11时15分34秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int main() {
    int64_t ans = 1, num = 20;
    for (int64_t i = 40; i > 20; i--) {
        ans *= i;
        while (num > 1 && (ans % num == 0)){
            ans /= num;
            num--;
        }
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
