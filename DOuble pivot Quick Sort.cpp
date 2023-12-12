#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void dualPivotQuickSort(vector<int>& array, int low, int high) {
    if (low < high) {
        if (array[low] > array[high]) {
            swap(array[low], array[high]);
        }

        int pivot1 = array[low];
        int pivot2 = array[high];

        int i = low + 1;
        int leftPartition = low + 1;
        int rightPartition = high - 1;

        while (i <= rightPartition) {
            if (array[i] < pivot1) {
                swap(array[i], array[leftPartition]);
                leftPartition++;
            } else if (array[i] > pivot2) {
                while (i < rightPartition && array[rightPartition] > pivot2) {
                    rightPartition--;
                }
                swap(array[i], array[rightPartition]);
                rightPartition--;
                if (array[i] < pivot1) {
                    swap(array[i], array[leftPartition]);
                    leftPartition++;
                }
            }
            i++;
        }

        leftPartition--;
        rightPartition++;

        swap(array[low], array[leftPartition]);
        swap(array[high], array[rightPartition]);

        dualPivotQuickSort(array, low, leftPartition - 1);
        dualPivotQuickSort(array, leftPartition + 1, rightPartition - 1);
        dualPivotQuickSort(array, rightPartition + 1, high);
    }
}

void printArray(const vector<int>& array) {
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers = {6,7,2,2, 4, 5,9,0};
    int size = numbers.size();

    cout << "Original array: ";
    printArray(numbers);

    dualPivotQuickSort(numbers, 0, size - 1);

    cout << "Sorted array: ";
    printArray(numbers);

    return 0;
}
