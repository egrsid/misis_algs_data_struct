#include <iostream>

void StrNcpy(char* dst, const char* str, int n) {
    while (*str != '\0' && n > 0) {
        *dst = *str;
        ++dst;
        ++str;
        --n;
    }
    
    while (n > 0) {
        *dst = '\0';
        ++dst;
        --n;
    }
}

int main() {
    char* dst = new char[50];
    char str[] = "ABCDE";
    char str1[] = "12345";

    StrNcpy(dst, str, 10);
    StrNcpy(dst, str1, 2);
    std::cout << dst;
}