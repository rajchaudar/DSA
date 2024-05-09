#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
private:
    int size;
    vector<vector<int>> adjacency_matrix;
    vector<int> visited1;
    vector<int> visited2;
    vector<string> cities;
    char ch;

public:
    Graph()
    {
        cout << "Total Number of Cities:- ";
        cin >> size;
        cout << endl;
        adjacency_matrix.resize(size, vector<int>(size, 0));
        visited1.resize(size, 0);
        visited2.resize(size, 0);
        cities.resize(size);
    }
    void take_cities()
    {
        for (int m = 0; m < size; m++)
        {
            cout << "Enter City " << m + 1 << " Name:- ";
            cin >> cities[m];
        }
    }
    void take_flight()
    {
        for (int i = 0; i < size; i++)
        {
            adjacency_matrix[i][i] = 0;
            for (int j = i + 1; j < size; j++)
            {
                cout << "\nis their flight between " << cities[i] << " to " << cities[j] << " (y/n):- ";
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    cout << "Enter flight time/cost :- ";
                    cin >> adjacency_matrix[i][j];
                    adjacency_matrix[j][i] = adjacency_matrix[i][j];
                }
                else
                {
                    adjacency_matrix[i][j] = 0;
                    adjacency_matrix[j][i] = 0;
                }
            }
        }
    }
    void DFS_traversal()
    {
        stack<string> DFS_stack;
        DFS_stack.push(cities[0]);
        visited2[0] = 1;
        while (!DFS_stack.empty())
        {
            string city = DFS_stack.top();
            DFS_stack.pop();
            cout << city << "\t\t";
            for (int i = 0; i < size; i++)
            {
                if (cities[i] == city)
                {
                    for (int j = 0; j < size; j++)
                    {
                        if (adjacency_matrix[i][j] && !visited2[j])
                        {
                            DFS_stack.push(cities[j]);
                            visited2[j] = 1;
                        }
                    }
                }
            }
        }
        cout << endl;
    }
    void BFS_traversal()
    {
        queue<string> BFS_queue;
        BFS_queue.push(cities[0]);
        visited1[0] = 1;
        while (!BFS_queue.empty())
        {
            string city = BFS_queue.front();
            BFS_queue.pop();
            cout << city << "\t\t";
            for (int i = 0; i < size; i++)
            {
                if (cities[i] == city)
                {
                    for (int j = 0; j < size; j++)
                    {
                        if (adjacency_matrix[i][j] && !visited1[j])
                        {
                            BFS_queue.push(cities[j]);
                            visited1[j] = 1;
                        }
                    }
                }
            }
        }
    }
    void display_adje()
    {
        cout << endl
             << endl;
        cout << "adjecency matrix--->" << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << adjacency_matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }
    void display_visited1()
    {
        cout << "Visited matrix--->" << endl;
        for (int v = 0; v < size; v++)
        {
            cout << visited1[v] << "\t";
        }
    }
    void display_visited2()
    {
        cout << "Visited matrix--->" << endl;
        for (int v = 0; v < size; v++)
        {
            cout << visited2[v] << "\t";
        }
    }
    int is_connected1()
    {
        for (int s = 0; s < size; s++)
        {
            if (visited1[s] != 1)
            {
                return -1;
            }
        }
        return 1;
    }
    int is_connected2()
    {
        for (int s = 0; s < size; s++)
        {
            if (visited2[s] != 1)
            {
                return -1;
            }
        }
        return 1;
    }
};
int main()
{
    Graph G1;
    G1.take_cities();
    G1.take_flight();

    G1.display_adje();
    cout << "\n\nusing BFS--->" << endl;
    G1.display_visited1();
    cout << endl;
    G1.BFS_traversal();
    cout << endl;
    G1.display_visited1();
    cout << endl;
    if (G1.is_connected1() == 1)
    {
        cout << "\nGraph is connected " << endl;
    }
    else
    {
        cout << "\nGraph is not connected " << endl;
    }
    cout << endl;
    cout << "\n\nusing DFS--->" << endl;
    G1.display_visited2();
    cout << endl;
    G1.DFS_traversal();
    G1.display_visited2();
    cout << endl;
    if (G1.is_connected2() == 1)
    {
        cout << "\nGraph is connected " << endl;
    }
    else
    {
        cout << "\nGraph is not connected " << endl;
    }
    return 0;
}
