#include <bits/stdc++.h>
using namespace std;
const int MD = 1001; 
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define max 1501

int n, m, k; 

int grid[max+1][max+1]; 

struct colors{
    int x = 0; 
    int y = 0; 
    int col = 0; 
};

colors C[max*max]; 
colors C1[max*max]; 

bool sorter(colors const& l, colors const& r){
    if (l.col != r.col)
        return l.col > r.col;
    if (l.x != r.x)
        return l.x > r.x;
    return l.y > r.y;   
}

int main(){
    inputJunk 
    cin >> n >> m >> k; 
    int z = 0; 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> grid[j][i]; 
            if (grid[j][i] != 0){
                C[z].x = j; 
                C[z].col = grid[j][i]; 
                C[z++].y = i;   
            } 
        }
    }

    while(k > 0){
        sort(C, C + 1 + n+m, &sorter); 
        int r = 0; 
        for(int i = 0; i < n*m; i++){
            if (C[i].col <= 0){
                break; 
            }
            int x = C[i].x; 
            int y = C[i].y; 
            pair<int, int> offsets[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for (int o = 0; o < 4; o++){
                if (grid[x+offsets[o].first][y + offsets[o].second] == 0 && x+offsets[o].first <= m && x+offsets[o].first >= 0 && y+offsets[o].second <= n && y+offsets[o].second >= 0){
                    grid[x+ offsets[o].first][y+ offsets[o].second] = C[i].col;
                    C1[r].x = x + offsets[o].first;
                    C1[r].y = y + offsets[o].second;
                    C1[r++].col = C[i].col; 
                }
            }
        }
        // memset C to zero to remove all the other ones :)
        memset(C, 0, n*m);
        // reset the array into C from C1 to be able to use it again. 

        for(int i = 0; i < n*m; i++){
            C[i].col = C1[i].col; 
            C[i].x = C1[i].x;
            C[i].y = C1[i].y;
        }
        memset(C1, 0, n*m);
        
        k--;  
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << grid[j][i] << " ";
        }
        cout << endl; 
    } 
}