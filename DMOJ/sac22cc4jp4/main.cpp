
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
#define mxn 10001

int x[mxn]; // The values that we are given in the list that we have to rmove
int psaX[mxn + 1 ]; 
int a[mxn]; /// The vvalues we have to solve the problem for 
int n, k; 

int sum(int d){
    int totalSubtractions = 0;
    int lastSubtractionIndex = 0;  
    for (int i = 0; i < n; i++){ 
        // Check if the current number is the forbidden number 
        if (d == x[i]){
            // If forbidden we must remove the last n numbers from the PSA as long as we do NOT overlap the last section that we removed from
            if (i - d <= lastSubtractionIndex){
                // Remove only up to the last subtraction index 
                totalSubtractions -= psaX[i] - psaX[lastSubtractionIndex];  
                lastSubtractionIndex = i; 
            } else {
                totalSubtractions -= psaX[i] - psaX[i - d - 1]; 
            }
        }
    }
    return psaX[n-1] + totalSubtractions; 
} 

int main(){
    cin >> n >> k; 
    forl(n){
        cin >> x[i]; 
    }
    forl(k){
        cin >> a[i]; 
    }
    psaX[0] = a[0]; 
    // Generate the PSA for the problem
    for (int i = 1; i < n; i++){
        psaX[i] = psaX[i-1] + a[i]; 
    }

    // Now that we have the PSA we can solve the problem for each of the K values 
    for (int i = 0; i < k; i++){
        cout << sum(a[i]); 
    }  


}