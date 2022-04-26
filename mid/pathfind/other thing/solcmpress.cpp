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
#define mxn 5*10e5

int n, m, k; 
set<int> vis; // the unique integer thing 
map<int, vector<int>> adj; // the adj list for a given unique integer -1 means adjacent to left border, -2 means adjacent to right border, -3 means adjacent to top, -4 is bottom
queue<int> q; // some queue for the graph traversal 

bool bfs(int id){
    bool one = false; bool two = false; 
    int cur; 
    q.push(id); 
    while(!q.empty()){
        cur = q.front(); q.pop();
        vis.insert(cur);  
        for( int i : adj[cur]){
            // cout << i << " is adj to " << cur << endl; 
            // cout << one << two << endl;
            if (i == -2){
                two = true; 
            } 
            if (i == -1){
                one = true; 
  
            // check if its a blocked square, then push it to the queue if it is and if its not visited
            }
            if (vis.count(i) == 0 && adj.count(i) == 1) {
                q.push(i); // push the new thing in to the queue
            }
            if (one && two){
                return true; 
            }
        }
    }
    return false; 
}

int main(){
    inputJunk; 
    cin >> n >> m >> k; 
    forl(k){
        int x, y; 
        cin >> x >> y;
        int id = (x*mxn)+(y); 
        adj[id]; 
        if (x == 1){
            adj[id].pb(-1); 
            // cout <<  x << " " << y << " IS TOUCHING BORDER " << endl; 
        }
        if (x == n){
            adj[id].pb(-2); 
            // cout <<  x << " " << y << " IS TOUCHING BORDER " << endl;
        }
        if (y == m){
            adj[id].pb(-1); 
            // cout <<  x << " " << y << " IS TOUCHING BORDER " << endl;
            
        }
        if (y == 1){
            adj[id].pb(-2);
            // cout <<  x << " " << y << " IS TOUCHING BORDER " << endl;
        }

        // Append the coordinates  around it except the border ones whihch have already been appended 
        int xa[] = {1, -1, 0, 0, -1, 1, -1, 1}; int ya[]={0, 0, -1, 1, 1, 1, -1, -1}; 

        for(int i = 0; i < 8; i++){
            if (x+xa[i] <= n && x+xa[i] >= 1 && y+ya[i] <= m && y+ya[i] >= 1){
                adj[id].pb((x+xa[i])*mxn + y+ya[i]);
                // cout << "ADJ FOR " << x << " " << y << " IS " << x+xa[i] << " " << y+ya[i] << endl; 
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

/* 
Commments on how to solve 

- rn just make the input part work
- Convert to unique int x*mX+y  
- For those coordinates make an adjacency map vector thing 
- run a dfs with that adj list 
- see what walls it touches with and run the four cases...
- 
*/