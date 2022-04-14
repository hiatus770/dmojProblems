#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define INF (0x3f3f3f3f)
#define ms(a,b) memset(a,b,sizeof(a));

const int mxN = 5005;
int n,m,k,q,arr[mxN][mxN],diff[mxN][mxN];
ll pre[mxN][mxN];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        for(int j = a; j <= c; j++){
            diff[j][b]++;
            diff[j][d+1]--;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            arr[i][j] = arr[i][j-1] + diff[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pre[i][j] = arr[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << pre[c][d]-pre[a-1][d]-pre[c][b-1]+pre[a-1][b-1] << '\n';
    }
}