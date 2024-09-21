#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj_list, int s)
{
    int n = adj_list.size();
    vector<int> dist_to(n, INT_MAX);
    vector<int> parent(n);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist_to[s] = 0;

    for(int i=0;i<n;i++) {
        parent[i] = i;
    }

    pq.push({0, s});

    while (!pq.empty())
    {
        int curr = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        for (auto adj : adj_list[curr])
        {
            int v = adj.second;
            int wt = adj.first;

            if (dist + wt < dist_to[v])
            {
                dist_to[v] = dist + wt;
                // Why to hold all other distance for node v, {.., v} if we have found more optimal one?, 
                // This can be optimize by using set and erase all other
                // By default, the std::set is sorted in ascending order. 
                // However, we have the option to change the sorting order by using the following syntax.
                // std::set <data_type, greater<data_type>> set_name;
                pq.push({dist_to[v], v});

                parent[v] = curr;
            }
        }
    }

    return dist_to;
}

int main()
{
    int v = 9;
    int s = 0;
    vector<vector<int>> edges = {{0, 1, 4}, {0, 7, 8}, {1, 7, 11}, {1, 2, 8}, 
                                 {7, 6, 1}, {7, 8, 7}, {2, 8, 2}, {8, 6, 6}, 
                                 {2, 3, 7}, {2, 5, 4}, {6, 5, 2}, {3, 5, 14}, 
                                 {3, 4, 9}, {5, 4, 10}};
    vector<vector<pair<int, int>>> adj(v);

    for (auto edge : edges)
    {
        // {weight, other end}
        adj[edge[0]].push_back(make_pair(edge[2], edge[1]));
        adj[edge[1]].push_back(make_pair(edge[2], edge[0]));
    }
    vector<int> distance = dijkstra(adj, s);
    for (int i = 0; i < distance.size(); i++)
    {
        cout << i << ": " << distance[i] << endl;
    }
}
