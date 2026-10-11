
#include <stdio.h>

int main() {
    int arr[100], n, i;
    int largest, secondLargest;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 2 || n > 100) {
        printf("Enter between 2 and 100 elements.\n");
        return 1;
    }

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    largest = secondLargest = 0;
    int hasLargest = 0, hasSecond = 0;

    for (i = 0; i < n; i++) {
        if (!hasLargest || arr[i] > largest) {
            if (hasLargest) {
                secondLargest = largest;
                hasSecond = 1;
            }

            largest = arr[i];
            hasLargest = 1;
        } else if (arr[i] < largest &&
                   (!hasSecond || arr[i] > secondLargest)) {
            secondLargest = arr[i];
            hasSecond = 1;
        }
    }

    if (hasSecond) {
        printf("Second-largest element = %d\n", secondLargest);
    } else {
        printf("Second-largest distinct element does not exist.\n");
    }

    return 0;
}
