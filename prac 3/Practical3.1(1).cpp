#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int marks[n];
    cout << "Enter marks: ";
    for (int i = 0; i < n; i++)
    {
        cin >> marks[i];
    }

    int bubble[n], selection[n], insertion[n];

    for (int i = 0; i < n; i++)
    {
        bubble[i] = marks[i];
        selection[i] = marks[i];
        insertion[i] = marks[i];
    }

    bubbleSort(bubble, n);
    selectionSort(selection, n);
    insertionSort(insertion, n);

    cout << "\nBubble Sort: ";
    display(bubble, n);

    cout << "Selection Sort: ";
    display(selection, n);

    cout << "Insertion Sort: ";
    display(insertion, n);

    return 0;
}
