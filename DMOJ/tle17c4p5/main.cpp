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

int n, m; 

int main(){
    cin >> n >> m;
    long long i = 1; n++;  
    for(int j = 0; j < n; j++){
        cout << (int)i%m << ell;
        i = i * ((double)(n-j-1)/(double)(j+1));  
    } 
}