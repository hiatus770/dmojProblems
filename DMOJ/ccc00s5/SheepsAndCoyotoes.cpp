#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ell "\n"
#define f first
#define s second
#define pb push_back
#define forl(n) for (int i = 0; i < n; i++)
typedef long long ll; 
typedef pair<int, int> pInt; 
#define maxN 1000 

pair<double, double> sheep[1001];
unordered_set <int> deadSheep; 
int sheepAmt; 

int main(){
    cin >> sheepAmt; 
    forl(sheepAmt){
        cin >> sheep[i].f >> sheep[i].s; 
    }
    for(int c = 0; c <= 1000; c++){
        vector<pair<double, int>> v; // distance and index :)

        for(int i = 0; i < sheepAmt; i++){
            double dist = sqrt(pow(c-sheep[i].f, 2) + pow(sheep[i].s, 2)); 
            v.push_back({dist, i});
            //cout << sheep[i].f << " " << sheep[i].s << " " <<dist<<  endl; 
        }
        
        sort(v.begin(), v.end());
        deadSheep.insert(v[0].s); 
        //cout << v[0].f << endl; 
    }
    for (auto i : deadSheep){
        double x = ceil(sheep[i].f * 100.0) / 100.0;
        double y = ceil(sheep[i].s * 100.0) / 100.0;
        cout << "The sheep at (" << x << ", " << y << ") might be eaten.\n";
    }
}