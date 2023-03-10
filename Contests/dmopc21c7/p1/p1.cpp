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
const int mxn = 1600; 

ll g[mxn][mxn]; // x y 
queue<pInt> q; 

int main(){

    int n, m; cin >> n >> m; bool mogus = true; 



    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];  
            if (g[i][j] <= j || g[i][j] <= i){
                if (g[i][j] != 0){
                    cout << "-1\n"; return 0; 
                }
            }
            if (g[i][j] == 0){
                q.push({i, j}); 
                //cout << "PUSHED " << i << " " << j << ell
            } else {
                mogus = false; 
            }
        }
    }


    if (mogus){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << i+j+1 << " "; 
            }
            cout << endl; 
        }
    } else if (n == 1 && m != 1) {

        for (int j = 0; j < m; j++){
            int next = g[0][j+1]; 
            //cout << g[i][j] << " " << next << ell
            if (g[0][j] > next && next != 0){
                // bad input
                cout << "-1\n"; return 0; 
            }
        }

        while(!q.empty()){
            pInt coords = q.front(); 
            int x = coords.s;
            int y = coords.f; 
            ll lessThan = 0; 
            ll greaterThan = 0; 
            //cout<< "ON POINT " << x  << ' ' << y << ell

            if (x+1 < m){
                lessThan = g[y][x+1]; 
                //cout<< lessThan << " A\n"; 
            }
            if (x-1 >= 0){
                greaterThan = g[y][x-1];
                //cout<< greaterThan << " B\n";  
            }
   
            if (lessThan == 0 && greaterThan == 0){
                q.pop(); 
                q.push(coords); 
            } else if (greaterThan < lessThan ){
                if (greaterThan+1 == lessThan){
                    cout << "-1\n"; return 0; 
                }
                g[y][x] = lessThan-1; 
                q.pop(); 
            } else if (x == m-1 || g[y][x+1] == 0){
                if (greaterThan+1 == lessThan){
                    cout << "-1\n"; return 0; 
                }
                g[y][x] = greaterThan+1; 
                q.pop(); 
            } else {
                cout << "-1\n"; return 0; 
            }
            
        }

            // output // 
        for (int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << g[i][j] << " "; 
            }
            cout << endl;     
        }

    } else if (m == 1 && n == 1){
        cout << g[0][0] << endl; 
    }
}
