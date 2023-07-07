#include<bits/stdc++.h>
using namespace std;

void disp(vector<string> &paths)
{
    for(auto it:paths){cout<<it<<endl;}
}

void searchMazeUtil(vector<vector<int>> &arr,int n,string str,vector<string> &paths,int i,int j)
{
    if(i==n-1&&j==n-1){paths.push_back(str);return;}

    if(i<n-1&&arr[i+1][j]==1)
    {
        str.push_back('D');
        arr[i][j]=0;
        i++;

        searchMazeUtil(arr,n,str,paths,i,j);

        i--;
        arr[i][j]=1;
        str.pop_back();
    }

    if(j>0&&arr[i][j-1]==1)
    {
        str.push_back('L');
        arr[i][j]=0;
        j--;

        searchMazeUtil(arr,n,str,paths,i,j);

        j++;
        arr[i][j]=1;
        str.pop_back();
    }

    if(j<n-1&&arr[i][j+1]==1)
    {
        str.push_back('R');
        arr[i][j]=0;
        j++;

        searchMazeUtil(arr,n,str,paths,i,j);

        j--;
        arr[i][j]=1;
        str.pop_back();
    }

    if(i>0&&arr[i-1][j]==1)
    {
        str.push_back('U');
        arr[i][j]=0;
        i--;

        searchMazeUtil(arr,n,str,paths,i,j);

        i++;
        arr[i][j]=1;
        str.pop_back();
    }

    return;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n)
{
    vector<string> paths;

    if(arr[0][0]==0){return paths;}

    int i=0,j=0;string str;

    if(i<n-1&&arr[i+1][j]==1)
    {
        str.push_back('D');
        arr[i][j]=0;
        i++;

        searchMazeUtil(arr,n,str,paths,i,j);

        i--;
        arr[i][j]=1;
        str.pop_back();
    }

    if(j<n-1&&arr[i][j+1]==1)
    {
        str.push_back('R');
        arr[i][j]=0;
        j++;

        searchMazeUtil(arr,n,str,paths,i,j);

        j--;
        arr[i][j]=1;
        str.pop_back();
    }

    return paths;
}

int main()
{
    vector<vector<int>> arr={{0,1,1,1},{1,1,1,0},{1,0,1,1},{0,0,1,1}};
    int n=4;

    vector<string> paths=searchMaze(arr,n);
    disp(paths);

    return 0;
}


