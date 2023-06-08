#include <iostream>
#include <vector>
using namespace std;

// Function to get the index of the minimum value in 'values' vector
int getMin(vector<bool> &isVisit, vector<int> &values)
{
    int minIndex = INT_MAX;
    int minVal = INT_MAX;

    // Iterate through the 'values' vector
    for (int i = 0; i < values.size(); i++)
    {
        // Check if the value is not visited and less than the current minimum
        if (isVisit[i] == false && values[i] < minVal)
        {
            minVal = values[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to print the Minimum Spanning Tree (MST)
void printMST(vector<int> &parent, vector<vector<int>> &graph)
{
    int totalWeight = 0;
    cout << "Edge \tWeight\n";
    for (int i = 1; i < parent.size(); i++)
    {
        totalWeight += graph[i][parent[i]];
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }
    cout << endl;
    cout << "Total Weight: " << totalWeight << endl;
}

// Function to find the Minimum Spanning Tree (MST) using Prim's algorithm
void MST(vector<vector<int>> &graph, int start)
{
    int v = graph.size();
    vector<int> parent(v);
    vector<bool> isVisit(v, false);
    vector<int> values(v, INT_MAX);

    values[start] = 0;

    for (int nodes = 0; nodes < v - 1; nodes++)
    {
        int u = getMin(isVisit, values);
        isVisit[u] = true;

        for (int i = 0; i < v; i++)
        {
            if (graph[u][i] != 0 && isVisit[i] == false && graph[u][i] < values[i])
            {
                values[i] = graph[u][i];
                parent[i] = u;
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    // Define the graph using an adjacency matrix
    vector<vector<int>> graph = {{0, 3, 0, 0, 0, 1},
                                 {3, 0, 2, 1, 10, 0},
                                 {0, 2, 0, 3, 0, 5},
                                 {0, 1, 3, 0, 5, 0},
                                 {0, 10, 0, 5, 0, 4},
                                 {1, 0, 10, 0, 4, 0}};

    // Find and print the Minimum Spanning Tree (MST)
    MST(graph, 0);
    return 0;
}
