#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    Node* left;
    Node* right;
};

Node* createNode(string name)
{
    Node* newNode = new Node;
    newNode->name = name;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->name << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->name << " ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->name << " ";
}

void levelOrder(Node* root)
{
    if (root == NULL)
        return;

    Node* q[100];
    int front = 0, rear = 0;

    q[rear++] = root;

    while (front < rear)
    {
        Node* temp = q[front++];
        cout << temp->name << " ";

        if (temp->left != NULL)
            q[rear++] = temp->left;

        if (temp->right != NULL)
            q[rear++] = temp->right;
    }
}

int main()
{
    string ceo, manager1, manager2;
    string employee1, employee2, employee3, employee4;

    cout << "Enter CEO name: ";
    cin >> ceo;

    cout << "Enter first manager name: ";
    cin >> manager1;

    cout << "Enter second manager name: ";
    cin >> manager2;

    cout << "Enter first employee name: ";
    cin >> employee1;

    cout << "Enter second employee name: ";
    cin >> employee2;

    cout << "Enter third employee name: ";
    cin >> employee3;

    cout << "Enter fourth employee name: ";
    cin >> employee4;

    Node* root = createNode(ceo);

    root->left = createNode(manager1);
    root->right = createNode(manager2);

    root->left->left = createNode(employee1);
    root->left->right = createNode(employee2);

    root->right->left = createNode(employee3);
    root->right->right = createNode(employee4);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nLevel Order: ";
    levelOrder(root);

    cout << endl;

    return 0;
}