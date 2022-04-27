map<ll, vector<ll>> adj;
#define contains(x) (adj.find(x) != adj.end())
ll N;
int main(){
    init;
    ll R = nxtl, C = nxtl, K = nxtl, r, c;
    ll curPos;
    N = R * C;
    ll upper = 2 * N, bottom = 2 * N + 1;
    adj[upper] = vector<ll>();
    for (int i = 0; i < K; i++)
    {
        read(r, c), r--, c--, curPos = r * C + c;
        adj[curPos] = vector<ll>();
        if (r == 0 || c == C-1) //located on the upper corner
            adj[upper].push_back(curPos);
        if (r == R-1 || c == 0)
            adj[curPos].push_back(bottom);
        
    }
    
    for (auto &p : adj)  
    {
        curPos = p.first;
        if (curPos%C != C-1) 
        {
            if (contains(curPos+1)) //left
                adj[curPos].push_back(curPos + 1);
            if (contains(curPos+1-C)) //upper left
                adj[curPos].push_back(curPos + 1 - C);
            if (contains(curPos+1+C)) //bottom left
                adj[curPos].push_back(curPos + 1 + C);
        }
        if (curPos%C != 0) 
        {
            if (contains(curPos-1)) //right
                adj[curPos].push_back(curPos - 1);
            if (contains(curPos-1-C)) //upper right
                adj[curPos].push_back(curPos -1 - C);
            if (contains(curPos-1+C)) //bottom right
                adj[curPos].push_back(curPos -1 + C);
        }
        if (contains(curPos+C)) //down
            adj[curPos].push_back(curPos + C);
        if (contains(curPos-C)) //up
            adj[curPos].push_back(curPos - C);
        
    }
    set<ll> visited;
    queue<ll> q;
    q.push(upper), visited.insert(upper);
    ll v;
    while (!q.empty())
    {
        v = q.front(), q.pop();
        if (v == bottom)
            pc('N'), pc('O'), flush, exit(0);
        for (ll &w: adj[v])  
        {
            if (visited.find(w) == visited.end())
            {
                visited.insert(w), q.push(w);
            }
        }   
    }
    pc('Y'), pc('E'), pc('S');
    flush;
}