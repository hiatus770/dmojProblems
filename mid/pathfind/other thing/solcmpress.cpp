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

bool bfs(int startx, int starty){
    bool top = false; bool bottom = false; bool left = false; bool right = false; 

}

int main(){
    inputJunk; 
    cin >> n >> m >> k; 
    forl(k){
        int x, y; bool top = false; bool bottom = false; bool left = false; bool right = false; 
        cin >> x >> y;
        if (x == 1){
            // cout << "Left\n"; 
            
        }
        if (x == n){
            // cout << "Right\n";
             
        }
        if (y == m){
            // cout << "Bottom\n";
             
        }
        if (y == 1){
            // cout << "Top\n";
             
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
- see what walls it touches with and run the four cases :')


*/