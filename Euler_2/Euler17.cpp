/*************************************************************************
	> File Name: Euler17.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月25日 星期三 20时05分39秒
 ************************************************************************/

#include <stdio.h>

int LN20[20] = {
    0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3,
    6, 6, 8, 8, 7, 7, 9, 8, 8
};
int LN_shi[10] = {
    0, 0, 6, 6, 5, 5, 5, 7, 6, 6
};

int get_letter_num(int i) {
    if (i < 20) {
        return LN20[i];
    } else if (i < 100) {
        return LN_shi[i / 10] + LN20[i % 10];
    } else if (i < 1000) {
        int temp = get_letter_num(i % 100);
        if (temp != 0) temp += 3;
        return temp + LN20[i / 100] + 7;
    } else if (i == 1000) {
        return 11;
    } else {
        return 0;
    }
    return 0;
}

int main() {
    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        ans += get_letter_num(i);
    }
    printf("%d\n",ans);
    return 0;
}
