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
#define mxn 100

int n; int b; 
unordered_map<char, int> total; 
string alpha = "abcdefghijklmnopqrstuvwxyz"; vector<int> permutation;
pair<string, string> word[mxn]; 

int main(){
    freopen("blocks.out", "w", stdout); 
    freopen("blocks.in", "r", stdin); 

    cin >> n; 

    // set all letters to 0
    for(char i : alpha){
        total[i] = 0; 
    }

    for(int i = 0; i < n; i++ ){
        cin >> word[i].f >> word[i].s; 
    }

    for(int i = 0; i < n; i++){
        permutation.push_back(0); 
    }

    for (int j = 0; j < pow(2, n); j++){
        b = j;  
        
        for(int i=0; b>0; i++){
            permutation[i] = b%2;
            b = b/2;
        }

        unordered_map<char, int> comp; 

        for (char a : alpha){
            comp[a] = 0;
        }

        for(int i = 0; i < permutation.size(); i++){
            if (permutation[i] == 0){
                for(char a : word[i].f){
                    comp[a]++; 
                }
            } 
            if (permutation[i]== 1){  
                for(char a : word[i].s){
                    comp[a]++; 
                }          
            }
        }
    
        for (char a : alpha){
            total[a] = max(total[a], comp[a]); 
        }
    }   

    for(char a : alpha){
        cout << total[a] << ell
    }

}

/* 
1
2
1
1
0
1
1
0
0
0
0
0
0
0
2
0
0
1
1
1
1
0
0
1
0
0

2
2
2
1
0
1
1
0
0
0
0
0
0
0
2
0
0
1
1
1
1
0
0
1
0
0

*/ 