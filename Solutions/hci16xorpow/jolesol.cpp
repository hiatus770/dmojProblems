#include <bits/stdc++.h>
using namespace std;
// psa[r] ^ psa[l-1] = k
// psa[r] ^ psa[l-1] ^k = k^k = 0
// psa[r] ^ k = psa[l-1]

// a^a = 0 

const int mxn = 1e5+5;
int n, k;
long long ans, cur_k, psa[mxn];
void check(){
    unordered_map<long long, long long> mp;
    mp[0] = 1;
    for(int r = 1; r<=n; r++){
        ans+= mp[psa[r]^cur_k];
        mp[psa[r]]++;
    }
}
signed main(){
    cin.sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i =1; i<=n; i++){
        cin>>psa[i];
        psa[i]^=psa[i-1];
    }
    cur_k = k;
    while(cur_k>0){
        check();
        cur_k *=k;
    }
    cout<<ans<<"\n";
}