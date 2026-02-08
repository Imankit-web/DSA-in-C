// Q. Find the number of subarrays with sum exactly equal to K
// Optimized using prefix sum + hash map logic

#include <stdio.h>

int main() {
    int arr[100];
    int n, k;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    int prefixSum = 0;
    int count = 0;

    // Hash map simulation (prefixSum -> frequency)
    int freq[1000] = {0};

    // Important base case
    freq[0] = 1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum - k >= -1000 && prefixSum - k < 1000) {
            count += freq[prefixSum - k];
        }

        freq[prefixSum]++;
    }

    printf("%d", count);

    return 0;
}
