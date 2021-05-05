#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSort(int arr[], int start, int end)
{
    for (int i = start; i < end; i++)
    {
        int min = arr[i], index = i;
        for (int j = i + 1; j <= end; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }

        swap(arr, i, index);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    selectionSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
