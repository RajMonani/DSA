#include <iostream>
using namespace std;

struct Node
{
    int code;
    Node* left;
    Node* right;
};

Node* createNode(int code)
{
    Node* newNode = new Node;
    newNode->code = code;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int code)
{
    if (root == NULL)
    {
        return createNode(code);
    }

    if (code < root->code)
    {
        root->left = insert(root->left, code);
    }
    else if (code > root->code)
    {
        root->right = insert(root->right, code);
    }
    else
    {
        cout << "Duplicate code not allowed.\n";
    }

    return root;
}

void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->code << " ";
    inorder(root->right);
}

int main()
{
    Node* root = NULL;
    int n, code;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter book code: ";
        cin >> code;

        root = insert(root, code);
    }

    cout << "\nBook codes in sorted order: ";
    inorder(root);

    cout << endl;

    return 0;
}