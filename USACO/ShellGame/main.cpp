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

bool one[] = {true, false, false};
bool two[] = {false, true, false};
bool three[] = {false, false, true}; 
int a, b, c; 

int main(){
	freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);
    int n; cin >> n; 
    bool state; 
    forl(n){
        int x, y, z; cin >> x >> y >> z; x--; y--; z--; 
        forl(3){
            cout << one[i] << " "; 
        } 
        cout << endl; 

        swap(one[x], one[y]); 
        swap(two[x], two[y]); 
        swap(three[x], three[y]); 

        if (one[z] == true){
            a++; 
        }  
        if (two[z] == true){
            b++; 
        }
        if (three[z] == true){
            c++; 
        }
    }
    cout << max(a, max(b, c)) << endl;
}           