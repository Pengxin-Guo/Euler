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

