#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *first = NULL;

struct node *create_node(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    temp->data = x;
    temp->next = NULL;

    return temp;
}

void insert_last(int x)
{
    struct node *t = create_node(x);

    if (first == NULL)
    {
        first = t;
        return;
    }

    struct node *p = first;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = t;
}

void linear_search(int x)
{
    struct node *p = first;
    int pos = 1;

    while (p != NULL)
    {
        if (p->data == x)
        {
            cout << "Element found at position " << pos << endl;
            return;
        }

        p = p->next;
        pos++;
    }

    cout << "Element not found" << endl;
}

int main()
{
    int n, x, search;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> x;
        insert_last(x);
    }

    cout << "Enter element to search: ";
    cin >> search;

    linear_search(search);

    return 0;
}