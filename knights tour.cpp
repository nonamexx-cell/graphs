#include <bits/stdc++.h>

using namespace std;

int n;

int count1 = 0;
int x[] = {2,2,-2,-2,1,1,-1,-1};
int y[] = {1,-1,1,-1,2,-2,2,-2};
int isvalid(int a ,int b)
{
    if(a<n && a>=0 && b<n && b>=0 )
       return 1;
       
    return 0;
}
void call(vector<vector<int>> &board,int x1,int y1)
{
    if(count1 == n*n -1)
    {
        return ;
    }
    for(int i=0;i<8;i++)
    {
        if(count1 == n*n -1)
           return ;
        if(isvalid(x1+x[i],y1+y[i]) && board[x1+x[i]][y1+y[i]] == -1)
        {
            count1++;
            board[x1+x[i]][y1+y[i]] = count1;
            
            call(board,x1+x[i],y1+y[i]);
            
            if(count1 == n*n -1)
              return ; 
            count1--;
            board[x1+x[i]][y1+y[i]] = -1;
        }
    }
    
    
    
}


int main()
{
   cin>>n;
   
   vector<vector<int>> board(n,vector<int>(n,-1));
   board[0][0] = 0;
   count1 =0 ;
   call(board,0,0);
   if(count1 == n*n-1)
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(board[i][j]<10)
           cout<<board[i][j]<<"   ";
           else
           cout<<board[i][j]<<"  ";
       }
       cout<<endl;
   }
   else
   cout<<"Not posiible with this number"<<endl;
}
