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
#define mxn 5*10e5

int n, m, k; 
set<long long> pos; // the unique integer thing 
map<long long, vector<long long>> adj; // the adj list for a given unique integer -1 means adjacent to left border, -2 means adjacent to right border, -3 means adjacent to top, -4 is bottom
queue<long long> q; // some queue for the graph traversal 
map<long long, vector<bool>> border;  

bool bfs(int id){
    bool one = false; bool two = false;  
    int cur; 
    q.push(id); 
    while(!q.empty()){
        cur = q.front(); q.pop(); 
        for( auto i : adj[cur]){
            if (i == -2){
                two = true; 
            } else if (i == -1){
                one = true; 
            } else if (true) {

            }
        }
    }
    return true; 
}

int main(){
    inputJunk; 
    cin >> n >> m >> k; 
    forl(k){
        int x, y; 
        cin >> x >> y;
        long long id = x*mxn+y; 
        adj[id]; 
        if (x == 1){
            adj[id].append(-1); 
        }
        if (x == n){
            adj[id].append(-2); 
        }  
        if (y == m){
            adj[id].append(-1); 
        }
        if (y == 1){
            adj[id].append(-2);
        }

        // Append the coordinates  around it except the border ones whihch have already been appended 
        int xa[] = {1, -1, 0, 0, -1, 1, -1, 1}; int ya[]={0, 0, -1, 1, 1, 1, -1, -1}; 

        for(int i = 0; i < 8; i++){
            if (x+xa[i] < n && x+xa[i] > 1 && y+ya[i] < m && y+ya[i] > 1){
                adj[id].append(x+xa[i]*mxn + y+ya[i]);
                cout << "ADJ FOR " << x << " " << y << " IS " << x+xa[i] << " " << y+ya[i] << endl; 
            }
        }

        // if the number is in the set that means it is visited already, therefore dont put thmei nthe set now  :) 
    }
    
}

/* 
Commments on how to solve 

- rn just make the input part work

- Convert to unique int x*mX+y  
- For those coordinates make an adjacency map vector thing 
- run a dfs with that adj list 
- see what walls it touches with and run the four cases :')


*/