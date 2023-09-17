#include<bits/stdc++.h>
using namespace std;

// Maximal Rectangle leetcode (using concept of largest area rectangle in a histogram (STACK))

void prevSmallIndex(vector<int>& heights,vector<int>& prev)
{
    stack<int> s;
    s.push(-1);
    int n=heights.size();

    for(int i=0;i<n;i++)
    {
        while(s.top()!=-1&&heights[s.top()]>=heights[i])
        {
            s.pop();
        }
        prev[i]=s.top();
        s.push(i);
    }
}

void nextSmallIndex(vector<int>& heights,vector<int>& next)
{
    stack<int> s;
    int n=heights.size();
    s.push(n);

    for(int i=n-1;i>=0;i--)
    {
        while(s.top()!=n&&heights[s.top()]>=heights[i])
        {
            s.pop();
        }
        next[i]=s.top();
        s.push(i);
    }
}

int largestAreaInHistogram(vector<int>& heights)
{
    int n=heights.size();
    vector<int> prev(n,-1);
    prevSmallIndex(heights,prev);
    vector<int> next(n,n);
    nextSmallIndex(heights,next);

    int ans=0;
    for(int i=0;i<n;i++)
    {
        int h=heights[i];
        int b=next[i]-prev[i]-1;
        ans=max(ans,h*b);
    }
    return ans;
}

int maximalRectangle(vector<vector<char>>& matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    vector<int> heights(m,0);
    int ans=0;


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]=='0')
            {
                heights[j]=0;
            }
            else
            {
                heights[j]++;
            }
        }
        ans=max(ans,largestAreaInHistogram(heights));
    }
    return ans;
}

int main()
{
    vector<vector<char>> matrix={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    //vector<vector<char>> matrix={{'0','1'},{'1','0'}};
    cout<<maximalRectangle(matrix);
    return 0;
}

