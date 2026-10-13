#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *createTree()
{
    int value;

    cout << "Enter data : ";
    cin >> value;

    if (value == -1)
        return NULL;

    Node *root = createNode(value);

    cout << "Enter left child of " << value << endl;
    root->left = createTree();

    cout << "Enter right child of " << value << endl;
    root->right = createTree();

    return root;
}

void inorder(Node *root)
{
    Node *s[100];
    int top = -1;
    Node *current = root;

    while (current != NULL || top != -1)
    {
        while (current != NULL)
        {
            s[++top] = current;
            current = current->left;
        }

        current = s[top--];
        cout << current->data << " ";
        current = current->right;
    }
}

int main()
{
    Node *root = createTree();

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}