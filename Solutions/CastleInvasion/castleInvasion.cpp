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
const int mxn = 100; 

int front[mxn];
int back[mxn];
int n; int ans; 

int main(){
    cin >> n; 
    forl(n){
        cin >> front[i]; 
    }   
    forl(n){
        cin >> back[i]; 
    }

    cout << ". "; 
    for (int i = 0; i < n; i++){
        cout << " " << front[i] << "  "; 
    }
    cout << ell 

    for (int i = 0; i < n; i++){
        cout << back[i] << " "; 
        for (int j = 0; j<n; j++){
            cout << "[" << min(front[j], back[i]) << "] "; 
            ans += min(front[j], back[i]); 
        }
        cout << endl << endl; 
    }
    cout << ans << endl; 
}