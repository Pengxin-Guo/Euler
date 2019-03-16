/*************************************************************************
	> File Name: EP26.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 11时47分27秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_N 1000

int num[MAX_N + 5] = {0};

int get_length(int d) {
    memset(num, 0, sizeof(num));
    int y = 1, n = 0;
    while (y && num[y] == 0) {
        num[y] = n;
        y = y * 10 % d;
        n++;
    }
    return y ? n - num[y] : 0;
}

int main() {
    int ans, length = 0;
    for (int d = 2; d < 1000; d++) {
        int tem_length = get_length(d);
        if (length < tem_length) {
            length = tem_length;
            ans = d;
        }
    }
    printf("%d\n", ans);
    return 0;
}
