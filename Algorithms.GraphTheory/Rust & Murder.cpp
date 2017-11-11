#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<deque>
using namespace std;
/*
https://www.hackerrank.com/challenges/rust-murderer
This solution cannot pass last test case
*/  
std::unordered_map<int,int> dfs(std::unordered_map<int,std::unordered_set<int> >& mat,int V,int st){
    int u,v,j;
    std::deque<int> dq;
    dq.push_back(st);
    
    std::unordered_set<int> unvisited;
    for(j = 1;j<V+1;j++)
        unvisited.insert(j);
    unvisited.erase(st);
    
    std::unordered_map<int,int> res;
    res[st] = 0;
    while(dq.size() != 0){
        v = dq.front();
        dq.pop_front();
        
        std::vector<int> toBeRemoved;
        for(auto i = unvisited.begin();i!=unvisited.end();i++){
            u = *i;
            if(mat[v].find(u) == mat[v].end()){
                dq.push_back(u);
                res[u] = res[v] + 1;
                toBeRemoved.push_back(u);
            }
        }
        for(auto i = toBeRemoved.begin();i!=toBeRemoved.end();i++){
            unvisited.erase(*i);
        }
    }
    return res;
}   
int main(){
    //std::ifstream cin("input.txt");
    int case_num,i,j;
    cin >> case_num;
    
    for(i=0;i<case_num;i++){
        int V,E,a,b,st;
        cin >> V >> E;
        
        std::unordered_map<int,std::unordered_set<int> > mat;
        
        for(j=0;j<E;j++){
            cin >> a >> b;
            mat[a].insert(b);
            mat[b].insert(a);
        }
        
        cin >> st;
        auto res = dfs(mat,V,st);
        
        for(j=1;j<V+1;j++){
            if(j != st)
                std::cout<<res[j]<<" ";
        }
        printf("\n");
    }
    //cin.close();
    return 0;
}
