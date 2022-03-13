#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define end "\n"
#define space " "

int n, m, k; 

int main(){
    inputJunk 
    cin >> n >> m >> k; 
    if (k < n || ((n*1)*n)/2 < k){
        cout << -1 << endl; 
    } else if (n == k){
        for(int i = 0; i < n; i++){
            cout << i << " "; 
        } cout << endl; 
    } else {
        int g = k - n; int num = 0; int sum = 0; int ans; 
        for(int i = 0; i < n; i++){
            if (g == sum){
                cout << num << " ";  
            } else {
                if (num+1 >= g-sum){
 
                }
        }


    }
}