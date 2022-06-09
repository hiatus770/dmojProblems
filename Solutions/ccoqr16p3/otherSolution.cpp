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

// Finds the intersection of two coordinates
// larger coordinate is the first
pair<int, int> intersection(int x, int y){
    int i = min(x, y); 
    int j = max(x, y); 
    int f = cl[i].f-cl[i].s;
    int rowIntersection = cl[j].f + (cl[j].s) - (cl[j].f-f); 
    int columnIntersection = cl[j].s;
    return {rowIntersection, columnIntersection};
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
    cl.pb({7 , 1});
    cl.pb({5 , 2});
    cout << intersection(1, 0).f << " " << intersection(0, 1).s << ell
}
/*
1 [ ]
2 [ ] [ ]
3 [ ] [ ] [ ]
4 [ ] [ ] [ ] [ ]
5 [ ] [y] [ ] [ ] [ ]
6 [ ] [ ] [ ] [ ] [ ] [ ]
7 [x] [ ] [ ] [ ] [ ] [ ] [ ]
8 [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
9 [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
*/