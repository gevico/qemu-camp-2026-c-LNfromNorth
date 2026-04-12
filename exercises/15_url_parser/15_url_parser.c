#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 * URL参数解析器
 * 输入：包含http/https超链接的字符串
 * 输出：解析出所有的key-value键值对，每行显示一个
 */

int parse_url(const char* url) {
    int err = 0;

    // TODO: 在这里添加你的代码
    int idx = 0;
    // 找到问号或者结尾
    while(url[idx] != '\0' && url[idx] != '?') {
        idx++;
    }
    // 跳过问号
    if (url[idx] == '?') {
        idx++;
    }

    while(url[idx] != '\0') {
        char key[100];
        int tmp_idx = 0;
        // 遇到等号或者结束符停止
        while(url[idx] != '\0' && url[idx] != '=') {
            key[tmp_idx++] = url[idx++];
        }
        key[tmp_idx] = '\0'; 
        if (url[idx] == '=') idx++;
        
        char value[100];
        tmp_idx = 0;
        // 遇到与号或者结束符停止
        while(url[idx] != '\0' && url[idx] != '&') {
            value[tmp_idx++] = url[idx++];
        }
        value[tmp_idx] = '\0'; 
        if (url[idx] == '&') idx++;
        
        printf("key = %s, value = %s\n", key, value);
    }
exit:
    return err;
}

int main() {
    const char* test_url = "https://cn.bing.com/search?name=John&age=30&city=New+York";

    printf("Parsing URL: %s\n", test_url);
    printf("Parameters:\n");

    parse_url(test_url);

    return 0;
}