
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
#define mxn 101

int r[mxn]; 

int main(){

    int k, m; 
    cin >> k;  
    cin >> m; 
    forl(m){ 
        cin >> r[i]; 
    }   

    vector<pair<int, int>> list; 
    forl(k){
        list.push_back({i+1, i+1}); 
    } 
    forl(m){
        int j = 0; 
        while(j < list.size()){
            if (list[j].f % r[i] == 0){
                list.erase(std::next(list.begin(), j)); 
                j--; 
            }
            j++; 
        }
        // Reset all the numbers again 
        forl(list.size()){
            list[i].f = i+1; 
        }
    }
    forl(list.size()){
        cout << list[i].s << endl; 
    }

    
}