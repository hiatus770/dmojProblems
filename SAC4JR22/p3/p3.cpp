#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ell "\n"
#define f first
#define s second
#define pb push_back
#define forl(n) for (int i = 0; i < n; i++)
typedef long long ll; 
typedef pair<int, int> pInt; 
#define MAX 100005

ll n, a, x, y, ans = 0; 
long double angles[MAX]; 

long double findAngle(double ang){
    if (ang > a){
        return min(ang - a, abs(ang + 360 - a)); 
    } else {
        return min(a - ang, abs(a - 360 - ang));
    }
}

int main(){
    cin >> n >> a; 
    forl(n){
        cin >> x >> y; 
        long double ang = atan2(x, y) * 180/M_PI; 
        ang = (90 - ang);
        if (ang < 0){
            ang = 360 + ang; 
        }
        // cout << "\nANGLE: " << ang  << "\nCOORD: " << x << " " << y << endl; 
        // cout << "DIFFERENCE: " << findAngle(ang) << endl; 
        angles[i] = findAngle(ang); 
    }
    int cnt = 0; 
    for (int i = 1; i < n; i++){
        if (angles[i] < angles[cnt]){
            cnt = i; 
        }
    } 
    
    cout << cnt+1 << endl; 
}