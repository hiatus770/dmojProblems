#include <bits/stdc++.h>
using namespace std;

int a[4]; 
int b[4]; 
int c[4]; 

// bottom left x    bottom left y       top right x     top right y

int area(int r1[]){
    return (r1[2]-r1[0]) * (r1[3]-r1[1]); 
}

int intersect(int r1[], int r2[]){
    int x = max(0, min(r1[2], r2[2]) - max(r1[0], r2[0])); 
    int y = max(0, min(r1[3], r2[3]) - max(r1[1], r2[1])); 
    return x * y; 
}

int main(){
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
    cin >> a[0] >> a[1] >> a[2] >> a[3]; 
    cin >> b[0] >> b[1] >> b[2] >> b[3]; 
    cin >> c[0] >> c[1] >> c[2] >> c[3];  
    cout << area(a) + area(b) - intersect(a, c) - intersect(b, c) << endl; 
}