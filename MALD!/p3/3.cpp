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
#define mxn 1000005

int n, y; 
// DAY | AMT OF CATS INFECTED ON THAT DAY NATURALLY
map<long long, int> dayMap; 
//  coordinate compression map, maps some super large number to where it exists in the cat array

int main(){
    cin >> n >> y; 
    int ind = 0; 
    forl(n){
        int a; 
        cin >> a; 
        if (dayMap.find(a) == dayMap.end()){
            dayMap[a] = 1; 
        } else {
            dayMap[a] = dayMap[a]+1; 
        }
    }
    


    ll infected = 0; ll safe = n; 
    // simulation moment . . .
    ll day = 1; 

    while(true){
        if (dayMap.find(day) != dayMap.end()){
            infected+=dayMap[day]; 
        }

        safe=n-infected; 

        infected += floor(infected/y); 

        if (safe == 0){
            cout << day; 
            break; 
        }

        day++; // next day 
    }
}