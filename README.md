# Euler
#### Euler 50 test

**Problem 1. Multiples of 3 and 5**

 思路：把`3`的倍数加一遍，再把`5`的倍数加一遍，最后把`15`的倍数减一遍。

```c
for (int i = 3; i < MAX_N; i += 3) ans += i;
for (int i = 5; i < MAX_N; i += 5) ans += i;
for (int i = 15; i < MAX_N; i += 15) ans -= i;
```

**Problem 2. Even Fibonacci numbers**

思路：利用循环数组，`num[n % 3] = num[(n - 1) % 3] + num[(n - 2) % 3]`，一个长度为`3`的数组即可解决该问题。关键是数组的初始化，`num[0]`代表第一个斐波那契数`1`，之后要想使`num[1]`为`2`，则`num[2]`应初始化为`1`，`num[1]`初始化为`0`即可，这就是数组的初始化，`num[3] = {1, 0, 1}`。

```c
int ans = 0, n = 0;
while (num[n % 3] <= MAX_N) {
    if(!(num[n % 3] & 1))  ans += num[n % 3];
    n += 1;
    num[n % 3] = num[(n - 1) % 3] + num[(n - 2) % 3];
}
```

**Problem 3. Largest prime factor**

思路：从最小的质因数开始，慢慢增大向上除。

```c
int64_t n = 2, ans, num = 600851475143;
while (n * n < num) {
    if (num % n == 0) ans = n;
    while (num % n == 0) num /= n;
    n++;
}
if (num != 1) ans = num
```

**Problem 4. Largest palindrome product**

思路：暴力求解即可。

```c
int is_palindromic(int n) {
    int temp = n, num = 0;
    while (temp) {
        num = num * 10 + temp % 10;
        temp /= 10;
    }
    return num == n;
}

int main() {
    int ans = 0;
    for (int i = 999; i; i--) {
        for (int j = 999; j; j--) {
            if (!is_palindromic(i * j)) continue;
            if (ans < i * j) ans = i * j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
```

**Problem 5. Smallest multiple**

思路：`a`和`b`的最小公倍数等于`a * b / gcb(a, b)`，其中`gcb`代表最大公约数。这个题给出了最小的能够被被`1`到`10`整除的数是`2520`，故我们只需从`11`开始计算即可。

```c
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
```

**Problem 6. Sum square difference**

 思路：平方和公式为：1<sup>2</sup> + 2<sup>2</sup> + ... + n<sup>2</sup> = n * (n + 1) * (2 * n + 1) / 6。

```c
int64_t num1 = 100 * (100 + 1) / 2, num2 = 100 * (100 + 1) * (2 * 100 + 1) / 6;
printf("%" PRId64 "\n", num1 * num1 - num2);
```

**Problem 7. 10001st prime**

思路：线性筛。

```c
void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; i * prime[j] < MAX_N && j <= prime[0]; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}
```

**Problem 8. Largest product in a series**

思路：滑动窗口法。设置窗口大小为`13`，并且记录一下这个窗口里面`0`的个数，处理`0`这个数字只需将`0`的个数加一（入窗口）或减一（出窗口）就行，而不需要计算到最终结果里面。

```c
int64_t ans = 0, zero = 0, p = 1;
for (int64_t i = 0; i < MAX_N; i++) {
    if (num[i] == '0') zero += 1;
    else p *= (num[i] - '0');
    if (i >= 13) {
        if (num[i - 13] == '0') {
            zero -= 1;
        }
        else {
            p /= (num[i - 13] - '0');
        }
    }
    if (zero == 0 && ans < p) ans = p;
}
```

**Problem 9. Special Pythagorean triplet**

思路：毕达哥拉斯三元数组（勾股数组）：`a * a + b * b = c * c`；满足以下性质，若`a`为偶数，则存在正整数`i`、`j`，使`a = 2 * i * j`、`b = j * j - i * i`、`c = j * j + i * i`成立。

```c
for (int i = 1; i < 32; i++) {
    for (int j = i + 1; j < 32; j++) {
        int a = 2 * i * j;
        int b = j * j - i * i;
        int c = j * j + i * i;
        if (1000 % (a + b + c) == 0){
            int e = 1000 / (a + b + c);
            printf("%d\n", a * b * c * e * e * e);
            return 0;
        }
    }
}
```

**Problem 10. Summation of primes**

思路：线性筛，一边判断是否是素数，一边求解答案。

```c
int prime[MAX_N + 5] = {0};
int64_t ans = 0;
for (int i = 2; i < MAX_N; i++) {
    if (!prime[i]) {
        prime[++prime[0]] = i;
        ans += i;
    }
    for (int j = 1; i * prime[j] <= MAX_N && j <= prime[0]; j++) {
        prime[i * prime[j]] = 1;
        if (i % prime[j] == 0) break;
    }
}
printf("%" PRId64 "\n", ans);
```

**Problem 11. Summation of primes**

思路：循环，暴力求解即可。

```c
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
```

**Problem 12. Highly divisible triangular number**

思路：第`n`个三角形数为`n * (n + 1) / 2` ，可以写成`a * b`的形式，`a * b`的因数个数等于`a`的因数个数乘以`b`的因数个数再减去重复的。利用线性筛可以求出每个数的因子个数。

```c
int prime[MAX_N + 5] = {0};
int dnum[MAX_N + 5] = {0}; //记录每个数字的因子个数
int mnum[MAX_N + 5] = {0}; //记录每个数字的最小因子的幂次

void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;
            mnum[i] = 1;
        }
        for (int j = 1; i * prime[j] <= MAX_N && j <= prime[0]; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                dnum[i * prime[j]] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                mnum[i * prime[j]] = mnum[i] + 1;
                break;
            }
            dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            mnum[i * prime[j]] = 1;
        }
    }
    return ;
}

int factor_nums(int n) {
    if (n & 1) return dnum[n] * dnum[(n + 1) / 2];
    else return dnum[n / 2] * dnum[n + 1];
}

int main() {
    init();
    int n = 1;
    while (factor_nums(n) < 500) n++;
    printf("%d\n", n * (n + 1) / 2);
    return 0;
}
```

