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
    if (row > n){
        return 0;
    }
    ll dif = n-row+1;
    return ((double)dif/2)*(dif+1);
}

// Finds the intersection of two coordinates
pair<int, int> intersection(int x, int y){
    int i = min(x, y);
    int j = max(x, y);
    int f = cl[i].f-cl[i].s;
    int rowIntersection = cl[j].f + (cl[j].s) - (cl[j].f-f); 
    int columnIntersection = cl[j].s;
    return {rowIntersection, columnIntersection};
}

int main(){
    cin >> n >> m;
    forl(m){
        cin >> arr[i].s >> arr[i].f;
    }
    sort(arr, arr+m);
    for(int i = 0; i < m; i++){
        cl.pb({arr[i].s, arr[i].f});
    }
    // If its in the past tallest then do not include. 
    int f = INT_MAX; 
    int pastCoord = 0;   
    for( int j = 0; j < cl.size(); j++){
        pInt i = cl[j]; 
        if(i.s <= i.f-f){
            cout << "Current coordinate is under another coordinate.\n";
        } else if (i.s > i.f-f){
            cout << "Current coordinate is over another coordinate or is the starting coordinate.\n";
            f = i.f - i.s;
            pInt intersect = intersection(j, pastCoord); 
            cout << "Intersection is: " << intersect.f << " " << intersect.s << ell;
            if (j != 0){
                ans += seriesSum(i.f, i.s) - seriesSum(intersect.f, intersect.s); 
            } else {
                ans += seriesSum(i.f, i.s);
            }

            cout << "Sum of first coordinate: " << seriesSum(i.f, i.s) << " Sum of second coordinate: " << seriesSum(intersect.f, intersect.s) << ell 
        }
    }

    // for(int i = 0; i < cl.size(); i++){
    //     pair<int, int> coord = cl[i];
    //     if (i != cl.size()-1){
    //         pair<int, int> intersect = intersection(i, i+1);
    //         cout << "INTERSECTION OF " << coord.f << " "  << coord.s << " AND " << cl[i+1].f << " " << cl[i+1].s << " IS " << intersect.f << " " << intersect.s << ell;
    //         cout << "ADDING: " << seriesSum(coord.f, coord.s) << "-" << seriesSum(intersect.f, intersect.s) << ell 
    //         ans += seriesSum(coord.f, coord.s) - seriesSum(intersect.f, intersect.s);
    //     } else {
    //         ans += seriesSum(coord.f, coord.s);
    //         cout << ".ADDING: " << seriesSum(coord.f, coord.s) << ell 
    //     }
    // }
    
    cout << ans << ell 
    
}
/*
1 [ ]
2 [ ] [ ]
3 [ ] [ ] [ ]
4 [ ] [ ] [ ] [ ]
5 [ ] [x] [ ] [ ] [ ]
6 [ ] [ ] [ ] [ ] [ ] [ ]
*/