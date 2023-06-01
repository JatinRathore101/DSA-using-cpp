#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> >& M, int n)
{
    stack<int> s;int i=0;
    while(i<n)
    {
        s.push(i);i++;
    }
    while(s.size()!=1)
    {
        int x=s.top();s.pop();
        int y=s.top();s.pop();
        if(M[x][y]==1) // x knows y // x can't be celebrity
        {
            s.push(y);
        }
        else if(M[y][x]==1) // y knows x // y can't be celebrity
        {
            s.push(x);
        }
    }

    int k=s.top();
    i=0;
    while(i<n)
    {
        if(M[k][i]!=0){return -1;}
        i++;
    }
    M[k][k]=1;
    i=0;
    while(i<n)
    {
        if(M[i][k]!=1){return -1;}
        i++;
    }
    return k;
}

int main()
{
    int n=20;
    vector<vector<int>> M(20);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            M[i].push_back(rand()%2);
        }
    }
    int k=rand()%20; // making k as celebrity
    cout<<"k = "<<k<<endl;
    for(int i=0;i<20;i++){M[i][k]=1;}
    for(int j=0;j<20;j++){M[k][j]=0;}
    for(int l=0;l<20;l++){M[l][l]=0;}

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<M[i][j]<<"  ";
        }cout<<endl;
    }

    cout<<celebrity(M,n);
    return 0;
}

/*
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
Follow Up: Can you optimize it to O(N)


Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0},
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity.


Example 2:

Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.


Your Task:
You don't need to read input or print anything. Complete the function celebrity() which takes the matrix M and its size N as input parameters and returns the index of the celebrity. If no such celebrity is present, return -1.


Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(1)


Constraints:
2 <= N <= 3000
0 <= M[][] <= 1

*/
