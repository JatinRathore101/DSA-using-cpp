#include<bits/stdc++.h>
using namespace std;

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

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> paths;

    if(m[0][0]==0){return paths;}

    int i=0,j=0;string str;

    if(i<n-1&&m[i+1][j]==1)
    {
        str.push_back('D');
        m[i][j]=0;
        i++;

        searchMazeUtil(m,n,str,paths,i,j);

        i--;
        m[i][j]=1;
        str.pop_back();
    }

    if(j<n-1&&m[i][j+1]==1)
    {
        str.push_back('R');
        m[i][j]=0;
        j++;

        searchMazeUtil(m,n,str,paths,i,j);

        j--;
        m[i][j]=1;
        str.pop_back();
    }

    return paths;
}

int main()
{
    return 0;
}

