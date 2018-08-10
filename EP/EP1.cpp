/*************************************************************************
	> File Name: EP1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 14时04分03秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 1000

int main() {
    int ans = 0;
    for (int i = 3; i < MAX_N; i += 3) ans += i;
    for (int i = 5; i < MAX_N; i += 5) ans += i;
    for (int i = 15; i < MAX_N; i += 15) ans -= i;
    printf("%d\n", ans);
    return 0;
}
