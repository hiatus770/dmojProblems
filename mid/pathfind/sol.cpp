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

int n, m, k; 
set<pair<int, int>> pos; 
map<pair<int, int>, bool> state; 

void bfs(int x, int y){
    // bfs function thing for each group breaks the entire code if it finds a single group that satisfies any of the four cases that are posssible to block the final cube 
    
}

int main(){
    cin >> n >> m >> k; 
    forl(k){
        int a, b; 
        cin >> a >> b;
        pos.insert({a, b}); 
        state[{a, b}] = false; // false means it is not visited.  by default all are false as the bfs group thing will visit them all
    }
    for (auto i : pos){
        cout << i.s << " " << i.f << endl; 
        cout << (bool)state[i] << endl; 
    }
}