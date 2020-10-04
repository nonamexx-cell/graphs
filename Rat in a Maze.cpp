#include <bits/stdc++.h>

using namespace std;

int x[] = {1,0};
int y[] = {0,1};
int flag = 0;
int n;
int isvalid(int a,int b)
{
    if(a<n && b<n && a>=0 && b>=0)
    return 1;
  
    return 0;
}
void call(vector<vector<int>> &maze,int x1,int y1)
{
    

    if(x1 == n-1 && y1 == n-1)
    {
        flag = 1;
        return ;
    }
    
   for(int i=0;i<2;i++)
   {
       if(flag == 1)
         return ;
       if(isvalid(x1+x[i],y1+y[i]) && maze[x1+x[i]][y1+y[i]] == 1)
       {
           
           maze[x1+x[i]][y1+y[i]] = 2;
           call(maze,x1+x[i],y1+y[i]);
           if(flag == 1)
             return ;
            
           maze[x1+x[i]][y1+y[i]] = 1;
       }
   }
    
    
}

int main()
{

    cin>>n;

    vector<vector<int>> maze(n,vector<int>(n,0));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
          cin>>maze[i][j];
    }

     maze[0][0] = 2;
       flag = 0;
    call(maze,0,0);
    
    if(flag == 0)
     cout<<"No its not Possible";
    else
     {
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             {
                 if(maze[i][j] == 2)
                 cout<<maze[i][j]<<" ";
                 else
                  cout<<0<<" ";
             }
             cout<<endl;
         }
     }
    
}
