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

int n; 

int main(){
    cin >> n; 
    for (int i = 0; i < n; i++){
        long double a, b; 
        cin >> a >> b; 
        long double p = ceil((a/b)*100);
        // cout << p << ell  
        if (p > 100){
            cout << "sus\n"; 
        } else if (p == 100){
            cout << "average\n"; 
        } else if (p >= 98 && p <= 99){
            cout << "below average\n"; 
        } else if (p >= 95 && p <= 97){
            cout << "can't eat dinner\n"; 
        } else if (p >= 90 && p <= 94){
            cout << "don't come home\n"; 
        } else if (p < 90){
            cout << "find a new home\n"; 
        }
    }
}