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
#define mxn 100005

ll n, k, powK, psa[mxn], ans; 


int main(){
    inputJunk
    cin >> n >> k; powK = k; 
    for(int i = 1; i <= n; i++){
        cin >> psa[i]; 
        // the xor psa thing 
        psa[i] ^= psa[i-1]; 
    }

    while(powK > 0){
        unordered_map<ll, ll> freq; 
        freq[0] = 1; 
        for (int r = 1; r <= n; r++){
            ans+=freq[psa[r]^powK];
            freq[psa[r]]++; 
        }
        powK*=k; 
    }
    cout << ans << endl; 

}