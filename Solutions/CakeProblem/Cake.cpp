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
        for (int r = a; r <= c; r++){
            arr[r][b]++; 
            arr[r][d+1]--; 
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << arr[j][i] << " ";
        }
        cout << endl; 
    }
}