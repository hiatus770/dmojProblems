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

 int main(){
     int m; cin >> m; 
     double a = 12; double b = -5; double c = (1-m); 
     double x1 = (-b + sqrt(25 + (-48 * c)))/24;
    cout << fixed << setprecision(6) << x1 << endl; 
}