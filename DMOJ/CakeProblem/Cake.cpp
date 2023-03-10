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
ll psa[mxN][mxN]; 

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
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

    // Applying psa to the difference array to get the actual values 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            arr[i][j] = arr[i][j-1] + arr[i][j];  
        }
    }

    // creating the 2d psa array 
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            psa[i][j] = arr[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }

    // Using the 2dpsa to output the range in O(1) time 
    cin >> q; 
    forl(q){
        int a, b, c, d; 
        cin >> a >> b >> c >> d;
        cout << psa[c][d]-psa[a-1][d]-psa[c][b-1]+psa[a-1][b-1] << '\n';
    }
/* (a,b) to (c, d) is the rectangle that we want */ 
}
