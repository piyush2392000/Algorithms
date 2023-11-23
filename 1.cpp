#include <bits/stdc++.h>
using namespace std;
 
vector<int>dfs(int v,vector<int>adj[])
{
    vector<bool>vis(n,0)
    int start=0;
    vector<int>ls;
    printdfs(start,adj,vis,ls);
    return ls;
}
void printdfs(int node,vector<int>adj[],vector<int>&vis,vector<int>ls)
{
    vis[node]=1;
    ls.push_back(node);
    for(auto it :adj[node])
    {
        if(!vis[it])
        {
            printdfs(it,adj,vis,ls);
        }

    }
}


int noofconnectedcomp(vector<int>adj[],int v)
{
    vector<bool>vis(n,0);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            cnt++;
            dfs(i,adj,n,vis);
        }
    }
}




vector<int>bfs(int v,vector<int>adj[])
{
    int vis[v]={0};
    queue<int>q;
    q.push(0);
    vector<int>bfs;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        bfs.push(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}





void adjmatrix_to_adjlist(vecto<vector<int>>adj,vector<int>&adjls[],int v)
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(adj[i][j]==1&&i!=j)
            {
                adjls[i].push_back(j);
                adjls[j].push_back(i);
            }
        }
    }
}
//detecting cycle in undirected graphs
bool detect_a_cycle(int src,bool vis[],vector<int>adj[],int v)
{
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});   // {node,parent}
    while(!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto adjacentnode :adj[node])
        {
            if(!vis[adjacentnode])
            {
                q.push({adjacentnode,node});
                vis[adjacentnode]=1;
            }
            else if(parent!=adjacentnode)
            {
                return true;
            }
        }
    }
    return false;
}
// 01 matrxi bfs
vector<vector<int>> nearest1(vector<vector<int>>grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>dis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++)
    {
        for(int i=0;i<m;i++)
        {
            if(grid[i][j]==1)
            {
                vis[i][j]=1;
                q.push({{i,j},0});    //  {{row,col},steps}
            }
        }
    }
    int dr[4]={0,-1,0,+1};
    int dc[4]={-1,0,+1,0};
    while(!q.empty())
    {
        int r=q.front().first.first;
        int c=q.front().first.second;
        int steps=q.front().second;
        q.pop();
        dist[r][c]=steps;
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>0&&nr<n&&nc>0&&nc<m&&vis[nr][nc]==0)
            {
                vis[nr][nc]=1;
                q.push({{nr,nc},steps+1});
            }
        }
    }
    return dis;
}

/*
11011
10000   no of distinct islands =3
00001     
11011

*/
int countdistinctislands(vector<vector<int>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();
    //store the shape in a set data str
    vector<vector<int>>vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>>st;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {

            if(!vis[i][j]&&grid[i][j]==1)
            {
                vector<pair<int,int>>vec;
                dsfm(i,j,vis,grid,vec,i,j);
                st.insert(vec);

            }
        }
    }
    return st.size();
void dfsm(int r,int c,vector<vector<int>>&vis,
    vector<vector<int>>grid,vector<pair<int,int>>&vec,int r0,int c0)
{
    vis[i][j]=1;
    int n=grid.size();
    int m=grid[0].size();
    vec.push_back({r-r0,c-c0});
    int dr[4]={};
    int dc[4]={};
    for(int i=0;i<4;i++)
    {
        int nr=r+dr[i];
        int nc=c+dc[i];
        if(nr>0&&nr<n&&nc>0&&nc<m&&vis[nr][nc]==0&&grid[nr][nc]==1)
        {
           dfs(nr,nc,vis,grid,vec,r0,c0);
        }   
    }


}    

}
//bipartite graph bfs
bool isbipartite(int v,vector<int>adj[])
{
    vector<int>color(v); //here we take color arr in place of vis arr 
    for(int i=0;i<v;i++)
    {
        color[i]=-1;
    }
    queue<int>q;   
    q.push(0);
    color[0]=1;
    while(!q.empty())
    {
        auto node=q.front();
        q.pop()
        for( auto adjnode:adj[node])
        {
            if(color[adjnode]==-1)
            {
               color[adjnode]=!color[node];
               q.push(adjnode);
            }
            else if(color[adjnode]==color[node])
            {
                return false;
            }
        }
    }
    return true;
}
// toposort(bfs)(kahn algo)
vector<int> toposort(vector<int>adj[],int v)
{
    vector<int>vis(v,0);
    vector<int>indegree(v,0);
    queue<int>q;
    for(int i=0;i<v;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
              q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }
    return topo;
}
// aliens dictionary
string findorder(string dict[],n.k)
{
    vector<char>adj[k];
    for(int i=0;i<n;i++)
    {
        string s1=dict[i];
        string s2=dict[i+1];
        int len=min(s1.size(),s2.size());
        for(int it=0;it<min;it++)
        {
            if(s1[it]!=s2[it])
            {
                adj[s1[it]].push_back(s2[it]);
                break;
            }
        }
    }
}



//shortest path in direct acyclic graphs



void toposort(int node,vector<int>&vis,vector<pair<int,int>>adj[],
    stack<int>&st)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            toposort(it,vis,adj,st);
        }
    }
    st.push(node);
}
vector<int> shortestPath(int n,int m,int src,vector<vector<int>>& edges)
{
    // n->nodes m->edges
    // step 1->get the toposort stack...
    vector<pair<int,int>>adj[n];
    for(int i=0;i<m;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
    }
    vector<int>vis(n,0);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            toposort(i,vis,adj,st)
        }
    }

    //step 2->from toposort pick the elements and relax the edges .
    vector<int>dist(n);
    // set the element of distance vector to infinity.
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }
    dist[src]=0;  //dist of src from src =0
    while(!st.empty())
    {
        int  node=st.top();
        st.pop();
        for(auto it:adj[node])
        {
            int v=it.first;
            int wt=it.second;
            if(dist[node]+wt<dist[v])
            {
                dist[v]=dist[node]+wt;
            }
        }
    }
    return dist;
         
}





// shortest distance from a node in undirected graphs using simple bfs

vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        vector<int>adj[n];
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
        }
        queue<pair<int,int>>q;
        vector<int>dist(n);
        for(int i=0;i<n;i++)
        {
            dist[i]=1e9;
        }
        dist[src]=0;
        q.push({src,0});
        while(!q.empty())
        {
            int node=q.front().first;
            int dis=q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                if(dis+1<dist[it])
                {
                    dist[it]=dis+1;
                    q.push({it,dist[it]});
                }
            }
        }
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
            if(dist[i]!=1e9)
            {
                ans[i]=dist[i];
            }
        }
        return ans;
}


// WORD LADDER


int wordLadderLength(string startWord, 
    string targetWord, vector<string>& wordList) 
{
    queue<pair<string,int>>q;
    q.push({startWord,1});
    set<string>st(wordList.begin(),wordList.end());
    st.erase(startWord);
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        string word=it.first;
        int steps=it.second;
        if(word==targetWord){return steps;}
        for(int i=0;i<word.size();i++)
        {
            char original=word[i];
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(st.find(word)!=st.end())
                {
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i]=original;
        }

    }
    return 0;
}

// word ladder 2
vector<vector<string>> findSequences(string beginWord, 
    string endWord, vector<string>& wordList) 
{ 
    set<string>st(wordList.begin(),wordList.end());
    queue<vector<string>>q;
    q.push({beginWord});
    vector<string>usedonlvl;
    usedonlvl.push_back(beginWord);
    int lvl=0;
    vector<vector<string>>ans;
    while(!q.empty())
    {
        vector<string>vec=q.front();
        q.pop();
        if(vec.size()>lvl)
        {
            lvl++;
            for(auto it:usedonlvl)
            {
                st.erase(it);
            }
        }
        string word=vec.back();
        if(word==endWord)
        {
            if(ans.size()==0)
            {
                ans.push_back(vec);
            }
            else if(ans[0].size()==vec.size())
            {
                ans.push_back(vec);
            }
        }
        for(int i=0;i<word.size();i++)
        {
            char original=word[i];
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(st.count(word)>0)
                {
                    vec.push_back(word);
                    q.push(vec);
                    usedonlvl.push_back(word);
                    vec.pop_back();
                }
            }
            word[i]=original;
        }
    }
    return ans;
}

// dijkstra algo 

vector<int> dijkstra(vector<vector<int>>adj[],int V,int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>;
    vector<int>dist(V,1e9);
    dist[s]=0;
    pq.push({0,s})   // {dist,node}
    while(!pq.empty())
    {
        dis=pq.top().first;
        node=pq.top().second;
        pq.pop();
        for( auto it:adj[node])
        {
            int ew=it[1];
            int adjnode=it[0];
            if(dis+ew<dist[adjnode])
            {
                dist[adjnode]=dis+ew;
                pq.push(dist[adjnode],adjnode);
            }
        }
    }
    return dist;
}

// finding shortest path in weighted undirected graphs(USING DIJKSTRA AND PARENT ARRAY)

vector<int> dijkstra(vector<pair<int,int>>adj[],int V,int s,int d)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>;
    vector<int>parent(V);
    for(int i=0;i<V;i++)
    {
        parent[i]=i;
    }
    vector<int>dist(V,1e9);
    dist[s]=0;
    pq.push({0,s});
    while(!pq.empty())
    {
        dis=pq.top().first;
        node=pq.top().second;
        for( auto it:adj[node])
        {
            int ew=it[1];
            int adjnode=it[0];
            if(dis+ew<dist[adjnode])
            {
                dist[adjnode]=dis+ew;
                parent[adjnode]=node;
                pq.push(dist[adjnode],adjnode);
            }
        }
    }
    if(dist[d]==1e9){return {-1};}  // unable to reach the destination
    // step 2->retreiving path from parent vector
    vector<int>path;
    int node=d
    while(parent[node]!=node)
    {
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(0);
    reverse(path.begin(),path.end());
    return path;
}

// shortest distance in binary maze
int func(vector<vector<int>>grid,pair<int,int>s,pair<int,int>d)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    queue<pair<int,pair<int,int>>>q;
    int dr[4]={};
    int dc[4]={};
    q.push({0,{s.first,s.second}});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        int r=it.second.first;
        int c=it.second.second;
        int dis=it.first;
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==1&&dis+1<dist[nr][nc])
            {
                dist[nr][nc]=1+dis;
                if(nr==d.first&&nc=d.second)
                {
                    return dis+1;
                }
                q.push({1+dis,{nr,nc}});
            }
        }

    }
    return -1;

}

//  path with minimum efforts
int minimumEffortPath(vector<vector<int>>& h) 
{
    int n=h.size();
    int m=h[0].size();
    vector<vector<int>dist(n,vector<int>(m,1e9));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    q.push({0,{0,0}});
    dist[0][0]=0;
    int dr[4]={-1, 0, 1, 0};
    int dc[4]={0, 1, 0, -1};
    while(!q.empty())
    {
        auto it=q.top();
        int dis=it.first;
        int r=it.second.first;
        int c=it.second.second;
        if(r==n-1&&c==m-1){return dis;}
        for(int i=0;i<4;i++)
        {
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0&&nc>=0&&nr<n&&nc<m)
            {
                int neweff=max(abs(h[r][c]-h[nr][nc]),dis);
                if(neweff<dist[nr][nc])
                {
                    dist[nr][nc]=neweff;
                    q.push({neweff,{nr,nc}});
                }

            }
        }
    }
    return 0;
}
// no of ways to reach at destination  
int countPaths(int n, vector<vector<int>>& roads)
{
    // n->nodes
    // roads->{n1,n2,time}->connections
    vector<pair<int,int>>adj[n];

    vector<int>ways(n,0);
    vector<int>dist(n,1e9);
    ways[0]=1;    // src=0
    dist[0]=0;
    priority_queue<pair<int,int>>pq;
    pq.push({0,0});
    while(!pq.empty())
    {
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();
        for(auto it:adj[node])
        {
            int adjnode=it.first;
            int edw=it.second;
            if(dis+edw<dist[adjnode])
            {
                dist[adjnode]=dis+edw;
                ways[adjnode]=ways[node];
                pq.push({dis+edw,adjnode});
            }
            else if(dis+edw==dist[adjnode])
            {
                ways[adjnode]=ways[adjnode]+ways[node];
            }


        }

    }
    return ways[n-1]%mod;
        
} 

// prims algorithm

int spanningTree(int v, vector<vector<int>> adj[])
{
    //prims algo
    vector<int>vis(v,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int sum=0;
    pq.push({0,0});
    while(!pq.empty())
    {
        int node=pq.top().second;
        int wt=pq.top().first;
        pq.pop();
        if(vis[node]==1)continue;
        
        vis[node]=1;
        sum+=wt;
        for(auto it:adj[node])
        {
            int adjnode=it[0];
            int ewt=it[1];
            if(!vis[adjnode])
            {
                pq.push({ewt,adjnode});
            }
        }
    }
    return sum;
}

//dsu disjoint set union
class disjointset
{
    vector<int>parent;
    vector<int>rank;
public: disjointset(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
            }
        }
        int findupar(int node)
        {

            if(parent[node]==node){return node;}
            return findupar(parent[node]);
        }
        void unionbyrank(int u,int v)
        {
            ulp_u=findupar(u);
            ulp_v=findupar(v);
            if(ulp_u==ulp_v)return;
            if(rank[ulp_u]>rank[ulp_v]){
                parent[ulp_v]=ulp_u;
            }
            else if(rank[ulp_u]<rank[ulp_v])
            {
                parent[ulp_u]=ulp_v;
            }
            else
            {
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }


        }    
}

//kruskals algorithm
int spanningTree(int v, vector<vector<int>> adj[])
{
    vector<pair<int,pair<int,int>>>edges;
    for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
    }
    disjointset ds(v);
    sort(edges.begin(),edges.end());
    int mst=0;
    for(auto it:edges)
    {
        int u=it.second.first;
        int v=it.second.second;
        int wt=it.first;
        if(ds.findupar(u)==ds.findupar(v))continue;
        else 
        {
            mst+=wt;
            ds.unionbyrank(u,v);

        }
    }
    return mst;
}

// min no of operation to make graph connected

int makeConnected(int n, vector<vector<int>>& connections)
{
        disjointset ds(n);
        int cntextra=0;
        for(auto it:connections)
        {
            int v=it[0];
            int u=it[1];
            if(ds.findupar(u)==ds.findupar(v)){cntextra++;}
            else
            {
                ds.unionbyrank(u,v);
            }

        }
        int cntused=0;
        for(int i=0;i<n;i++)
        {
            if(ds.findupar(i)==i){cntused++;}
        }
        int ans=cntused-1;
        if(cntextra>ans){return ans;}
        else{return -1;}
        
}

int main(){
	int n,m;    //n->nodes,m->edges
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

}
