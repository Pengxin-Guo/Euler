/*************************************************************************
	> File Name: EP17.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 14时34分58秒
 ************************************************************************/

#include <stdio.h>

int ln20[20] = {
    0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3,
    6, 6, 8, 8, 7, 7, 9, 8, 8,
};
int ln_10[10] = {
    0, 0, 6, 6, 5, 5, 5, 7, 6, 6
};

int get_letter_num(int i) {
    if (i < 20) {
        return ln20[i];
    } else if (i < 100) {
        return ln_10[i / 10] + ln20[i % 10];
    } else if (i < 1000) {
        int temp = get_letter_num(i % 100);
        if (temp != 0) temp += 3;
        return temp + ln20[i / 100] + 7;
    } else {
        return 11;
    }
}

int main() {
    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        ans += get_letter_num(i);
    }
    printf("%d\n", ans);
    return 0;
}
