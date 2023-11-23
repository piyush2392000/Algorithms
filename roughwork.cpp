#include <bits/stdc++.h>
using namespace std;
        unordered_map<string,vector<string>> graph; 
        unordered_map<string,int> indegree ;
        
        //forming graph
        for(int i=0; i<ingredients.size(); i++){
            for(int j=0; j<ingredients[i].size(); j++){
                graph[ingredients[i][j]].push_back(recipes[i]) ;
                indegree[recipes[i]]++ ;
            }
        }
        
        queue<string> q;
        vector<string> ans ;
        for(int i=0; i<supplies.size(); i++){
            q.push(supplies[i]) ;
        }
        
        while(!q.empty()){
            string node = q.front() ;
            q.pop() ;
            
            for(auto it: graph[node]){
                indegree[it]-- ;
                if(indegree[it] == 0){
                    q.push(it) ;
                    ans.push_back(it) ;
                }
            }
        }
  
        return ans ;

vector<int> solve()
{
       unordered_map<string,vector<string>> graph; 
        unordered_map<string,int> indegree ;
        
        //forming graph
        for(int i=0; i<ingredients.size(); i++){
            for(int j=0; j<ingredients[i].size(); j++){
                graph[ingredients[i][j]].push_back(recipes[i]) ;
                indegree[recipes[i]]++ ;
            }
        }
        
        queue<string> q;
        vector<string> ans ;
        for(int i=0; i<supplies.size(); i++){
            q.push(supplies[i]) ;
        }
        
        while(!q.empty()){
            string node = q.front() ;
            q.pop() ;
            
            for(auto it: graph[node]){
                indegree[it]-- ;
                if(indegree[it] == 0){
                    q.push(it) ;
                    ans.push_back(it) ;
                }
            }
        }
  
        return ans ;

}