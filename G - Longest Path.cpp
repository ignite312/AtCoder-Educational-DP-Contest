/*
Problem Name: G - Longest Path
Problem Link: https://atcoder.jp/contests/dp/tasks/dp_g
Idea: 
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
vector<int> adj[N+1];
int visited[N+1], longest_path[N+1];

void dfs(int u) {
  visited[u] = true;
  for(auto v : adj[u]) {
    if(!visited[v])dfs(v);
    longest_path[u] = max(longest_path[u], longest_path[v]+1);
  }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
          int u, v;
          cin >> u >> v;
          adj[u].push_back(v);
        }
        for(int i = 1; i <= n; i++) {
          if(!visited[i]) {
            dfs(i);
          }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
          ans = max(ans, longest_path[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}