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

// circle = 1, square = 2, triangle = 3 

int polygons[MAX]; 
int n, q; 
int main(){
    cin >> n >> q; 

    forl(q){
        string cmd; string type; int index; 
        int t; 
        cin >> cmd >> type >> index; 
        if (type == "square"){
            t = 2; 
        } else if (type == "triangle"){
            t = 3; 
        } else {
            t = 1; 
        }
        if (cmd == "get"){
            if (t == polygons[index]){
                cout << "1\n"; 
            } else {
                cout << "0\n"; 
            }
        } else if (cmd == "set"){
            polygons[index] = t; 
        }
    } 
}