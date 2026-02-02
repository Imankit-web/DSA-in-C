//Q. Find the longest subarray whose sum lies in a given range [L, R] (using prefix sum)

#include <stdio.h>

int main() {
    int arr[100], prefix[100];
    int n, L, R;

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of L: ");
    scanf("%d", &L);
    printf("Enter the value of R: ");
    scanf("%d", &R);

    // Build prefix sum
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    int max_len = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum;

            if (i == 0)
                sum = prefix[j];
            else
                sum = prefix[j] - prefix[i - 1];

            if (sum >= L && sum <= R) {
                int length = j - i + 1;
                if (length > max_len) {
                    max_len = length;
                }
            }
        }
    }

    printf("%d", max_len);

    return 0;
}


