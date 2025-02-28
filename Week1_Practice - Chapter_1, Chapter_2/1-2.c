#include <stdio.h>

// 알고리즘 A: sum = n(n+1)/2
long long algorithm_A(int n) {
    return (long long)n * (n + 1) / 2;
}

// 알고리즘 B: sum = 1 + 2 + ... + n
long long algorithm_B(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// 알고리즘 C: sum = (1) + (1 + 1) + (1 + 1 + 1) + ..., (1 + 1 + ... + 1)
long long algorithm_C(int n) {
    long long sum = 0;
    long long term = 0;
    for (int i = 1; i <= n; i++) {
        term += 1;
        sum += term;
    }
    return sum;
}

int main() {
    int n1, n2, n3;

    scanf("%d", &n1);

    scanf("%d", &n2);

    scanf("%d", &n3);

    printf("%lld %lld %lld %d\n", algorithm_A(n1), algorithm_B(n1), algorithm_C(n1), n1);
    printf("%lld %lld %lld %d\n", algorithm_A(n2), algorithm_B(n2), algorithm_C(n2), n2);
    printf("%lld %lld %lld %d\n", algorithm_A(n3), algorithm_B(n3), algorithm_C(n3), n3);

    return 0;
}