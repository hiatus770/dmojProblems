#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); // cout.tie(0);
#define ell "\n";
#define f first
#define s second
#define pb push_back
#define forl(n) for (int i = 0; i < n; i++)
typedef long long ll; 
typedef pair<int, int> pInt; 
#define mxn 500005
#define has(x) (adj.find(x) != adj.end())
ll n, m, k; 
set<ll> vis; // the unique integer thing 
map<ll, vector<ll>> adj; // the adj list for a given unique integer -1 means adjacent to left border, -2 means adjacent to right border, -3 means adjacent to top, -4 is bottom
queue<ll> q; // some queue for the graph traversal 
ll b = -1; // bottom side 
ll t = -2; // top side 

int main(){
    inputJunk; 
    cin >> n >> m >> k; 
    for(int i = 0; i < k; i++){
        ll x, y; 
        cin >> x >> y; x--; y--; 

        ll id = (y*n)+(x);
        adj[id] = vector<ll>(); 

        if (x == 0 || y == n-1){ // lower
            adj[id].pb(b); 
        }
        if (x == m-1 || y == 0){ // upper 
            adj[t].pb(id); 
        }
    }

    ll pos; 
    for (auto p : adj){
        pos = p.first; 
        if (pos%n != n-1){
            if (has(pos+1)){
                adj[pos].pb(pos+1); 
            }
            if (has(pos+1-n)){
                adj[pos].pb(pos+1-n); 
            }
            if (has(pos+1+n)){
                adj[pos].pb(pos+1+n); 
            }
        }
        if (pos%n != 0){
            if (has(pos-1)){
                adj[pos].pb(pos-1); 
            }
            if (has(pos-1-n)){
                adj[pos].pb(pos-1-n); 
            }
            if (has(pos-1+n)){
                adj[pos].pb(pos-1+n); 
            }
        }
        if (has(pos+n)){
            adj[pos].pb(pos+n); 
        }
        if (has(pos-n)){
            adj[pos].pb(pos-n); 
        }
    }

    ll cur; 
    q.push(t); vis.insert(t); 
    while(!q.empty()){
        cur = q.front(); q.pop(); 
        if (cur == b){
            cout << "NO\n"; return 0; 
        }
        for(ll &i : adj[cur]){
            if (vis.find(i) == vis.end()) {
                vis.insert(i);
                q.push(i); // push the new thing in to the queue
            }
        }
    }
    
    cout << "YES\n"; 
}
