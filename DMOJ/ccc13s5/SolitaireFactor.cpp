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

int main(){
    int ans = 0; 
    int c; cin >> c; int a = 2; 

    while(c != 1){
        a = 2;
        while(true){  
            if (c % a == 0){
                int b = c/a; 
                //cout << "Current:" <<  c << " " << a << " " << (c-a)/(c/a) <<  endl; 
                ans += (c-b)/b;
                c = c - b;
                break; 
            }
            a++;
        }
    }
    cout << ans; 


}