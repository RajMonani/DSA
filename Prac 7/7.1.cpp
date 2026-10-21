#include <iostream>
using namespace std;
int main()
{
    int queue[5];
    int front = 0;
    int rear = -1;
    int choice, token;
    while (true)
    {
        cout << "\n1. Join";
        cout << "\n2. Serve";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            if (rear == 4)
            {
                cout << "Queue is full.\n";
            }
            else
            {
                cout << "Enter token number: ";
                cin >> token;
                rear++;
                queue[rear] = token;
                cout << "Token added.\n";
            }
        }
        else if (choice == 2)
        {
            if (front > rear)
            {
                cout << "Queue is empty.\n";
            }
            else
            {
                cout << "Token served = " << queue[front] << endl;
                front++;
            }
        }
        else if (choice == 3)
        {
            if (front > rear)
            {
                cout << "Queue is empty.\n";
            }
            else
            {
                cout << "Queue: ";
                for (int i = front; i <= rear; i++)
                {
                    cout << queue[i] << " ";
                }
                cout << endl;
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