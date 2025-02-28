#include <stdio.h>


int main() {
    int day[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int number[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for(int i = 0; i < 12; i++) {
        printf("%d %d\n", number[i], day[i]);
    }
    return 0;
}