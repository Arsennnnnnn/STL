#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>

//merge sort
void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2]; // temp arrays

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k] = L[i++];
        else arr[k] = R[j++];
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
//merge sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// quick sort
int partition(int array[], int left, int right)
{
  int pivot_index = left + (std::rand() % (right - left + 1));
  if (pivot_index != right)
  {
    std::swap(array[pivot_index], array[right]);
  }

  int pivot_value = array[right];
  int i = left;
  for (int j = left; j < right; j++)
  {
    if (array[j] <= pivot_value)
    {
      std::swap(array[i], array[j]);
      i++;
    }
  }
  std::swap(array[i], array[right]);
  return i;
}

void quickSort_recursion (int arr[], int left, int right) {
    if (left < right) {
        int pivot_index = partition(arr, left, right);
        quickSort_recursion(arr, left, pivot_index - 1);
        quickSort_recursion(arr, pivot_index + 1, right);
    }

}

void quickSort(int arr[], int length) {
    std::srand(time(nullptr));
    quickSort_recursion(arr, 0, length - 1);
}
//quick sort

int main() {
    int arr1[] = {123, 433, 1, 4, 6, 5, 4, 10, 3 , 901};
    int arr2[] = {3, 10, 200, 1, 23, -1, 0, 7, 4, 90};
    int len = 10;
    mergeSort(arr1, 0, len - 1);
    quickSort(arr2, len);
    std::cout << "sorted arr1" << std::endl;
    for (int i = 0; i < len; ++i)
        std::cout << arr1[i] << std::endl;
    std::cout << "sorted arr2" << std::endl;
    for (int i = 0; i < len; ++i)
        std::cout << arr2[i] << std::endl;
    return 0;
}