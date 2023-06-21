#include <stdio.h>

int stairs(int n) {
    if (n <= 1) {
        return n;
    }
    return stairs(n - 1) + stairs(n - 2);
}

int countWays(int s) {
    return stairs(s - 2);
}

int main() {
    int result = countWays(5);
    printf("%d\n", result);
    return 0;
}
