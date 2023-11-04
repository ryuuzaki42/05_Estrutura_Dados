#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0, k = 0;
    int *arr = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
    double result = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            arr[k++] = nums1[i++];
        } else {
            arr[k++] = nums2[j++];
        }
    }

    for (; i < nums1Size; i++) {
        arr[k++] = nums1[i];
    }

    for (; j < nums2Size; j++) {
        arr[k++] = nums2[j];
    }

    if (k % 2 == 0) {
        result = (arr[k / 2] + arr[k / 2 - 1]) / 2.0;
    } else {
        result = (double)arr[k / 2];
    }

    free(arr);
    return result;
}

int main() {
    int nums1[] = {2, 3, 5, 8};
    int nums1Size = 4;
    int nums2[] = {10, 12, 14, 16, 18, 20};
    int nums2Size = 6;

    double median = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("Median: %.2f\n", median);
    return 0;
}
