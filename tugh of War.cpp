#include <bits/stdc++.h>

using namespace std;
int len =0;
int mini = INT_MAX;
int sum = 0;
int temp = 0;    // value 
vector<int> vec; //  to store values for temporary
vector<int> ans; // final answer
int n;
void dfs(vector<int> &arr,vector<int> &vis)
{
    
    for(int i=0;i<n;i++)
    {
        if(vis[i] == 0)
        {
            temp = temp+arr[i];
            vec.push_back(arr[i]);
            len = len+1;
            vis[i] = 1;
             if(len == n/2)
             {
                 if(abs(sum-temp-temp) < mini)
                 {
                     ans.clear();
                     ans =  vec;
                     mini = min(abs(mini),abs(sum-temp - temp));
                 }
             }
             else
             {
                 dfs(arr,vis);
             }
             temp = temp-arr[i];
            len = len-1;
            vis[i] = 0;
            vec.pop_back();
        }
        
        
    }
    
}
int main()
{
    //int n;
    cin>>n;
    //len = n/2;
    vector<int> arr(n,0); 
    sum = 0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum = sum+arr[i];
    }
    vector<int> vis(n,0);
    vec.clear();
    dfs(arr,vis);
    cout<<mini<<endl;
    for(auto x : ans)
    {
        cout<<x<<" ";
    }
}
