#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;

    int lenDiff = strlen(str1) - strlen(str2);

    if (lenDiff == 0) {
        return strcmp(str1, str2);
    }
    else {
        return lenDiff;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    char **words = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        words[i] = (char *)malloc(51 * sizeof(char));
        scanf("%s", words[i]);
    }

    qsort(words, n, sizeof(char *), compare);

    for (int i = 0; i < n; i++) {
        if (i == 0 || strcmp(words[i], words[i - 1]) != 0)
            printf("%s\n", words[i]);
    }

    for (int i = 0; i < n; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}
