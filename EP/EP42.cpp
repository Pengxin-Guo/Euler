/*************************************************************************
	> File Name: EP42.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 14时11分59秒
 ************************************************************************/

#include <stdio.h>
#include "42.h"

int triangle(int n) {
    return n * (n + 1) / 2;
}

int get_num(char *word) {
    int num = 0;
    for (int i = 0; word[i]; i++) {
        num += word[i] - 'A' + 1;
    }
    return num;
}

int find(int x) {
    int low = 0, high = 500, mid;
    while (low <= high) {
        mid = (low + high) >> 1;
        if (triangle(mid) == x) return 1;
        if (triangle(mid) < x) low = mid + 1;
        else high = mid - 1;
    }
    return 0;
}

int main() {
    int n = sizeof(words) / 20;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp = get_num(words[i]);
        if (find(temp)) {
            ans += 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
