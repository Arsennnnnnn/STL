#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <ctime>

//merge sort
template <typename T>
void merge(std::vector<T>& arr, int left, int mid, int right) {
    std::vector<T> temp(right - left + 1);

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)   temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    std::copy(temp.begin(), temp.end(), arr.begin() + left);
}

template <typename T>
void mergeSort(std::vector<T>& arr, int left, int right) {
    if (left >= right) return; // base case: 0 or 1 elements

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

template <typename T>
void mergeSort(std::vector<T>& arr) {
    if (!arr.empty()) mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
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
    std::vector<int> arr(arr1, arr1 + len);
    mergeSort(arr);
    quickSort(arr2, len);
    std::cout << "sorted arr" << std::endl;
    for (int i = 0; i < len; ++i)
        std::cout << arr[i] << std::endl;
    std::cout << "sorted arr" << std::endl;
    for (int i = 0; i < len; ++i)
        std::cout << arr2[i] << std::endl;
    return 0;
}