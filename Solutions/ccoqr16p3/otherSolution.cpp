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

int m, n; long long ans;
pair<int, int> arr[mxn];
vector<pair<int, int>> cl;

long long seriesSum(int row, int column){
    ll dif = m-row+1;
    return ((double)dif/2)*(dif+1);
}

// long long coordSum(){
//     if (i < m-1){

//     } else if (i == m-1){

//     }

// }

int main(){
    cin >> n >> m;
    forl(m){
        cin >> arr[i].s >> arr[i].f;
    }
    sort(arr, arr+m);

    int lastColumn = 0; int highestRow = 0;
    for(int i = 0; i < m; i++){
        if (i == m-1){
            cl.push_back({arr[i].s, arr[i].f});
        } else if (arr[i].f != arr[i-1].f){
            cl.push_back({arr[i-1].s, arr[i-1].f});
        }
        cout << "ON COORDINATE: " << arr[i].s << " " << arr[i].f << ell
    }
    for(auto i : cl){
        cout << i.f << " " << i.s << ell
    }
}
