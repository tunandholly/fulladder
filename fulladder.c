#include <stdio.h>

// 計算 Sum（每個位的和）
int full_adder_x(int a, int b, int c) {
    return a ^ b ^ c;
}

// 計算 Carry（進位）
int full_adder_c(int a, int b, int c) {
    return (a & b) | (b & c) | (a & c);
}

#define LEN 5

int main() {
    int a[LEN], b[LEN], ans[LEN], c = 0;

    // 讀取輸入
    for(int i = 0 ; i < LEN; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0 ; i < LEN; ++i) {
        scanf("%d", &b[i]);
    }

    // 從最低有效位（LSB）到最高有效位（MSB）進行計算
    for(int i = 0; i < LEN; ++i) {
        int sum = full_adder_x(a[i], b[i], c);
        int carry = full_adder_c(a[i], b[i], c);
        ans[i] = sum;
        c = carry;
    }

    // 輸出結果
    for(int i = 0; i < LEN; ++i) {
        printf("%d ", ans[i]);
    }
    printf("%d", c);

    return 0;
}
