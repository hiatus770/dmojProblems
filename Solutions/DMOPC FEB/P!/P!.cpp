#include <bits/stdc++.h>
using namespace std;
const int MD = 1001; 
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define end "\n"
#define space " "

int d; 
int number[1000005];  

void swap(int a, int b){
    int temp = number[b]; 
    number[b] = number[a];
    number[a] = temp;  
}

int main() {
    cin >> d; 
    string ipt; 
    cin >> ipt; 

    for(int i = 0; i < d; i++){
        if (ipt[i] == '1'){
            number[i] = 1; 
        }
        if (ipt[i] == '2'){
            number[i] = 2; 
        }
        if (ipt[i] == '3'){
            number[i] = 3; 
        }
        if (ipt[i] == '4'){
            number[i] = 4; 
        }
        if (ipt[i] == '5'){
            number[i] = 5; 
        }
        if (ipt[i] == '6'){
            number[i] = 6; 
        }
        if (ipt[i] == '7'){
            number[i] = 7; 
        }
        if (ipt[i] == '8'){
            number[i] = 8; 
        }
        if (ipt[i] == '9'){
            number[i] = 9; 
        }
    }

    for (int i = 0; i < d-1; i++){
        if (number[i] < number[i+1]){
            swap(i, i+1); 
            break;
        }
    }

    for(int i = 0; i < d; i++){
        cout << number[i]; 
    }
    cout << endl; 
}
