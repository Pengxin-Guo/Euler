/*************************************************************************
	> File Name: EP11.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 15时53分57秒
 ************************************************************************/

#include <stdio.h>

int dir_arr[4][2] = {
    1, 1, 1, -1,
    0, 1, 1, 0
};

int main() {
    int num[30][30] = {0}, ans = 0;
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            scanf("%d", num[i] + j);
        }
    }
    for (int x = 5; x < 25; x++) {
        for (int y = 5; y < 25; y++) {
            for (int k = 0; k < 4; k++) {
                int p = 1;
                for (int step = 0; step < 4; step++) {
                    int xx = x + step * dir_arr[k][0];
                    int yy = y + step * dir_arr[k][1];
                    p *= num[xx][yy];
                }
                if (p > ans) ans = p;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
