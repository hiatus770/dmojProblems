#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ell "\n";
#define f first
#define s second
#define pb push_back
#define forl(n) for (int i = 0; i < n; i++)
#define pr(arr, n) for (int i = 0; i < n; i++){cout << arr[i] << " ";} cout << endl; 
typedef long long ll; 
typedef pair<int, int> pInt; 
const int mxN = 500005; 

int s[mxN];



int main(){
    int n; ll ans = 0; 
    cin >> n;
    pInt m = {-1000000000, 0}; 
    forl(n){
        cin >> s[i];
        if (s[i] > m.f){
            m.f = s[i]; 
            m.s = i; 
        }   
    }
    int hv = m.s; 

    for(int i = 0; i < hv; i++){
        ans += max(0, s[i]-s[i+1]); 
        s[i+1] = s[i+1] + max(0, s[i]-s[i+1]); 
    }

    for(int i = n-2; i >= hv; i--){
        ans += max(0, s[i+1]-s[i]);
        s[i] = s[i] + max(0, s[i+1]-s[i]); 
    }

    cout << ans << endl; 
}