/*************************************************************************
	> File Name: Euler42.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 20时58分06秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include "42.h"
#define MAX_N 2000

int triangle(int n) {
    return n * (n + 1) / 2;
}

int find(int x) {
    int low = 0, high = 500, mid;
    while (low <= high) {
        mid = (low + high) >> 1;
        if (triangle(mid) == x) return mid;
        if (triangle(mid) < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int length = 0;
    while (words[length].length() != 0) length++;
    int ans = 0;
    for (int i = 0; i < length; i++) {
        int t = 0;
        for (int j = 0; j < words[i].length(); j++) {
            t += words[i][j] - 'A' + 1;
        }
        if (find(t) == -1) continue;
        ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}
