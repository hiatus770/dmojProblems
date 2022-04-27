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
#define mxn 500000

int n, m, k; 
set<ll> vis; // the unique integer thing 
map<ll, vector<ll>> adj; // the adj list for a given unique integer -1 means adjacent to left border, -2 means adjacent to right border, -3 means adjacent to top, -4 is bottom
queue<ll> q; // some queue for the graph traversal 
ll b = -10; // bottom side 
ll t = -11; // top side 

bool bfs(ll id){
    bool top = false; bool bottom = false; bool left = false; bool right = false; 
    ll cur; 
    q.push(id); 
    while(!q.empty()){
        cur = q.front(); q.pop();
        vis.insert(cur);  
        for( ll i : adj[cur]){
            if (vis.count(i) == 0){
                if (i == -2){
                    right = true; 
                } 
                if (i == -1){
                    left = true; 
                }
                if (i == -3){
                    bottom = true; 
                }
                if (i == -4){
                    top = true; 
                }
                if (bottom && top){
                    return true; 
                }
                if (top && left){
                    return true; 
                } 
                if (left && right){
                    return true; 
                }
                if (bottom && right){
                    return true; 
                }
                if (adj.find(id) != adj.end()) {
                    q.push(i); // push the new thing in to the queue
                }
            }
        }
    }
    return false; 
}

int main(){
    inputJunk; 
    cin >> n >> m >> k; 
    forl(k){
        ll x, y; 
        cin >> x >> y;
        ll id = (x*mxn)+(y); 

        if (x == 1 || y == m){
            adj[b].pb(id); 
        }
        if (x == n || y == 1){
            adj[t].pb(id); 
        }

        // Append the coordinates  around it except the border ones whihch have already been appended 
        ll xa[] = {1, -1, 0, 0, -1, 1, -1, 1}; 
        ll ya[]={0, 0, -1, 1, 1, 1, -1, -1}; 

        for(int i = 0; i < 8; i++){
            if (x+xa[i] <= n && x+xa[i] >= 1 && y+ya[i] <= m && y+ya[i] >= 1){
                adj[id].pb( (x+xa[i])*mxn + y+ya[i] );
            }
        }
    }
    for(auto i : adj){
        // cout << i.f << endl; 
        if (vis.count(i.f) == 0){
            if (bfs(i.f)){
                cout << "NO\n"; 
                return 0; 
            } 
        }
    }
    cout << "YES\n"; 
}