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
#define mxn 500005

int road[100]; int journey[100]; 

int n, m; 

int main(){
    freopen("speeding.out", "w", stdout); 
    freopen("speeding.in", "r", stdin); 

    cin >> n >> m; 
    int count = 0; 
    for(int i = 0; i < n; ++i){
        int a, b; 
        cin >> a >> b; 
        for (int i = count; i < count+a; i++){
            road[i] = b; 
        }
        count += a;
    }
    count = 0; 
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b; 
        for( int i = count; i < count + a; ++i){
            journey[i] = b; 
        }
        count += a; 
    }
    int ans = 0; 
    for(int i = 0; i < 100; i++){
        ans = max(journey[i]-road[i], ans); 
        //cout << "Limit: " << road[i] << " Cow speed: " << journey[i] << ell
    }
    cout << ans << endl; 
}