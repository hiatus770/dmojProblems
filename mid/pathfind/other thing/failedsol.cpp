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
#define mxn 100000*5

ll n, m, k; 
set<ll> vis; // the unique lleger thing 
map<ll, vector<ll>> adj; // the adj list for a given unique lleger -1 means adjacent to left border, -2 means adjacent to right border, -3 means adjacent to top, -4 is bottom
queue<ll> q; // some queue for the graph traversal 

bool bfs(ll id){
    bool top = false; bool bottom = false; bool left = false; bool right = false; 
    ll cur; 
    q.push(id); 
    while(!q.empty()){
        cur = q.front(); q.pop();
        vis.insert(cur);  
        cout << "VISITING " << cur << endl;
        for( ll i : adj[cur]){
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
            if (vis.find(i) == vis.end() && adj.find(i) != adj.end()) {
                cout << "PUSHING " << i << endl; 
                q.push(i); // push the new thing in to the queue
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
        ll id = (x*mxn)+y; 
        adj[id]; 

        if (x == 1){
            adj[id].pb(-1); 
        }
        if (x == n){
            adj[id].pb(-2); 
        }
        if (y == m){
            adj[id].pb(-3);             
        }
        if (y == 1){
            adj[id].pb(-4);
        }

        // Append the coordinates  around it except the border ones whihch have already been appended 
        ll xa[] = {1, -1, 0, 0, -1, 1, -1, 1}; ll ya[]={0, 0, -1, 1, 1, 1, -1, -1}; 

        for(int i = 0; i < 8; i++){
            if (x+xa[i] <= n && x+xa[i] >= 1 && y+ya[i] <= m && y+ya[i] >= 1){
                adj[id].pb((x+xa[i])*mxn + y+ya[i]);
                // cout << "ADJ FOR " << x << " " << y << " IS " << x+xa[i] << " " << y+ya[i] << endl; 
            }
        }
    }
    for(auto i : adj){
        // cout << i.f << endl; 
        if (vis.find(i.f) == vis.end()){
            cout << "BFS FROM: " << i.f << endl;  
            if (bfs(i.f)){
                cout << "NO\n"; 
                return 0; 
            } 
        }
    }
    cout << "YES\n"; 
}