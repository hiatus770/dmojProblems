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
#define mxn 100500
string websites[mxn];
set<string> fi; 



int main(){
    int n; cin >> n; 
    string a; 
    getline(cin, a); 
    for (int i = 0; i < n; i++){
        getline(cin, websites[i]);  
    }
    for (int i = 0; i < n; i++){
        if (websites[i].find("yubo")!=string::npos){
            //cout << "FOR WEBSITE " << websites[i] << " CHECKING " << i-1 << " AND " << i+1 << ell 
            if (i-1 >= 0){
                fi.insert(websites[i-1]); 
            }
            fi.insert(websites[i]); 
            if (i+1 < n){
                fi.insert(websites[i+1]); 
            }
        }
    }
    for (string i : fi){ 
        cout << i << ell
    }
}