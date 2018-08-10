/*************************************************************************
	> File Name: Euler16.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月25日 星期三 20时53分00秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 400
int num [MAX_N + 5] = {1, 1};

int main() {
    //提高程序的执行效率，可以求1024的100次方，也可以求1024 * 1024的50次方
    //减少外层循环次数
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= num[0]; j++) {
            num[j] *= 1024 * 1024;
        }
        for (int j = 1; j <= num[0]; j++) {
            if (num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] %= 10;
            num[0] += (j == num[0]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= num[0]; i++) {
        ans += num[i];
    }
    printf("%d\n",ans);
}
