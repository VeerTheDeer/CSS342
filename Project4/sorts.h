#ifndef SORTS_H_
#define SORTS_H_

#include <vector>

using namespace std;

class sorts {
public:
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void merge(vector<int>& myVec, int left, int middle, int right) {
        int length1 = middle - left + 1;
        int length2 = right - middle;

        vector<int> Left(length1);
        vector<int> Right(length2);

        for (int i = 0; i < length1; i++) {
            Left[i] = myVec[left + i];
        }

        for (int i = 0; i < length2; i++) {
            Right[i] = myVec[middle + 1 + i];
        }

        int lPointer = 0, rPointer = 0, counter = left;

        while (lPointer < length1 && rPointer < length2) {
            if (Left[lPointer] <= Right[rPointer]) {
                myVec[counter++] = Left[lPointer++];
            } else {
                myVec[counter++] = Right[rPointer++];
            }
        }


        while (lPointer < length1) {
            myVec[counter++] = Left[lPointer++];
        }

        while (rPointer < length2) {
            myVec[counter++] = Right[rPointer++];
        }
    }

    // Recursive Merge Sort implementation
    void MergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            // Recursively sort left and right halves
            MergeSort(arr, left, mid);
            MergeSort(arr, mid + 1, right);

            // Merge sorted halves
            merge(arr, left, mid, right);
        }
    }

    void IterativeMergeSort(vector<int>& items, int size) {
        vector<int> temp(size);
        for (int width = 1; width < size; width *= 2) {
            for (int left = 0; left < size - width; left += 2 * width) {
                int middle = left + width - 1;
                int right = min(left + 2 * width - 1, size - 1);

                int i = left, j = middle + 1, k = left;

                while (i <= middle && j <= right) {
                    if (items[i] <= items[j]) {
                        temp[k++] = items[i++];
                    } else {
                        temp[k++] = items[j++];
                    }
                }

                while (i <= middle) {
                    temp[k++] = items[i++];
                }

                while (j <= right) {
                    temp[k++] = items[j++];
                }

                for (int x = left; x <= right; x++) {
                    items[x] = temp[x];
                }
            }
        }
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Partition method for QuickSort
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void QuickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(arr, low, high);

            QuickSort(arr, low, pivotIndex - 1);
            QuickSort(arr, pivotIndex + 1, high);
        }
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void BubbleSort(vector<int>& items, int size) {
        for (int i = size; i > 0; i--) {
            for (int j = 0; j < i - 1; j++) {
                if (items[j] > items[j + 1]) {
                    swap(items[j], items[j + 1]);
                }
            }
        }
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void InsertionSort(vector<int>& items, int size) {
        for (int i = 1; i < size; i++) {
            int key = items[i];
            int j = i - 1;

            // Move elements greater than key one position ahead
            while (j >= 0 && items[j] > key) {
                items[j + 1] = items[j];
                j--;
            }
            items[j + 1] = key;
        }
    }

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    void ShellSort(vector<int>& items, int size) {
        for (int gap = size / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < size; i++) {
                int temp = items[i];
                int j = i;

                while (j >= gap && items[j - gap] > temp) {
                    items[j] = items[j - gap];
                    j -= gap;
                }
                items[j] = temp;
            }
        }
    }
};

#endif // SORTS_H_