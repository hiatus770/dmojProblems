void bfs(){
    q.push({1, 1}); 
    pInt c; 
    int xa[] = {1, -1, 0, 0}; 
    int ya[] = {0, 0, 1, -1}; 
    visited[1][1] = true; 
    while(!q.empty()){
        c = q.front(); 
        q.pop(); 
        int x = c.f; int y = c.s; 
        //cout << "X: " << x << " Y: " << y << endl; 
        for (int i = 0; i < 4; i++){
            if (x+xa[i] <= n && x+xa[i] >= 1 && y+ya[i] >= 1 && y+ya[i] <= m && !visited[x+xa[i]][y+ya[i]]){
                //cout << x+xa[i] << " " << y+ya[i] << endl;
                q.push({x+xa[i], y+ya[i]});
                visited[x+xa[i]][y+ya[i]] = true;  
            }
        }
    }

}