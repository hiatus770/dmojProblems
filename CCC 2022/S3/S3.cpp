#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define end "\n"
#define space " "

int n, m, k; 

int main(){
    cin >> n >> m >> k; 
    
    if (m == 2){
        if (n > k){
            cout << -1 << endl; 
        } else {
            int goal = k - n; 
            int score = 0; 
            if (goal > n-1){
                cout << -1 << endl; 
            } else {
                for(int i = 0; i < n; i++){
                    if (score != goal){
                        if (score % 2 == 0){
                            cout <<  "1";  
                        } else {
                            cout << "2"; 
                        }
                        if (i != n-1){
                            cout << " "; 
                        } else {
                            cout << endl; 
                        }
                        score += 1; 
                    } else if (score == goal){
                        if (score % 2 == 0){
                            cout <<  "1";  
                        } else {
                            cout << "2"; 
                        }
                        if (i != n-1){
                            cout << " "; 
                        } else {
                            cout << endl; 
                        }                
                    } 
                }
            }
        }

    } else {
        if (2 * n < k){
            cout << -1 << endl; 
        } else {
            int goal = k - n; 
            int score = 0; 
            int sum = 0; 
            for(int i = 0; i < n; i++){
                if (score != goal){
                    if (goal - score == 1){
                        cout << sum-1;

                    } else {
                        cout << sum+1; 
                    }
                    score += sum++;
                    if (i == n-1){
                        cout << endl; 
                    }  else {
                        cout << " "; 
                    }
                } else {
                    cout << sum; 
                    if (i == n-1){
                        cout << endl; 
                    }  else {
                        cout << " "; 
                    }
                }
            }
        }
    }
}