#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, ll>>> graph(N + 1);
    int cnt = 0;
    while(cnt < M) {
        int A, B;
        ll W;
        cin >> A >> B >> W;
        graph[A].push_back({B, W});
        cnt++;
    }
    int S, T;
    cin >> S >> T;
    vector<ll> capacity(N + 1, 0);
    vector<int> parent(N + 1, -1);
    priority_queue<pair<ll, int>> pq;
    capacity[S] = INF;
    pq.push({capacity[S], S});
    while(!pq.empty()){
        ll cap = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(cap < capacity[u])
            continue;
        auto it = graph[u].begin();
        while(it != graph[u].end()){
            int v = it->first;
            ll weight = it->second;
            ll cand = min(capacity[u], weight);
            if(cand > capacity[v]){
                capacity[v] = cand;
                parent[v] = u;
                pq.push({capacity[v], v});
            }
            it++;
        }
    }
    if(capacity[T] == 0) {
        cout << "No path from " << S << " to " << T << " exists.\n";
        return 0;
    }
    vector<int> path;
    int cur = T;
    while(cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());
    cout << "Maximum capacity from " << S << " to " << T << " is " << capacity[T] << "\n";
    cout << "Path: ";
    for(int i = 0; i < path.size(); i++)cout << path[i] << " ";

}
