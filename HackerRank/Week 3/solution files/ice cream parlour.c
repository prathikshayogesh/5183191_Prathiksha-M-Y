#include <stdio.h>
#include <stdlib.h>


void icecreamParlor(int m, int arr_count, int* arr) {
    for (int i = 0; i < arr_count - 1; i++) {
        for (int j = i + 1; j < arr_count; j++) {
            if (arr[i] + arr[j] == m) {
                printf("%d %d\n", i + 1, j + 1); 
                return; // Only one solution exists
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);  // number of trips
    
    while (t--) {
        int m, n;
        scanf("%d", &m);  // total money
        scanf("%d", &n);  // number of flavors
        
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        icecreamParlor(m, n, arr);
        
        free(arr);
    }
    return 0;
}
