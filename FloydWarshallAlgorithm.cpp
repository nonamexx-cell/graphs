#include <bits/stdc++.h>
// do not forget to use long long 
using namespace std;
#define mod 1000000007
#define modc 998244353
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vl vector<ll>
#define vul vector<ull>
#define fr(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define ret return
const double pi = 3.14159265359;
void solve()
{
    // floyd Warshall Algorithm
    // time complexity O(n^3)
    // basically it is bruteForce algorithm to find minimum distance between each pair of vertices
    
     int n;   // number of edges.starting from 0
     cin>>n;
     
     vector<vector<ll>> dist(n,vector<ll>(n,INT_MAX));
     
     vector<vector<int>> path(n,vector<int>(n,n)); // to get path
     
        // path value n implies there is no edge from i to j
  
     int m;   // number of edges
     cin>>m;
     int x,y,z;
     for(int i=0;i<m;i++)    
     {
          cin>>x>>y>>z;    // Assuming graph is directed
          dist[x][y] = z;  // edges -> from x to y;
          path[x][y] = y;
     }
     for(int i=0;i<n;i++)
     {
         dist[i][i] = 0;
     }
     
    for(int i=0;i<n;i++)          // checking for all intermediate vertices;
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(dist[j][k] > dist[j][i]+dist[i][k])
                {
                    dist[j][k] = dist[j][i]+dist[i][k];
                    
                    path[j][k] = i;   // to reach k from j we use intermediate vertex i.
                }
            }
        }
    }
    
    for(int i=0;i<n;i++)   // Printing final result.
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j] != INT_MAX)
             cout<<dist[i][j]<<" ";
            else
              cout<<'a'<<" ";
        }
        
        cout<<endl;
    }
   
   // if any diagonal element is -ve implies there is a negative value loop
   
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
       int t = 1;
      cin>>t;
      while(t--)
         solve();
	return 0;
}
