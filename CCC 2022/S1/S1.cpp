#include <bits/stdc++.h>
using namespace std;
const int MD = 1001; 
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define end "\n"
#define space " "


int n; 
int compute(){
    int ans = 0; 
    for (int i = n; i >= 0; i-=4){
        if (i % 5 == 0){
            ans++; 
        }
    }
    return ans; 
}


int main(){
    cin >> n; 
    cout << compute() << endl; 
}