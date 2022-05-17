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

int capacity[3]; int milk[3]; 

void pour(int a, int b) {
    int c = min(milk[a], capacity[b]-milk[b]);  
    milk[a]-=c; 
    milk[b]+=c; 
}


int main(){
	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);
    for (int i = 0; i < 3; i++){
        cin >> capacity[i] >> milk[i]; 
    }
    for(int i = 0; i < 100; i++){
        pour(i%3, (i+1)%3); 
    }
    forl(3)
        cout << milk[i] << ell 
}           