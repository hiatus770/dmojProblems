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
#define mxn 5005

// https://cses.fi/problemset/task/1623 

ll findMinimumAppleDifference(int index, vector<int> applesLeft, vector<int> applesRight, int maxIndex, int appleList[]){
    if (maxIndex != index){
        vector<int> newAL = applesLeft; 
        newAL.push_back(appleList[index]); 
        ll left = findMinimumAppleDifference(index + 1, newAL, applesRight, maxIndex, appleList); 
        vector<int> newAR = applesRight; newAR.push_back(appleList[index]); 
        ll right = findMinimumAppleDifference(index + 1, applesLeft, newAR, maxIndex, appleList); 
        
        return min(left, right); 
    }
    if (maxIndex == index){
        // Calculate the sum of both lists and see their difference
        ll sumLeft = 0, sumRight = 0; 
        for (int appleWeight : applesLeft){
            sumLeft += appleWeight; 
        }
        for (int appleWeight : applesRight){
            sumRight += appleWeight; 
        }
        
        return abs(sumLeft - sumRight); 
    }
}

int main(){
    int numberOfApples; 
    cin >> numberOfApples;

    int appleList[numberOfApples]; 

    for(int i = 0; i < numberOfApples; i++){
        cin >> appleList[i]; 
    }

    cout << findMinimumAppleDifference(0, {}, {}, numberOfApples, appleList) << endl; 
}