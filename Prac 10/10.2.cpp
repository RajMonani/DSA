#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> shelf[10];
    int n, code;
    cout << "Enter number of books: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter book code: ";
        cin >> code;
        int index = code % 10;
        shelf[index].push_back(code);
    }
    cout << "\nBooks on each shelf:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "Shelf " << i << ": ";
        if (shelf[i].empty())
        {
            cout << "Empty";
        }
        else
        {
            for (int j = 0; j < shelf[i].size(); j++)
            {
                cout << shelf[i][j] << " ";
            }
        }
        cout << endl;
    }
    int searchCode;
    cout << "\nEnter book code to search: ";
    cin >> searchCode;
    int index = searchCode % 10;
    bool found = false;
    for (int j = 0; j < shelf[index].size(); j++)
    {
        if (shelf[index][j] == searchCode)
        {
            found = true;
            break;
        }
    }
    if (found)
    {
        cout << "Book found!";
    }
    else
    {
        cout << "Book not found!";
    }
    return 0;
}