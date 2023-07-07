#include<bits/stdc++.h>
using namespace std;

void disp(vector<vector<int>> &paths)
{
    for(auto it:paths)
    {
        for(auto gt:it)
        {
            cout<<gt<<"  ";
        }
        cout<<endl;
    }
}

void _012(vector<vector<int>> &paths,int n)
{
    int m=n*n;
    n=paths.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(paths[i][j]==2){paths[i][j]=1;}else{paths[i][j]=0;}
        }
        paths[i][m-1]=1;
    }
}

vector<int> _2Dto1D(vector<vector<int>> &arr)
{
    vector<int> ans;
    for(auto it:arr)
    {
        for(auto gt:it)
        {
            ans.push_back(gt);
        }
    }
    return ans;
}

void searchMazeUtil(vector<vector<int>> &arr,int n,vector<vector<int>> &paths,int i,int j)
{
    if(i==n-1&&j==n-1){paths.push_back(_2Dto1D(arr));return;}

    if(i<n-1&&arr[i+1][j]==1)
    {
        arr[i][j]=2;
        i++;

        searchMazeUtil(arr,n,paths,i,j);

        i--;
        arr[i][j]=1;
    }

    if(j>0&&arr[i][j-1]==1)
    {
        arr[i][j]=2;
        j--;

        searchMazeUtil(arr,n,paths,i,j);

        j++;
        arr[i][j]=1;
    }

    if(j<n-1&&arr[i][j+1]==1)
    {
        arr[i][j]=2;
        j++;

        searchMazeUtil(arr,n,paths,i,j);

        j--;
        arr[i][j]=1;
    }

    if(i>0&&arr[i-1][j]==1)
    {
        arr[i][j]=2;
        i--;

        searchMazeUtil(arr,n,paths,i,j);

        i++;
        arr[i][j]=1;
    }

    return;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n)
{
    vector<vector<int> > paths;

    if(maze[0][0]==0){return paths;}
    else if(n==1){return maze;}

    int i=0,j=0;

    if(i<n-1&&maze[i+1][j]==1)
    {
        maze[i][j]=2;
        i++;

        searchMazeUtil(maze,n,paths,i,j);

        i--;
        maze[i][j]=1;
    }

    if(j<n-1&&maze[i][j+1]==1)
    {
        maze[i][j]=2;
        j++;

        searchMazeUtil(maze,n,paths,i,j);

        j--;
        maze[i][j]=1;
    }

    _012(paths,n);

    return paths;
}

int main()
{
    int n=3;
    vector<vector<int>> maze={{1,0,1},{1,1,1},{1,1,1}};

    vector<vector<int>> paths=ratInAMaze(maze,n);
    disp(paths);

    return 0;
}

