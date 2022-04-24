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

int n, m, k; 
set<pair<int, int>> pos; 
map<pair<int, int>, bool> state; 
queue<pair<int, int>> q; 

bool bfs(int startx, int starty){
    bool top = false; bool bottom = false; bool left = false; bool right = false; 
    // bfs function thing for each group breaks the entire code if it finds a single group that satisfies any of the four cases that are posssible to block the final cube 
    state[{startx, starty}] = true; 
    q.push({startx, starty});
    int x, y; int xa[] = {1, -1, 0, 0, -1, 1, -1, 1}; int ya[]={0, 0, -1, 1, 1, 1, -1, -1}; 
    while(!q.empty()){
        x = q.front().f;    
        y = q.front().s; 
        state[q.front()] = true; 
        q.pop(); 
        // cout << "X: " << x << " Y:" << y << endl; 
        if (x == 1){
            // cout << "Left\n"; 
            left = true; 
        }
        if (x == n){
            // cout << "Right\n";
            right = true;  
        }
        if (y == m){
            // cout << "Bottom\n";
            bottom = true;  
        }
        if (y == 1){
            // cout << "Top\n";
            top = true;  
        }
        if (top && bottom){
            return true; 
        }
        if (left && right){
            return true; 
        }
        if (left && top){
            return true;  
        }  
        if (right && bottom){
            return true; 
        }

        for(int i = 0; i < 8; i++){
            if (pos.find({x+xa[i], y+ya[i]}) != pos.end() && !state[{x+xa[i], y+ya[i]}]){
                // not touching any borders and visited of that place is false 
                q.push({x+xa[i], y+ya[i]}); 
            }
        }
    }
    return false; 
}

int main(){
    inputJunk; 
    cin >> n >> m >> k; 
    forl(k){
        int a, b; 
        cin >> a >> b;
        pos.insert({a, b}); 
        state[{a, b}] = false; // false means it is not visited.  by default all are false as the bfs group thing will visit them all
    }
    for(pInt i : pos){
        if (state[i] == false){
            if(bfs(i.f, i.s)){
                cout << "NO\n"; return 0;
            } 
        }
    }
    cout << "YES\n"; 
}