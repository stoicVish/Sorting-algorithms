#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int j = start - 1;

    for (int i = start; i < end; i++)
    {
        if (arr[i] < pivot)
        {
            j++;
            swap(arr, i, j);
        }
    }
    j++;
    swap(arr, j, end);
    return j;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int index = partition(arr, start, end);
    quickSort(arr, start, index - 1);
    quickSort(arr, index + 1, end);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
