#include <stdio.h>
#include <stdlib.h>

int list[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

int search_binary(int key, int low, int high) {
    if(low > high) {
        return -1;
    }

    int middle = low + (high - low) / 2;

    if(list[middle] == key) {
        return middle;
    } else if(key < list[middle]) {
        return search_binary(key, low, middle - 1);
    } else {
        return search_binary(key, middle + 1, high);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int result = search_binary(n, 0, sizeof(list) / sizeof(list[0]) - 1);

    if(result != -1) {
        printf("Key found at index %d\n", result);
    } else {
        printf("Key not found\n");
    }

    return 0;
}
