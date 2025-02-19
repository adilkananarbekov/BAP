#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
vector<vector<int>> adj;
int dfs(int node, int parent) {
    int cnt = 1; 
    for (int child : adj[node]) {
        if (child == parent) continue;
        int subtreeSize = dfs(child, node);
        if (subtreeSize % 2 == 0)
            ans++;
        cnt += subtreeSize;
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cin >> n;
    if(n % 2 != 0){
        cout << -1;
        return 0;
    }
    adj.resize(n + 1);
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans;
}
