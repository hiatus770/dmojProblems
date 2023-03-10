#include <bits/stdc++.h>
using namespace std;
const int MD = 1001; 
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define maxN 5000

bool table[maxN][maxN];

int testCases; 


void sub(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
    cout << endl; 
}

void longestPalindrome(string palindrome){
    int maxLength = 1; 
    int n = palindrome.length(); 
    memset(table, 0, sizeof(table));
    for(int i = 0; i < n; ++i){
        table[i][i] = true; 
    }

    int startingIndex = 0; 
    for(int i = 0; i < n - 1; ++i){
        if (palindrome[i] == palindrome[i+1]){
            maxLength = 2; 
            startingIndex = i; 
            table[i][i+1] = true; 
        }
    }

    for (int k = 3; k <= n; ++k) {
            for (int i = 0; i < n - k + 1; ++i) {
                int j = i + k - 1; 
                //cout << k space i space n space maxLength - 1 << endl;  
                if (table[i + 1][j - 1] && palindrome[i] == palindrome[j]) {
                    table[i][j] = true;
                    if (k > maxLength){
                        startingIndex = i; 
                        maxLength = k; 
                    }
                }
        }
    }
    cout << maxLength << endl; 

}

int main(){
        string Input; cin >> Input; 
        longestPalindrome(Input); 
}
 