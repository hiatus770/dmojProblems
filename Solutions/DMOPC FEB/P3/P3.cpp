#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ell "\n"
#define f first
#define s second
#define pb push_back
#define forl(n) for (int i = 0; i < n; i++)
typedef long long ll; 
typedef pair<int, int> pInt; 
#define MAX 1505

int n, m, k, z, dist; 

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1}; 

ll grid[MAX][MAX]; 
//pair<ll, pair<int, int>> c[MAX]; 
vector<pair<int, pInt>> c; 
queue<pair<int, pair<int, int>>> q; 

void bfs(){
    for (int i = 0; i < c.size(); i++){
        //cout << c[i].f << endl; 
        q.push({0,{c[i].s.f, c[i].s.s}}); 
    }
    pair<int, pInt> cur; 
    while(!q.empty()){
        cur = q.front(); 
        q.pop(); 
        //cout << "NODE: " << cur.s.f << " " << cur.s.s << " VAL:" << grid[cur.s.f][cur.s.s] << endl; 
        int x = cur.s.f;
        int y = cur.s.s;
        dist = cur.f; 
        
        if (dist < k){
            forl(4){
                if (x + dx[i] >= 1 && x + dx[i] <= m && y + dy[i] >= 1 && y + dy[i] <= n && grid[x+dx[i]][y+dy[i]] == 0){
                    //cout << "PUSHING: " << x + dx[i] << " " << y + dy[i] << " " << dist+1 << endl; 
                    grid[x+dx[i]][y+dy[i]] = grid[x][y]; 
                    q.push({dist+1, {x+dx[i], y+dy[i]}}); 
                }
            }   
        }
    }
}

int main(){
    inputJunk 
    cin >> n >> m >> k;  
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> grid[j][i]; 
            if (grid[j][i] != 0){
                c.push_back({grid[j][i], {j, i}}); 
            }
        }
    }
    sort(c.begin(), c.end()); 
    bfs();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (j != m){
                cout << grid[j][i] << " "; 
            } else {
                cout << grid[j][i]; 
            }
        }
        cout << endl; 
    }
}
