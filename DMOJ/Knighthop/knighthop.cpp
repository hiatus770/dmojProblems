#include <bits/stdc++.h>
using namespace std;
const int MD = 8; 
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define x positions[i].first
#define y positions[i].second

bool debug = false; 

pair<int, int> a, b; 
queue<pair<int, int>> q; 
bool visited[MD][MD]; 
int distances[MD][MD];
pair<int, int> positions[8] = {{-2, -1},{-2, 1},{-1, 2},{-1, -2},{2, 1},{1, 2},{2, -1},{1, -2}};

int bfs(pair<int, int> src, pair<int, int> dst){
  q.push(src);
  visited[src.first][src.second] = true; 
  pair<int, int> c; 
  while(!q.empty()){
    c = q.front(); 
    q.pop(); 
    // 8 Directions possible with the Knight


    // DEBUG
    if(debug){
    for(int k = 0; k < 8; k++){
      for(int j = 0; j < 8; j++){
        
      if (k == a.first && j == a.second){
      cout << "A"; 
      } else if (k == b.first && j == b.second){
      cout << "B";
      } else if(visited[j][k] == true){
      cout << "_";
      }  else {
        cout << " "; 
      }
      }
      cout << endl; 
      }
      cout << endl;
    } 


    for(int i = 0; i < 8; i++){
      if(visited[c.first + x][c.second + y] == false && c.first + x >= 0 && c.second + y >= 0 && c.first + x < 8 && c.second + y < 8){
        visited[c.first+x][c.second+y] = true; 
        q.push({c.first+x, c.second+y}); 
        distances[c.first+x][c.second+y] = distances[c.first][c.second] + 1; 
      }
      if(c.first == b.first && c.second == b.second){
        return distances[c.first][c.second]; 
      }
  
    // +1 -2
    // +2 -1
    // +1 +2
    // +2 +1
    // -1 -2 down left
    // -2 -1 down left Y
    // -2 +1 up left Y
    // -1 +2 up left Y
    } 
  }
}

int main(){
  cin >> a.first >> a.second; 
  cin >> b.first >> b.second;
  a = {a.first-1, a.second-1};
  b = {b.first-1, b.second-1}; 
  cout << bfs(a, b); // Returns the amount of moves

}