#include <bits/stdc++.h>
using namespace std;
const int MD = 1001; 
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ell "\n"; 
#define f first
#define s second
#define pb push_back
#define forl(n) for (int i = 0; i < n; i++)
typedef long long ll; 
typedef pair<int, int> pi; 

int n; 

map<int, int> cnt;  

pi readings[1005]; 

int main(){
    cin >> n; 
    forl(n){
        int a; cin >> a; 
        if (cnt.count(a) != 0){
            cnt[a]++; 
        } else {
            cnt.insert({a, 1}); 
        }
    }
    int i = 0; 
    for(auto const& x : cnt){
        readings[i++] = {x.second, x.first}; 
    }
    sort(readings, readings+n, greater<pi>()); 


    

    if (readings[0].f == readings[1].f){
        forl(n){
            if (readings[n].f == readings[0].f){

            }
        }
    }

    forl(4)
    cout << readings[i].first << " " << readings[i].second << ell
}