#include <stdio.h>

int main() {
    char source[] = "Hello, World! This is a test string for my_strcpy function.\n";
    char destination[101];
    
	// TODO: 在这里添加你的代码
    int idx = 0;
    do {
        destination[idx] = source[idx];
        idx++;
    } while(source[idx] != '\0');
    
    printf("拷贝后的字符串: %s", destination);
    
    return 0;
}