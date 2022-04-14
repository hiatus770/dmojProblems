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
#define mxN 5005 

int n, m, k, q, arr[mxN][mxN]; 
ll pre[mxN][mxN]; 

int main(){
    inputJunk
    cin >> n >> m >> k; 

    forl(k){
        int a, b, c, d; 
        cin >> a >> b >> c >> d; 
        //    (x1, y1)  (x2, y2) 
        for (int r = a; r <= c; r++){
            arr[r][b]++; 
            arr[r][d+1]--; 
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            arr[j][i] = arr[j][i-1] + arr[j][i];  
        }

    }

    cout << "ORIGINAL:\n"; 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << arr[j][i] << " ";
        }
        cout << endl; 
    }

    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            pre[j][i] = arr[j][i] + pre[j-1][i] + pre[j][i-1] - pre[j-1][i-1];  
        }
    }

    cout << "PSA:\n"; 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << pre[j][i] << " ";
        }
        cout << endl; 
    }

    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            pre[j][i] = arr[j][i] + pre[j-1][i] + pre[j][i-1]; 
        }
    }

    cin >> q; 
    forl(q){
        int a, b, c, d; 
        cin >> a >> b >> c >> d;
        cout << pre[d][c]-pre[d][a-1]-pre[b-1][c]+pre[b-1][a-1] << ell 
        cout << pre[d][c] << "-" << pre[d][a-1] << "-" << pre[b-1][c] << "+" << pre[b-1][a-1] << ell
    }
/* (a,b) to (c, d) is the rectangle that we want */ 
}
