#include <bits/stdc++.h>
using namespace std;
const int MD = 1001; 
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); // cout.tie(0);
#define end "\n"
#define space " "

long long x, y, g, ans; 

vector<int> with[300500]; 

vector<int> sep[300500]; 

map<int, string> p; 
map<string, int> id; 


// map.count checks if a key exists :o returns 0 if no count, take nfrom cpp thing website cplusplus reference 

int main(){
    cin >> x; 
    int cnt = 0; 
    for(int i = 0; i < x; i++){
        string a, b; 
        cin >> a >> b; 
        if (id.count(a) <= 0){
            id.insert({a, cnt}); 
            p.insert({cnt++, a}); 
            // cout << cnt-1 << " is " << a << endl;  
        } 
        if (id.count(b) <= 0){
            id.insert({b, cnt});
            p.insert({cnt++, b});  
            // cout << cnt-1 << " is " << b << endl; 
        }
        with[id[a]].push_back(id[b]); 
    }
    cin >> y; 
    for(int i = 0; i < y; i++){
        string a, b; 
        cin >> a >> b; 
        if (id.count(a) <= 0){
            id.insert({a, cnt}); 
            p.insert({cnt++, a}); 
            // cout << cnt-1 << " is " << a << endl; 
        } 
        if (id.count(b) <= 0){
            id.insert({b, cnt});
            p.insert({cnt++, b});  
            // cout << cnt-1 << " is " << b << endl; 
        }
        sep[id[a]].push_back(id[b]);     
    }
    cin >> g; 
    for (int i = 0; i < g; i++){
        string a, b, c; cin >> a >> b >> c; 
        // cout << "In group: " << i << endl; 
        if (id.count(a) > 0 && a == p[id[a]]){
            // cout << a << " has a constraint\n"; 
            for(int z : with[id[a]]){
                // cout << p[z] << endl; 
                if (z != id[b] && z !=id[c]){
                    // cout << "Violation as " << a << " is not with " << p[z] << endl; 
                    ans++; 
                }
            }
            for(int z : sep[id[a]]){
                if (z == id[b]){
                    // cout << "Violation as " << a << " is with " << p[z] << endl; 
                    ans++; 
                } else if (z == id[c]){
                    // cout << "Violation as " << a << " is with " << p[z] << endl; 
                    ans++; 
                }
            }
        } 
        if (id.count(b) > 0 && b == p[id[b]]){
            // cout << b << " has a constraint\n"; 
            for(int z : with[id[b]]){
                // cout << p[z] << endl; 
                if (z != id[a] && z != id[c]){
                    // cout << "Violbtion bs " << b << " is not with " << p[z] << endl; 
                    ans++; 
                }
            }
            for(int z : sep[id[b]]){
                if (z == id[a]){
                    // cout << "Violation as " << b << " is with " << p[z] << endl; 
                    ans++; 
                } else if (z == id[c]){
                    // cout << "Violation as " << b << " is with " << p[z] << endl; 
                    ans++; 
                }
            }
        } 
        if (id.count(c) > 0 && c == p[id[c]]){
            // cout << c << " has a constraint\n"; 
            for(int z : with[id[c]]){
                // cout << p[z] << endl; 
                if (z != id[b] && z !=id[a]){
                    // cout << "Violation as " << c << " is not with " << p[z] << endl; 
                    ans++; 
                }
            }
            for(int z : sep[id[c]]){
                if (z == id[b]){
                    // cout << "Violation as " << c << " is with " << p[z] << endl; 
                    ans++; 
                } else if (z == id[a]){
                    // cout << "Violation as " << c << " is with " << p[z] << endl; 
                    ans++; 
                }
            }
        } 
    }
    if (ans > x + y){
        cout << x + y; 
    } else {
    cout << ans << endl; 
    }
}