#include <bits/stdc++.h>
using namespace std;
const int MD = 1001; 
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ell "\n"
#define f first
#define s second
#define pb push_back
#define forl(n) for (int i = 0; i < n; i++)
typedef long long ll; 
#define MAX 1500

int n, m, k; 


int grid[MAX+1][MAX+1]; 
int dist[MAX+1][MAX+1]; 
pair<int, pair<int, int>> c[MAX+1]; 
queue<pair<int, int>> q; 

void bfs(){
    for (int i = 0; i < z; i++){
        q.push({c[i].f.f, c[i].f.s}); 
    }
    pair<int, int> cur; 
    while(!q.empty()){
        cur = q.front(); 
        q.pop(); 

        if (c.f+1 <= m && grid[c.f+1][c.s] == 0  && dist[c.f][c.s] < k){
            grid[c.f+1][c.s] = grid[c.f][c.s]; 
            q.push({c.f+1, c.s}); 
            dist[c.f+1][c.s] = dist[c.f][c.s];
        }
       if (c.f-1 <= m && grid[c.f-1][c.s] == 0  && dist[c.f][c.s] < k){
            grid[c.f-1][c.s] = grid[c.f][c.s]; 
            q.push({c.f-1, c.s}); 
            dist[c.f-1][c.s] = dist[c.f][c.s];
        }
        if (c.f+1 <= m && grid[c.f+1][c.s] == 0  && dist[c.f][c.s] < k){
            grid[c.f+1][c.s] = grid[c.f][c.s]; 
            q.push({c.f+1, c.s}); 
            dist[c.f+1][c.s] = dist[c.f][c.s];
        }
    }
}

int main(){
    inputJunk 
    cin >> n >> m >> k;  
    int z = 0; 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[j][i]; 
            if (grid[j][i] != 0){
                pair<int, pair<int, int>> thing = {grid[j][i], {i, j}}; 
                c[z++] = thing;
                dist[j][i] == 0;  
            }
        }
    }

    bfs();

    sort(c, c+(n*m), greater<pair<int, pair<int, int>>>()); 
    
    for (int i = 0; i < z; i++){
        cout << c[i].f << endl; 
    }



}