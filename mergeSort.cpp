#include <iostream>
#include <vector>
using namespace std;

void merge(int low, int mid, int high, int *arr)
{
    vector<int> left(mid - low + 1), right(high - mid);
    for (int i = low; i <= mid; i++)
        left[i - low] = (arr[i]);

    for (int i = mid + 1; i <= high; i++)
        right[i - mid - 1] = (arr[i]);

    int i = 0, j = 0, k = low;

    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < left.size())
        arr[k++] = left[i++];

    while (j < right.size())
        arr[k++] = right[j++];
}

void mergeSort(int low, int high, int *arr)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    mergeSort(low, mid, arr);
    mergeSort(mid + 1, high, arr);
    merge(low, mid, high, arr);
}

//test code
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(0, n - 1, arr);

    for (int i : arr)
        cout << i << " ";

    return 0;
}
