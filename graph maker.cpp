#include<bits/stdc++.h>
using namespace std;
void connectConst(int cur, vector<set<int>> &graph) {
    int minDeg = numeric_limits<int>::max();
    int chosen = -1;
    for (int x = 1; x <= 4; x++) {
        if (x == cur)
            continue;
        int deg = graph[x].size();
        if (deg < minDeg) {
            minDeg = deg;
            chosen = x;
        }
    }
    if (chosen != -1) {
        graph[cur].insert(chosen);
        graph[chosen].insert(cur);
    }
}
int main() {
    int n;
    cout << "How many vertices we'll add: ";
    cin >> n;
    int totalVertices = 4 + n;
    vector<set<int>> graph(totalVertices + 1);
    for (int i = 5; i <= totalVertices; i++) {
        for (int j = 5; j <= totalVertices; j++) {
            if (i != j) {
                graph[i].insert(j);
            }
        }
    }
    for (int i = 1; i <= 4; i++) {
        for (int k = 0; k < 2; k++) {
            if (graph[i].size() < 2) {
                int minDeg = numeric_limits<int>::max();
                int chosen = -1;
                for (int x = 5; x <= totalVertices; x++) {
                    int deg = graph[x].size();
                    if (deg < minDeg) {
                        minDeg = deg;
                        chosen = x;
                    }
                }
                if (totalVertices > 4) {
                    if (graph[chosen].find(i) == graph[chosen].end()) {
                        graph[i].insert(chosen);
                        graph[chosen].insert(i);
                    } else {
                        connectConst(i, graph);
                    }
                } else {
                    connectConst(i, graph);
                }
            }
        }
    }
    for (int i = 1; i <= totalVertices; i++) {
        for (int neighbor : graph[i]) {
            if (neighbor > i) { 
                cout << i << " " << neighbor << endl;
            }
        }
    }
}
