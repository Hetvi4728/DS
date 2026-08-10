#include <iostream>
using namespace std;

void traverse(int arr[], int n)
{
    cout << "Array Elements are : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int insertElement(int arr[], int n, int element, int position)
{
    if (position < 1 || position > n + 1)
    {
        cout << "Invalid position" << endl;
        return n;
    }

    for (int i = n; i >= position; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = element;
    n++;

    cout << "Element inserted" << endl;
    return n;
}

int deleteElement(int arr[], int n, int position)
{
    if (position < 1 || position > n)
    {
        cout << "Invalid position" << endl;
        return n;
    }

    for (int i = position - 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Element deleted successfully" << endl;
    return n;
}

void searchElement(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at position " << i + 1 << endl;
            return;
        }
    }

    cout << "Element not found" << endl;
}

int main()
{
    int arr[100], n;
    int choice, element, position, key;

    cout << "Enter number of elements : ";
    cin >> n;

    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    do
    {
        cout << "\n1. Traverse";
        cout << "\n2. Insert";
        cout << "\n3. Delete";
        cout << "\n4. Search";
        cout << "\n5. Exit";

        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            traverse(arr, n);
            break;

        case 2:
            cout << "Enter element to insert : ";
            cin >> element;

            cout << "Enter position : ";
            cin >> position;

            n = insertElement(arr, n, element, position);
            break;

        case 3:
            cout << "Enter position to delete : ";
            cin >> position;

            n = deleteElement(arr, n, position);
            break;

        case 4:
            cout << "Enter key element to search : ";
            cin >> key;

            searchElement(arr, n, key);
            break;

        case 5:
            cout << "Program ended" << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 5);

    return 0;
}