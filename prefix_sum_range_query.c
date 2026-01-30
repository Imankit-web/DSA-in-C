//Q. Find the sum of elements between indices L and R for multiple queries.


#include <stdio.h>

int main() {
    int arr[100], prefix[100];
    int n;

    printf("Enter the length of the array: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1] + arr[i];
    }

    int q;
    printf("Enter number of queries: ");
    scanf("%d", &q);

  
    while(q--){
        int l, r;
        printf("Enter l and r: ");
        scanf("%d", &l);
        scanf("%d", &r);

        int sum;
        if(l == 0){
            sum = prefix[r];
        } else {
            sum = prefix[r] - prefix[l - 1];
        }

        printf("Sum = %d\n", sum);
    }

    return 0;
}
