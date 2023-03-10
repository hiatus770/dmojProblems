#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ell "\n";
#define f first
#define s second
#define pb push_back
#define forl(n) for (int i = 0; i < n; i++)
typedef long long ll; 
typedef pair<int, int> pInt; 
#define mxn 1005
#define INF 10000000

ll n, m; 
vector<pair<ll, ll>> adj[mxn];
bool visited[mxn]; 
ll dist[mxn]; 
priority_queue<pair<ll, ll>> q; 


int main(){
    cin >> n >> m; 
    for (int i = 0; i < m; i++){
        int a, b, c; 
        cin >> a >> b >> c; 
        adj[a].push_back({b, c}); 
        adj[b].push_back({a, c});
    }

    for(int i = 1; i <= 1000; i++) {dist[i] = INF;}  

    dist[1] = 0; 
    q.push({0, 1}); /* distance  node */ 

    while(!q.empty()){
        ll a = q.top().second; q.pop(); 

        if (visited[a]) continue; 
        
        visited[a] = true; 

        for (auto u : adj[a]){
            ll b = u.f, w = u.s; 
            if (dist[a]+w < dist[b]){
                dist[b] = dist[a] + w; 
                q.push({-dist[b],b}); 
            }
        }

    }
    
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cout << "-1\n"; 
        } else {
            cout << dist[i] << ell
        }
    }
}