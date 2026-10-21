#include <iostream>
using namespace std;
struct Node
{
    int patient;
    Node* next;
};
int main()
{
    Node* front = NULL;
    Node* rear = NULL;
    int choice, patient;
    while (true)
    {
        cout << "\n1. Arrive";
        cout << "\n2. Attend";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter patient number: ";
            cin >> patient;
            Node* newNode = new Node;
            newNode->patient = patient;
            newNode->next = NULL;
            if (front == NULL)
            {
                front = newNode;
                rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
            cout << "Patient added.\n";
        }
        else if (choice == 2)
        {
            if (front == NULL)
            {
                cout << "No patients to attend.\n";
            }
            else
            {
                Node* temp = front;
                cout << "Patient attended = "
                     << front->patient << endl;
                front = front->next;
                delete temp;
                if (front == NULL)
                {
                    rear = NULL;
                }
            }
        }
        else if (choice == 3)
        {
            if (front == NULL)
            {
                cout << "Queue is empty.\n";
            }
            else
            {
                Node* temp = front;
                cout << "Front patient = "
                     << front->patient << endl;
                cout << "Queue: ";
                while (temp != NULL)
                {
                    cout << temp->patient << " ";
                    temp = temp->next;
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