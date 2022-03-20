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

int t; 


int main(){
    cin >> t;
    // (int)a - 48; cast 1 2 3 4 5 6 7 8 9 to int or not
    forl(t){
        string n; int k; string ans = ""; 
        int cnt = 1; int kcnt = 0;  
        
        cin >> n >> k; 
        int sorted = n.size();

        priority_queue<int ,vector<int>, greater<int>> q;  
        
        while(cnt < n.size() && kcnt < k){
           
            int a = n[cnt]-48;
            int b = n[cnt-1]-48; 

            //cout << a << " " << b << " " << cnt << endl; 

            if (b > a){
                q.push(b);
                n.erase(n.begin()+cnt-1); 
                cnt = 0; 
                kcnt++; 
            } else if (cnt == n.size()-1 && a > q.top()){
                q.push(a);
                n.erase(n.begin()+cnt); 
                cnt = 0; 
                kcnt++; 
            }
            cnt++;
        }
        while (!q.empty()){
            n.push_back('0'+q.top());
            q.pop();  
        }
        cout << n << endl; 
    } // forl(t)


}