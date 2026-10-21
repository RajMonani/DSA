#include <iostream>
using namespace std;
int main()
{
    int stack[5];
    int top = -1;
    int choice, value;
    while (true)
    {
        cout << "\n1. Push Tray";
        cout << "\n2. Pop Tray";
        cout << "\n3. Display Stack";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter tray number: ";
            cin >> value;
            if (top == 4)
            {
                cout << "Stack is full. Cannot add tray.\n";
            }
            else
            {
                top++;
                stack[top] = value;
                cout << "Tray added.\n";
                cout << "Current top = " << stack[top] << endl;
            }
        }
        else if (choice == 2)
        {
            if (top == -1)
            {
                cout << "Stack is empty. Cannot remove tray.\n";
            }
            else
            {
                cout << "Removed tray = " << stack[top] << endl;
                top--;
                if (top == -1)
                {
                    cout << "Stack is now empty.\n";
                }
                else
                {
                    cout << "Current top = " << stack[top] << endl;
                }
            }
        }
        else if (choice == 3)
        {
            if (top == -1)
            {
                cout << "Stack is empty.\n";
            }
            else
            {
                cout << "Stack from top to bottom: ";
                for (int i = top; i >= 0; i--)
                {
                    cout << stack[i] << " ";
                }
                cout << endl;
                cout << "Current top = " << stack[top] << endl;
            }
        }
        else if (choice == 4)
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