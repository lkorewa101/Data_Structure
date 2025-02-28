#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void selection_sort(int list[], int n) {
    int i, j, least, temp;
    for(i = 0; i < n - 1; i++) {
        least = i;
        for(j = i + 1; j < n; j++) {
            if(list[j] < list[least]) {
                least = j;
            }
        }
        SWAP(list[i], list[least], temp);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int list[n];
    int i;

    for(i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    selection_sort(list, n);
    printf("%d\n", list[k-1]);
    return 0;
}