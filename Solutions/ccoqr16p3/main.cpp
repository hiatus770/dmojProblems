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
#define mxn 100005

/*It's a well-known fact that, inside computers, all data is stored in 2D pyramids of data blocks.

A certain pyramid has  () rows, numbered  from top to bottom. Each row  has  block spaces, which are labelled  from left to right. Each block space  in rows  rests on top of two supporting block spaces in the row below it — block spaces  and . For example, a pyramid with 6 rows is illustrated below, with block spaces , , and  indicated in red:*/ 

// Data structure problem on dmoj 
int m; int n; int f; long long ans; 
pair<ll, ll> arr[mxn]; 

long long seriesSum(int row, int column){
    ll dif = m-row+1; 
    return ((double)dif/2)*(dif+1);   
}

// returns the sum of a series of number from a to b
long long coordSum(int i){
    if (i == 0){
        // first pair of coordinates
        f = arr[0].f-arr[0].s;
        return seriesSum(arr[0].f, arr[0].s);
    } else {
        // first check if they are in the same series
        if (arr[i].s <= arr[i].f-f){
            return 0;
        } else {
            // find out where they intersect on the grid, and use the formula newSeries - intersectionSeries = blocks added
            ll rowIntersection =  arr[i].f + (arr[i].s) - (arr[i].f-f); 
            ll columnIntersection = arr[i].s;
            cout << "F:" << f << ell
            cout << rowIntersection << " " << columnIntersection << ell
            f = arr[i].f-arr[i].s;
            return seriesSum(arr[i].f, arr[i].s) - seriesSum(rowIntersection, columnIntersection);
        }
    }
}

int main(){
    cin >> m >>  n;
    forl(n){
        cin >> arr[i].f >> arr[i].s;
    }
    sort(arr, arr + n);
    forl(n){
        cout << "ROW:" << arr[i].f << " " << arr[i].s << ell;
        ans += coordSum(i); 
    }
    cout << ans << ell;
}