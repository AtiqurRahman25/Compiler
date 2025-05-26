#include <stdio.h>
#include <string.h>

int main() {
    char line[1000];

    printf("Enter Something: ");
    fgets(line, sizeof(line), stdin);

    int i = 0;
    while (line[i] == ' ' || line[i] == '\t') {
        i++;
    }

    if (line[i] == '/' && line[i+1] == '/') {
        printf("It is a single-line comment.\n");
    } else if (line[i] == '/' && line[i+1] == '*') {
        int len = strlen(line);
        if (len >= 4 && line[len - 3] == '*' && line[len - 2] == '/') {
            printf("It is a multi-line comment (in a single line).\n");
        } else {
            printf("It starts a multi-line comment.\n");
        }
    } else {
        printf("It is not a comment.\n");
    }

    return 0;
}
