#include <iostream>
using namespace std;

int main()
{
    int a[100], n, choice, temp, min;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\n1. Bubble Sort";
    cout << "\n2. Selection Sort";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (a[j] > a[j + 1])
                    {
                        temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                }
            }
            cout << "Bubble Sort: ";
            break;

        case 2:
            for (int i = 0; i < n - 1; i++)
            {
                min = i;

                for (int j = i + 1; j < n; j++)
                {
                    if (a[j] < a[min])
                        min = j;
                }

                temp = a[i];
                a[i] = a[min];
                a[min] = temp;
            }
            cout << "Selection Sort: ";
            break;

        default:
            cout << "Invalid choice!";
            return 0;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
