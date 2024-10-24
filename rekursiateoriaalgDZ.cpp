// rekursiateoriaalgDZ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int findMax(int arr[], int n) 
{
    if (n == 1) return arr[0];
    return max(arr[n - 1], findMax(arr, n - 1));
}

int findMin(int arr[], int n) 
{
    if (n == 1) return arr[0];
    return min(arr[n - 1], findMin(arr, n - 1));
}

int partition(int arr[], int low, int high, int& pivotIdx) 
{
    int pivot = arr[high];
    int i = low - 1;
    cout << "opor element: " << pivot << endl;
    for (int j = low; j < high; j++) 
    {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    pivotIdx = i + 1;
    cout << "array after sorting: ";
    for (int k = low; k <= high; k++) cout << arr[k] << " ";
    cout << endl;
    cout << "indexof element: " << pivotIdx << endl;

    return pivotIdx;
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pivotIdx;
        int pi = partition(arr, low, high, pivotIdx);
        cout << "left side: ";
        for (int i = low; i < pivotIdx; i++) cout << arr[i] << " ";
        cout << endl;
        cout << "right side: ";
        for (int i = pivotIdx + 1; i <= high; i++) cout << arr[i] << " ";
        cout << endl;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() 
{
    vector<vector<int>> arrays = 
    {
        {34, 7, 23, 32, 5},
        {1, 2, 3, 4, 5, 6},
        {90, 80, 70, 60, 50, 40, 30},
        {5, 3, 8, 8, 1, 5, 3, 9}
    };

    for (int i = 0; i < arrays.size(); i++) 
    {
        int* arr = arrays[i].data();
        int size = arrays[i].size();

        cout << "max elevment of array: " << findMax(arr, size) << endl;

        cout << "min elevment of array: " << findMin(arr, size) << endl;

        cout << "nachalniy massive: ";
        for (int j = 0; j < size; j++) cout << arr[j] << " ";
        cout << endl;
        quickSort(arr, 0, size - 1);
        cout << "sorted massive: ";
        for (int j = 0; j < size; j++) cout << arr[j] << " ";
        cout << endl;
        cout << "---------------------------" << endl;
    }
    return 0;
}