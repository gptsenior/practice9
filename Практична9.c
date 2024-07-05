#include <stdio.h>
#include <stdlib.h>

int minSteps(int x, int y) {

    int distance = y - x;

    int steps = 0;

    int stepLength = 1;

    while (distance > 0) {
        steps++;
        distance -= stepLength;
        if (distance <= stepLength) {
            stepLength = distance;
        } else if (distance > stepLength * 2) {
            stepLength++;
        }
    }

    return steps;
}

int main() {
    int x, y;
    printf("Введіть початкове значення x: ");
    scanf("%d", &x);
    printf("Введіть кінцеве значення y: ");
    scanf("%d", &y);

    if (x < 0 || y < 0 || x > y) {
        printf("Некоректні значення. Переконайтесь, що 0 <= x <= y < 2^31.\n");
        return 1;
    }

    int result = minSteps(x, y);
    printf("Мінімальна кількість кроків від %d до %d: %d\n", x, y, result);

    return 0;
}