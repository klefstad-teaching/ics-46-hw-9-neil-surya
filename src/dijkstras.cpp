#include <iostream>
#include <vector>
#include <algorithms>

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    vector<int> distances(G.numVertices, INF);
    previous.resize(G.numVertices, -1);
    distances[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    vector<bool> visited(G.numVertices, false);
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        for (const Edge& e : G[u] {
            int v = e.dst;
            int w = e.weight;
            if (!visited[v] && distances[u] != INF && distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
                previous[v] = u;
                pq.push({distances[v], v});
            }
        })
    }
    return distances;
}
vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    vector<int> path;
    for (int v = destination; v != -1; v = previous[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}
void print_path(const vector<int>& v, int total) {
    cout << "Path: ";
    for (auto e: v)
        cout << e << " ";
    cout << "Total cost is " << total << endl;
}
