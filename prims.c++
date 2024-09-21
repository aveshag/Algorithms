#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int prims(vector<vector<pair<int, int>>> &adj)
{
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    int v = adj.size();
    int sum = 0;
    vector<bool> vis(v, false);

    // starting node
    pq.push({0, {0, -1}});

    while (!pq.empty())
    {
        pair<int, pair<int, int>> t = pq.top();
        pq.pop();
        int wt = t.first;
        int node = t.second.first;
        int parent = t.second.second;

        if (vis[node])
            continue;
        vis[node] = true;
        sum += wt;
        cout << parent << " --> " << node << " (" << wt << ")" << endl;

        for (auto adj_node : adj[node])
        {
            if (!vis[adj_node.second])
            {
                pq.push({adj_node.first, {adj_node.second, node}});
            }
        }
    }

    return sum;
}

int main()
{
    int v = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<pair<int, int>>> adj(v);

    for (auto edge : edges)
    {
        adj[edge[0]].push_back(make_pair(edge[2], edge[1]));
        adj[edge[1]].push_back(make_pair(edge[2], edge[0]));
    }
    int total_wt = prims(adj);
    cout << "Total weight: " << total_wt << endl;
}
