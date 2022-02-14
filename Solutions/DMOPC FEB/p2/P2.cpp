#include <bits/stdc++.h>
using namespace std;
const int MD = 1001; 
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define end "\n"
#define space " "

int n, k; 
int arr[1000010]; 

int main(){
    string b; 
    cin >> n >> k >> b;
    int arrcount = 0; 

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if (b[i] == '1'){
            arr[arrcount++] = cnt; 
            cnt = 0; 
        } else if (b[i] == '0'){
            cnt++; 
        }
    }
    arr[arrcount] = cnt; 

    sort(arr, arr+n, greater<int>()); 

    int ans = 0; 

    for(int i = 0; i < k; i++){
        ans += arr[i]; 
    }
    cout << ans << endl; 

}