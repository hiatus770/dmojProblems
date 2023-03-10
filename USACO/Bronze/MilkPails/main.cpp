#include <iostream>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ell "\n";
#define f first
#define s second
#define pb push_back
#define forl(n) for (int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pInt;
#define mxn 100

int main(){
    freopen("pails.out", "w", stdout); 
    freopen("pails.in", "r", stdin); 
    int x, y, m; int ans = 0;  
    cin >> x >> y >> m; 
    for(int i = 0; i <= m/x; i++){
        for(int j = 0; j <= m/y; j++){
            if (m-ans > m - (x*i + y*j) && x*i + j*y <= m){
                ans = x*i + y*j; 
            }
        }
    }
    cout << ans << ell 
}