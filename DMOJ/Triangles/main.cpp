
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

float n; 

// https://dmoj.ca/problem/ioi94p1  


int getInd(float row, float column){
    float i = 0;
    i += (float)((float)((row)/2) * (float)(1 + row)); 
    i+= column;
    return i;  
}

int main(){
    cin >> n; 
    int length = (float)((float)((n)/2) * (float)(1 + n)); 
    int sumTriangle[length]; 
    int triangle[length]; 

    forl(length){
        cin >> triangle[i]; 
        sumTriangle[i] = 0; 
    }

    for(int row = n-1; row >= 0; row--){
        if (row == n-1){
            for(int i = 0; i < n; i++){
                sumTriangle[getInd(row, i)] = triangle[getInd(row, i)]; 
            }
        } else {
            for (int i = 0; i <= row; i++){
                int a = triangle[getInd(row+1, i)]; 
                int b = triangle[getInd(row+1, i+1)]; 
                // cout << "COMPARING " << a << " AND " << b << ell 
                if (sumTriangle[getInd(row+1, i)] > sumTriangle[getInd(row+1, i+1)]){
                    sumTriangle[getInd(row, i)] += triangle[getInd(row, i)] + sumTriangle[getInd(row+1, i)]; 
                    // cout << a << " WAS LARGER SETTING " << triangle[getInd(row, i)] << " TO " << a << ell
                } else {
                    sumTriangle[getInd(row, i)] += triangle[getInd(row, i)] + sumTriangle[getInd(row+1, i+1)]; 
                    // cout << b << " WAS LARGER SETTING " << triangle[getInd(row, i)] << " TO " << b << ell
                }
            }
        }
    } 

    cout << sumTriangle[0] << endl; 
}