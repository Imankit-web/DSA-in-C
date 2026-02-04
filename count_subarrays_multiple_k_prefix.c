//Q. Find the number of subarrays with sum exactly equal to K for multiple queries (using prefix sum)


#include <stdio.h>

int main() {
    int arr[100], prefix[100];
    int n, k,q;

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of queries:");
    scanf("%d",&q);
    
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1] + arr[i];
    }
    
    int count = 0;
    
    while(q-- ){
        printf("Enter the value of K: ");
        scanf("%d", &k);
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int sum;
        
                if(i == 0){
                    sum = prefix[j];
                } else {
                    sum = prefix[j] - prefix[i - 1];
                }
                if(sum == k){
                    count++;
                }
            }
        }
        printf("%d\n", count);
        count=0;
    }


    return 0;
}
