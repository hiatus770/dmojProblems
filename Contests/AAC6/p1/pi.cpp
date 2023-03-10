#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ell "\n"; 
 
int n, k;   

int main(){
    cin >> n >> k; 

    int maxM = (1000000000/k)*k;
    if (n%2==1 && n==1){
        cout << maxM << endl; 
    } else if (n%2==1){
        cout << maxM << " "; 
    }
    for (int i = 1; i <= floor(n/2); i++){
        cout << maxM-i << " " << i;
        if (i == floor(n/2)){
            cout << endl; 
        } else {
            cout << " "; 
        }
    }
}