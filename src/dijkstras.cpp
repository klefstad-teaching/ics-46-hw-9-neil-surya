#include <iostream>
#include <vector>
#include <algorithms>

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous);
vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination);
void print_path(const vector<int>& v, int total) {
    for (auto e: v) {
        cout << e << " ";
        total += e;
    }
    cout << "Total cost is " << total << endl;
}
