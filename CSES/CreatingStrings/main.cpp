
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

int charCount[26]; 
vector<string> permutations; 
string input;

void findPermutations(string current){
    if (current.size() == input.size()){
        permutations.push_back(current); 
        return; 
    }

    // Now if it isn't the full length we have to make it full length
    for(int i = 0; i < 26; i++){
        if (charCount[i] > 0){
            charCount[i]--; 
            findPermutations(current + (char)('a' + i)); 
            charCount[i]++; // Once we are done using it we increase the count again 
        }
    }
}

int main(){
    cin >> input; 
    for (char i : input){
        charCount[i - 'a']++; 
    }

    findPermutations(""); 

    cout << permutations.size() << endl; 
    
    for (string permutation : permutations) {
        cout << permutation << endl; 
    }

}