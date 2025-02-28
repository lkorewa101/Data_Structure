#include <stdio.h>
#include <stdlib.h>

int list[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

int interpol_search(int key, int n) {
    int low, high, j;

    low = 0;
    high = n - 1;
    while((list[high] != list[low]) && (key >= list[low]) && (key <= list[high])) {
        j = low + ((key - list[low]) * (high - low) / (list[high] - list[low]));
        if(list[j] < key)
            low = j + 1;
        else if(key < list[j])
            high = j - 1;
        else
            return j;
    }

    if(key == list[low])
        return low;
    else
        return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    int result = interpol_search(n, sizeof(list) / sizeof(list[0]));

    if(result != -1) {
        printf("Key found at index %d\n", result);
    } else {
        printf("Key not found\n");
    }

    return 0;
}
