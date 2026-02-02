//Q. Check if there exists at least ONE subarray with sum exactly equal to K (using prefix sum)

#include <stdio.h>

int main() {
    int arr[100], prefix[100];
    int n, k;

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of K: ");
    scanf("%d", &k);

    // Build prefix sum
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1] + arr[i];
    }

    int flag=0;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum;

            if(i == 0){
                sum = prefix[j];
            } else {
                sum = prefix[j] - prefix[i - 1];
            }

            if(sum == k){
                flag=1;
                break;
            }
        }
        if(flag){
            break;
        }
    }

    if(flag){
        printf("yes");

    }else{
        printf("No");
    }

    return 0;
}
