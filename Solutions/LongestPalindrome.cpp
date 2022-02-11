#include <bits/stdc++.h>
using namespace std;
const int MD = 1001; 
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define end "\n"
#define space " "
#define maxN 25005

bool table[maxN][maxN];

int n; 

void longestPalindrome(string palindrome){
    int maxLength = 1; 
    string p; 
    for(int i = 0; i < n; i++){
        table[i][i] = true; 
    }
    int startingIndex = 0; 
    for(int i = 0; i < n - 1; i++){
        if (palindrome[i] == palindrome[i+1]){
            maxLength = 2; 
            startingIndex = i; 
            table[i][i+1] = true; 
        }
    }
    for (int k = 3; k <= n; ++k) {
            for (int i = 0; i < n - k + 1; ++i) {
                int j = i + k - 1; 
                if (table[i + 1][j - 1] && palindrome[i] == palindrome[j]) {
                    table[i][j] = true;
                    if (k > maxLength){
                        startingIndex = i; 
                        maxLength = k; 
                    }
                    
                }
    }
    cout << palindrome.substr(startingIndex, startingIndex + maxLength - 1);
    cout << maxLength; 

}

int main(){
    cin >> n; 
    for(int i = 0; i < n; i++){
        string Input; cin >> Input; 
        longestPalindrome(Input); 
    }
}
 