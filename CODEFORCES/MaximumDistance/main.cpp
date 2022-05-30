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
#define mxn 5005

pair<double, double> coords[mxn]; 

double dist(pair<double, double> a, pair<double, double> b){
    return ((a.f-b.f)*(a.f-b.f)) + ((a.s-b.s) * (a.s-b.s));  
}

int main(){
    int n; 
    cin >> n;
    forl(n){
        cin >> coords[i].f;
    }
    forl(n){
        cin >> coords[i].s; 
    }
    double ans = 0; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans = max(dist(coords[i], coords[j]), ans); 
        }
    }
    cout << (int)(ans)<< ell

}