#include <bits/stdc++.h>
using namespace std;

int timer = 1;
stack<int> st;


// vis 0 -> not visited 1 -> not in the stack 2 -> in the stack;

void dfs(vector<vector<int>> &edges,int x,vector<int> &lowT,vector<int> &inT,vector<int> &vis){
    
     vis[x] = 2;
     
     lowT[x] = inT[x] = timer++;
     
     st.push(x);

     for(auto y : edges[x]){
          
          if(vis[y] == 2){
               lowT[x] = min(lowT[x],inT[y]);  
          }else if(vis[y] == 0){
               dfs(edges,y,lowT,inT,vis);
               lowT[x] = min(lowT[x],lowT[y]);
          }
     }
   
       vis[x] = 1;
     
     if(lowT[x] == inT[x]){
          
          
           while(true){
                cout<<st.top()+1<<" ";
                if(st.top() == x) {st.pop(); break;}
                st.pop();
           }
           cout<<endl;
     }

}

int main() {
	
	timer = 1;
	
	while(!st.empty()) st.pop();
	
	
	int n,m,x,y; cin>>n>>m;
	
	vector<vector<int>> edges(n);
	
	for(int i=0;i<m;i++) {
	      cin>>x>>y;
	      x--; y--;
	      edges[x].push_back(y);
	}
	
	vector<int> vis(n,0);
	vector<int> inT(n,0);
	vector<int> lowT(n,0);
	
	
	for(int i=0;i<n;i++) if(vis[i] == 0) { dfs(edges,i,lowT,inT,vis); }
	
	
     
	return 0;
}
