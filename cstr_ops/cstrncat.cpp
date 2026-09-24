#include <iostream>

void StrNcat(char* dst, const char* str, int n) {
    while (*dst != '\0') ++dst;

    while (*str != '\0' && n > 0) {
        *dst = *str;
        ++dst; ++str; --n;
    }

    *dst = '\0';
}

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
    std::cout << dst << std::endl;

    StrNcat(dst, str1, 20);
    std::cout << dst << std::endl;
}