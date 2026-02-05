//Q. Find the maximum sum of any subarray with length exactly K (using prefix sum)

#include <stdio.h>

int main() {
    int arr[100], prefix[100];
    int n, k;

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    // If subarray of length k cannot exist
    if (k > n) {
        printf("0");
        return 0;
    }

    // Build prefix sum
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // Initialize max_sum using first valid subarray
    int max_sum = prefix[k - 1];

    for (int i = 1; i + k - 1 < n; i++) {
        int j = i + k - 1;
        int sum = prefix[j] - prefix[i - 1];

        if (sum > max_sum) {
            max_sum = sum;
        }
    }

    printf("%d", max_sum);

    return 0;
}
