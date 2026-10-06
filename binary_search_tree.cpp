#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int info;
    struct node *left, *right;
};

struct node *root = NULL;

struct node *create_node(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *insert(struct node *root, int x)
{
    if (root == NULL)
    {
        return create_node(x);
    }

    if (x < root->info)
    {
        root->left = insert(root->left, x);
    }
    else if (x > root->info)
    {
        root->right = insert(root->right, x);
    }

    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->info << " ";
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->info << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->info << " ";
    }
}

int main()
{
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}