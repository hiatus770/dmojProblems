#include <bits/stdc++.h>
using namespace std;

int a[4]; 
int b[4]; 
int c[4]; 

// 0:bottom left x    1:bottom left y       2:top right x     3:top right y

int width(int r1[]){
    return (r1[2]-r1[0]); 
}

int height(int r1[]){
    return r1[3]-r1[1]; 
}

int main(){
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
    cin >> a[0] >> a[1] >> a[2] >> a[3]; 
    cin >> b[0] >> b[1] >> b[2] >> b[3]; 
    c[0] = min(a[0], b[0]); 
    c[1] = min(a[1], b[1]);
    c[2] = max(a[2], b[2]); 
    c[3] = max(a[3], b[3]);
    cout << max(width(c), height(c)) * max(width(c), height(c)) << endl;     
}