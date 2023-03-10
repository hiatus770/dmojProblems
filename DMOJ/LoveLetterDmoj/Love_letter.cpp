#include <bits/stdc++.h>
using namespace std;
const int MD = 1001; 
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define end "\n"
#define space " "

string alpha = "abcdefghijklmnopqrstuvwxyz"; 

int letter(char fi){
  int I;
  for(int i = 0; i < 26; i++){
    if (alpha[i] == fi){
      I = i; 
    }
  }
  return I;
}

int main(){
  
  int n; cin >> n; 
  int l; cin >> l;  
  string message; 

  getline (cin,message);
  getline (cin,message);
  
  for (int i = 0; i<message.length(); i++){
    if (message[i] != ' '){
      cout << alpha[(letter(message[i]) + l)%26];
    } else {
      cout << " "; 
    }
  }

}