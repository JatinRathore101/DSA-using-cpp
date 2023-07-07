#include<bits/stdc++.h>
using namespace std;

void disp(vector<vector<int>>& ans)
{
    for(auto it:ans)
    {
        for(auto gt:it)
        {
            cout<<gt<<"  ";
        }
        cout<<endl;
    }
}

/* // TLE //
vector<int> _2D_to_1D(vector<vector<int>> &board,int n)
{
    vector<int> v(n*n);
    int k=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            v[k++]=board[i][j];
        }
    }

    return v;
}

bool checkIJ(vector<vector<int>> &board,int i,int j,int n)
{
    for(int k=0;k<n;k++)
    {
        if(board[k][j]==1){return false;}
        if(board[i][k]==1){return false;}
    }

    int I=i-1,J=j-1;
    while(I>=0&&J>=0)
    {
        if(board[I][J]==1){return false;}
        I--;J--;
    }

    I=i+1,J=j-1;
    while(I<n&&J>=0)
    {
        if(board[I][J]==1){return false;}
        I++;J--;
    }

    return true;
}

void solve(vector<vector<int>> &board,int n,int q,vector<vector<int>> &ans)
{
    if(q==n)
    {
        ans.push_back(_2D_to_1D(board,n));
        return;
    }

    for(int j=q;j<n;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(checkIJ(board,i,j,n))
            {
                board[i][j]=1;
                q++;

                solve(board,n,q,ans);

                board[i][j]=0;
                q--;
            }
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> ans;
    if(n<2){ans.push_back({1});return ans;}

    vector<vector<int>> board;

    for(int i=0;i<n;i++)
    {
        vector<int> v(n,0);
        board.push_back(v);
    }

    int q=0,j=0;

    for(int i=0;i<n;i++)
    {
        board[i][j]=1;
        q++;

        solve(board,n,q,ans);

        board[i][j]=0;
        q--;
    }

    return ans;
}
*/







/* // passed all test cases //
vector<int> _2D_to_1D(vector<vector<int>> &board)
{
    vector<int> v;

    for(auto it:board)
    {
        for(auto gt:it)
        {
            v.push_back(gt);
        }
    }

    return v;
}

bool checkIJ(vector<vector<int>> &board,int i,int j,int n)
{
    int I=i,J=j-1;
    while(J>=0)
    {
        if(board[I][J]==1){return false;}
        J--;
    }

    I=i-1,J=j-1;
    while(I>=0&&J>=0)
    {
        if(board[I][J]==1){return false;}
        I--;J--;
    }

    I=i+1,J=j-1;
    while(I<n&&J>=0)
    {
        if(board[I][J]==1){return false;}
        I++;J--;
    }

    return true;
}

void solve(vector<vector<int>> &board,int n,int j,vector<vector<int>> &ans)
{
    if(j==n)
    {
        ans.push_back(_2D_to_1D(board));
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(checkIJ(board,i,j,n))
        {
            board[i][j]=1;

            solve(board,n,j+1,ans);

            board[i][j]=0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> ans;
    if(n<2){ans.push_back({1});return ans;}

    vector<vector<int>> board(n,vector<int>(n,0));

    int j=0;

    solve(board,n,j,ans);

    return ans;
}
*/


vector<int> _2D_to_1D(vector<vector<int>> &board)
{
    vector<int> v;

    for(auto it:board)
    {
        for(auto gt:it)
        {
            v.push_back(gt);
        }
    }

    return v;
}

void solve(vector<vector<int>> &board,int n,int j,vector<vector<int>> &ans,map<int,int> &row_filled,map<int,int> &diag45_filled,map<int,int> &diag135_filled)
{
    if(j==n)
    {
        ans.push_back(_2D_to_1D(board));
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(row_filled[i]==0&&diag45_filled[i+j]==0&&diag135_filled[i-j]==0)
        {
            board[i][j]=1;
            row_filled[i]=1;
            diag45_filled[i+j]=1;
            diag135_filled[i-j]=1;

            solve(board,n,j+1,ans,row_filled,diag45_filled,diag135_filled);

            board[i][j]=0;
            row_filled[i]=0;
            diag45_filled[i+j]=0;
            diag135_filled[i-j]=0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> ans;
    if(n<2){ans.push_back({1});return ans;}

    vector<vector<int>> board(n,vector<int>(n,0));

    map<int,int> row_filled;
    map<int,int> diag45_filled;
    map<int,int> diag135_filled;

    int j=0;
    solve(board,n,j,ans,row_filled,diag45_filled,diag135_filled);

    return ans;
}


int main()
{
    int n=4;
    vector<vector<int>> ans=nQueens(n);
    disp(ans);

    return 0;
}
