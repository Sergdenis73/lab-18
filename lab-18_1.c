#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Помилка: ділення на нуль!\n");
        return 0;
    }
}

int modulo(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        printf("Помилка: ділення на нуль!\n");
        return 0;
    }
}

int main() {
    system("chcp 65001");

    int (*func_ptr[5])(int, int) = {add, subtract, multiply, divide, modulo};
    
    int a = 10, b = 3;
    int result;

    for (int i = 0; i < 5; i++) {
        result = func_ptr[i](a, b);
        printf("Функція %d: результат = %d\n", i + 1, result);
    }
    
    return 0;
}