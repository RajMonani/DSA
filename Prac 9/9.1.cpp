#include <iostream>
#include <queue>
using namespace std;
int graph[10][10] = {0};
int n;
void DFS(int node, int visited[])
{
    cout << node << " ";
    visited[node] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] == 1 && visited[i] == 0)
        {
            DFS(i, visited);
        }
    }
}
void BFS(int start)
{
    int visited[10] = {0};
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}
int main()
{
    int edges, u, v, start;
    int visited[10] = {0};

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of roads: ";
    cin >> edges;

    cout << "Enter connected nodes:\n";

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start, visited);

    cout << "\nBFS Traversal: ";
    BFS(start);

    cout << endl;
    return 0;
}