#include <iostream>
#include <vector>
#include <ctime>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int leftSub = mid - left + 1; // Length of the left subarray
    int rightSub = right - mid; // Length of the right subarray

    // Create temporary arrays
    std::vector<int> L(leftSub), R(rightSub);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < leftSub; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < rightSub; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0; // Initial index of the first subarray
    int j = 0; // Initial index of the second subarray
    int k = left; // Initial index of the merged subarray

    while (i < leftSub && j < rightSub) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < leftSub) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < rightSub) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2; // Find the middle point to divide the array into two halves
    mergeSort(arr, left, mid); // Sort the first half
    mergeSort(arr, mid + 1, right); // Sort the second half
    merge(arr, left, mid, right); // Merge the sorted halves
}

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
        std::cin >> arr[i];
    std::clock_t start_time = std::clock();
    mergeSort(arr, 0, n - 1);
    std::clock_t tot_time = std::clock() - start_time;

    std::cout << "Sorted array is \n";
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    std::clock_t tot_time = std::clock() - start_time;
    std::cout << "Time: "
              << ((double) tot_time) / (double) CLOCKS_PER_SEC
              << " seconds" << std::endl;
    return 0;
}
