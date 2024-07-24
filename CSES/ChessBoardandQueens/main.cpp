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

// Only links from cplusplus.com
// Maps : https://cplusplus.com/reference/stack/stack/
// Arrays : https://cplusplus.com/reference/array/array/
// Lists : https://cplusplus.com/reference/list/list/
// Vectors : https://cplusplus.com/reference/vector/vector/
// Stacks : https://cplusplus.com/reference/stack/stack/
// Queues : https://cplusplus.com/reference/queue/queue/
// Deques : https://cplusplus.com/reference/deque/deque/
// Priority Queues : https://cplusplus.com/reference/queue/priority_queue/
// Sets : https://cplusplus.com/reference/set/set/
// Unordered Sets : https://cplusplus.com/reference/unordered_set/unordered_set/

// LINK: https://cses.fi/problemset/task/1624

int board[8][8];

int possiblePlacements = 0;

void getQueens(int column = 0, vector<pair<int, int>> placedQueens = {}){
    // Initially we start at column 0 slowly backtracking 
    if (column == 8){
        possiblePlacements++; 
        return; 
    } 
    
    for (int r = 0; r < 8; r++){
        // See if it is possible to place the piece at the indicated spot 
        bool possible = true; 
        for(pair<int, int> queen : placedQueens){
            if (r == queen.first){
                // No longer possible
                possible = false; 
                break;  
            }
            if (abs(r - queen.first) == abs(column - queen.second)){
                possible = false;
                break; 
            }
        }
        if (board[r][column] == 1){
            possible = false;  
        }
        if (!possible){
            continue; 
        }

        // Since it is possible at this point we place a queeen and proceed in the function
        placedQueens.push_back({r, column}); 
        getQueens(column+1, placedQueens);     
        placedQueens.pop_back(); 
    }
}

void placeQueen(){

}

int main(){
    for(int i = 0; i < 8; i++){
        std::string row;
        std::cin >> row; 
        for (int j = 0; j < 8; j++){
            // cout << "(" << row[j] << ") "; 
            if (row[j] == '*'){
                board[i][j] = 1; // First is row, second is column 
            } else {
                board[i][j] = 0; 
            }
        }
        // cout << endl; 
    }

    getQueens(); 

    std::cout << possiblePlacements << std::endl; 
}