#include <stdio.h>

unsigned int gcd_asm(unsigned int a, unsigned int b) {
    unsigned int result;
    
    __asm__ volatile (
        "mov %[a], %%eax\n\t"
        "mov %[b], %%ecx\n\t"
        "1:\n\t"
        "test %%ecx, %%ecx\n\t"
        "je 2f\n\t"
        "xor %%edx, %%edx\n\t"
        "div %%ecx\n\t"
        "mov %%ecx, %%eax\n\t"
        "mov %%edx, %%ecx\n\t"
        "jmp 1b\n\t"
        "2:\n\t"
        "mov %%eax, %[result]"
        : [result] "=r" (result)
        : [a] "r" (a), [b] "r" (b)
        : "eax", "ecx", "edx", "cc"
    );
    
    return result;
}

int main(int argc, char* argv[]) {
    printf("%d\n", gcd_asm(12, 8));
    printf("%d\n", gcd_asm(7, 5));
    return 0;
}
