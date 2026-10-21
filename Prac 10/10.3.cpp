#include <iostream>
using namespace std;

int main()
{
    int table[10];

    for (int i = 0; i < 10; i++)
    {
        table[i] = -1;
    }

    int n, id;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter student ID: ";
        cin >> id;

        int h1 = id % 10;

        int steps[4] = {1, 3, 7, 9};
        int h2 = steps[id % 4];

        int index;
        bool inserted = false;

        for (int j = 0; j < 10; j++)
        {
            index = (h1 + j * h2) % 10;
            if (table[index] == -1)
            {
                table[index] = id;
                inserted = true;
                break;
            }
        }
        if (!inserted)
        {
            cout << "Hash table is full for ID "
                 << id << "!\n";
        }
    }
    cout << "\nFinal Hash Table:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << i << " : " << table[i] << endl;
    }
    return 0;
}