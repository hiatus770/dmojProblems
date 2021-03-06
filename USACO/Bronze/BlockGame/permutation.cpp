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

int n; 
map<char, int> blocks; 
string alpha = "abcdefghijklmnopqrstuvwxyz"; 

int main(){
    freopen("blocks.in", "r", stdin); 
    freopen("blocks.out", "w", stdout);         
    cin >> n;
    for(char i : alpha){blocks[i] = 0;}
    for(int i = 0; i < n; i++){
        string a, b; cin >> a >> b; 
        map<char, int> aMap; 
        map<char, int> bMap; 
        for(char i : alpha){
            aMap[i] = 0; bMap[i] = 0; 
        }
        for(char i : a){
            aMap[i]++;
        }
        for(char i : b){
            bMap[i]++; 
        }
        for(char i : alpha){
            blocks[i] += max(bMap[i], aMap[i]); 
        }
    }
    for(char i : alpha){
        cout << blocks[i] << ell 
    }
}