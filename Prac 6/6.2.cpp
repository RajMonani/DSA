#include <iostream>
using namespace std;

struct Node
{
    string page;
    Node* next;
};
int main()
{
    Node* top = NULL;
    int choice;
    string page;
    while (true)
    {
        cout << "\n1. Visit Page";
        cout << "\n2. Back";
        cout << "\n3. Show Current Page";
        cout << "\n4. Show History";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter page name: ";
            cin >> page;
            Node* newNode = new Node;
            newNode->page = page;
            newNode->next = top;
            top = newNode;
            cout << "Visited page: " << page << endl;
            cout << "Current page = " << top->page << endl;
        }
        else if (choice == 2)
        {
            if (top == NULL)
            {
                cout << "No page history. Cannot go back.\n";
            }
            else
            {
                cout << "Going back from: " << top->page << endl;
                Node* temp = top;
                top = top->next;
                delete temp;
                if (top == NULL)
                {
                    cout << "No previous page available.\n";
                }
                else
                {
                    cout << "Current page = " << top->page << endl;
                }
            }
        }
        else if (choice == 3)
        {
            if (top == NULL)
            {
                cout << "No page is open.\n";
            }
            else
            {
                cout << "Current page = " << top->page << endl;
            }
        }
        else if (choice == 4)
        {
            if (top == NULL)
            {
                cout << "History is empty.\n";
            }
            else
            {
                Node* temp = top;
                cout << "Page history: ";
                while (temp != NULL)
                {
                    cout << temp->page << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}