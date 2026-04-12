#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int parse_replace_command(const char* cmd, char** old_str, char** new_str) {
    if (cmd[0] != 's' || cmd[1] != '/') {
        return -1;
    }

    // TODO: 在这里添加你的代码
    int start = 2;
    int idx = 2;
    while(cmd[idx] != '/' && cmd[idx] != '\0') {
        idx++;
    }
    
    int old_len = idx - start;
    *old_str = (char*)malloc(sizeof(char) * (old_len + 1));
    strncpy(*old_str, &cmd[start], old_len);
    (*old_str)[old_len] = '\0';
    
    if (cmd[idx] == '/') idx++;
    start = idx;
    
    while(cmd[idx] != '/' && cmd[idx] != '\0') {
        idx++;
    }
    
    int new_len = idx - start;
    *new_str = (char*)malloc(sizeof(char) * (new_len + 1));
    strncpy(*new_str, &cmd[start], new_len);
    (*new_str)[new_len] = '\0';
    
    return 0;
}

void replace_first_occurrence(char* str, const char* old, const char* new) {
    // TODO: 在这里添加你的代码
    char* pos = strstr(str, old);
    if (pos == NULL) {
        return;
    }

    char temp[MAX_LINE_LENGTH];
    int prefix_len = pos - str;
    
    // 将匹配到的位置之前的内容复制到temp
    strncpy(temp, str, prefix_len);
    temp[prefix_len] = '\0';
    
    // 拼接新字符串
    strcat(temp, new);
    
    // 拼接老字符串后面的剩余部分
    strcat(temp, pos + strlen(old));
    
    // 将修改后的内容写回原字符串
    strcpy(str, temp);
}

int main(int argc, char* argv[]) {
    const char* replcae_rules = "s/unix/linux/";

    char line[MAX_LINE_LENGTH] = {"unix is opensource. unix is free os."};

    char* old_str = NULL;
    char* new_str = NULL;
    
    if (parse_replace_command(replcae_rules, &old_str, &new_str) != 0) {
        fprintf(stderr, "Invalid replace command format. Use 's/old/new/'\n");
        return 1;
    }

    
    replace_first_occurrence(line, old_str, new_str);
    fputs(line, stdout);

    free(old_str);
    free(new_str);
    return 0;
}
