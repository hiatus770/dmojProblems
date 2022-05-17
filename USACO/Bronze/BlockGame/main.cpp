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
map<char, int> frontSide; 
map<char, int> backSide; 
string alpha = "abcdefghijklmnopqrstuvwxyz"; 

int main(){
    freopen("blocks.out", "w", stdout); 
    freopen("blocks.in", "r", stdin); 
    cin >> n; 
    for(char i : alpha){
        frontSide[i] = 0; 
        backSide[i] = 0;
    }

    forl(n){
        string a, b; 
        cin >> a >> b; 
        for (char i : a){
            frontSide[i]++;  
        }
        for (char i : b){
            backSide[i]++; 
        }
    }
    
    for(char i : alpha){
        cout << max(frontSide[i], backSide[i]) << endl; 
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