#include <bits/stdc++.h>
using namespace std;
const int MD = 1001; 
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define end "\n"
#define space " "
#define maxN 2000

int n, k; 
int arr[maxN]; int ans; 

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i]; 
    }
    sort(arr, arr+n, greater<int>()); 
    int lastElement = 0; 
    for(int i = 1; i < n; i++){
        if (arr[lastElement] - k >= arr[i]){
            ans++; 
            lastElement = i; 
        }
    }
    cout << ans << endl; 
}