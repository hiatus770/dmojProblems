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
#define zeroSet(n) memset(n, 0, sizeof(n)); 

int b, n; // N is cow count and b is the max distance possible 

int xCows[1000001];
int yCows[1000001];  

int main(){
    cin >> b >> n;
    zeroSet(xCows);
    zeroSet(yCows); 
    forl(n){
        int xCoord, yCoord; 
        cin >> xCoord >> yCoord; 
        xCows[xCoord]+=1; 
        yCows[yCoord]+=1;
    }
    int partX; int partY; 

}