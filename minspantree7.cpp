#include <iostream>
#include <vector>
#include <string>
using namespace std;

void primsMST(int n, vector<vector<int>> &cost)
{
    vector<int> visit(n, 0);
    int mincost = 0;
    int s;
    cout << "\n\nEnter Starting Vertex (1 to " << n << "): ";
    cin >> s;
    s--;
    visit[s] = 1;
    cout << "\nSelected Edges in MST:" << endl;
    for (int k = 0; k < n - 1; k++)
    {
        int min = 999;
        int row = -1, col = -1;
        for (int i = 0; i < n; i++)
        {
            if (visit[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (visit[j] == 0 && cost[i][j] != -1 && min > cost[i][j])
                    {
                        min = cost[i][j];
                        row = i;
                        col = j;
                    }
                }
            }
        }
        if (row != -1 && col != -1)
        {
            cout << "Edge: " << row + 1 << " - " << col + 1 << endl;
            mincost += min;
            visit[col] = 1;
            cost[row][col] = -1;
            cost[col][row] = -1;
        }
        else
        {
            cout << "Error: Unable to find valid edge." << endl;
            break;
        }
    }
    cout << "\nTotal Min Cost: " << mincost << endl;
}

int main()
{
    int n;
    cout << "\nEnter the number of cities: ";
    cin >> n;
    cout << endl;
    string cities[n];
    vector<vector<int>> cost(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        cout << "Enter city " << i + 1 << ":- ";
        cin >> cities[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            char op;
            cout << "\nIs there an connection between " << cities[i] << " and " << cities[j] << " (y/n)?:- ";
            cin >> op;
            if (op == 'y' || op == 'Y')
            {
                cout << "Enter Cost: ";
                cin >> cost[i][j];
                cost[j][i] = cost[i][j];
            }

            else
            {
                cost[i][j] = cost[j][i] = -1;
            }
        }
    }
    cout << endl;
    primsMST(n, cost);
    return 0;
}
