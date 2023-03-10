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
#define mxn 10000
int one[mxn];
int zero[mxn]; 

long double imbalance(long double z, long double o, long double l){
    return (abs((z-o)/l)*100); 
}

// double psa (zero and one) for finding how much ones and zeroes in each range for each substring of the thing 
string n; int ans; 
int main(){
    int mi, ma; 
    cin >> mi >> ma; 
    cin >> n;
    for(int i = 0; i < n.length(); i++){
        char letter = n[i]; 
        if (letter == '0'){
            // the zero psa is now one here
            zero[i+1] = 1; 

        } else {
            // the zero psa value is now 0 here
            one[i+1] = 1; 
        }
    }

    for(int i = 1; i < n.length()+1; i++){
        one[i] += one[i-1]; 
        zero[i] += zero[i-1]; 

    }



    for(int i = 1; i <= n.length(); i++){
        for (int j = i; j <= n.length(); j++){
            //cout << i << " " << j << ":" << imbalance((zero[j]-zero[i-1]), (one[j]-one[i-1]), j-i+1) << ell 
            long double im = imbalance((zero[j]-zero[i-1]), (one[j]-one[i-1]), j-i+1); 
            if (im >= mi && im <= ma){
                ans++; 
            }
        }
    }
    cout << ans << ell 
}