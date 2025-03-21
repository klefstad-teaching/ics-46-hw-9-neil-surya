#include "dijkstras.h"
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <limits>
#include <fstream>
using namespace std;

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.size();
    vector<int> distance(n, INF);
    previous.assign(n, -1);
    distance[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (const Edge& e : G[u]) {
            int v = e.dst;
            int weight = e.weight;
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                pq.push({distance[v], v});
            }
        }
    }
    return distance;
}
vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;
    if (destination < 0 || distances[destination] == INF)
        return path;
    stack<int> s;
    for (int v = destination; v != -1; v = previous[v]) {
        s.push(v);
        if (v == previous[v]) break;
    }
    while (!s.empty()) {
        path.push_back(s.top());
        s.pop();
    }
    return path;
}
void print_path(const vector<int>& v, int total) {
    if (total == INF) {
        cout << "No path found!" << endl;
        return;
    }
    for (auto e: v)
        cout << e << " ";
    cout << endl;
    cout << "Total cost is " << total << endl;
}
