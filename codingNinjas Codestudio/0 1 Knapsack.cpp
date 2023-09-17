#include<bits/stdc++.h>
using namespace std;

/* // TLE // inclusion-exclusion //
int knapsackRecur(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    if(n<=0){return 0;}

    int inc=0;
    if(maxWeight>=weight[n-1])
    {
        inc=value[n-1]+knapsackRecur(weight,value,n-1,maxWeight-weight[n-1]);
    }

    int exc=knapsackRecur(weight,value,n-1,maxWeight);

    return max(inc,exc);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return knapsackRecur(weight,value,n,maxWeight);
}
*/

/* // memoisation // inclusion exclusion //
int knapsackRecur(vector<int> &weight, vector<int> &value, int n, int maxWeight,vector<vector<int>> &dq)
{
    if(n<=0){return 0;}

    if(dq[n][maxWeight]!=-1){return dq[n][maxWeight];}

    int inc=0;
    if(maxWeight>=weight[n-1])
    {
        inc=value[n-1]+knapsackRecur(weight,value,n-1,maxWeight-weight[n-1],dq);
    }

    int exc=knapsackRecur(weight,value,n-1,maxWeight,dq);

    return dq[n][maxWeight]=max(inc,exc);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dq(n+1 ,vector<int>(maxWeight+1,-1) );
    return knapsackRecur(weight,value,n,maxWeight,dq);
}
*/

/* // tabulation //
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dq(n+1, vector<int>(maxWeight+1,-1) );

    for(int j=0;j<=maxWeight;j++)
    {
        dq[0][j]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=maxWeight;j++)
        {
            int inc=0;
            if(j>=weight[i-1])
            {
                inc=value[i-1]+dq[i-1][j-weight[i-1]];
            }

            int exc=dq[i-1][j];
            dq[i][j]=max(inc,exc);
        }
    }

    return dq[n][maxWeight];
}
*/

/* // space optimization
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dq(2, vector<int>(maxWeight+1,-1) );

    for(int j=0;j<=maxWeight;j++)
    {
        dq[0][j]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=maxWeight;j++)
        {
            int inc=0;
            if(j>=weight[i-1])
            {
                inc=value[i-1]+dq[0][j-weight[i-1]];
            }

            int exc=dq[0][j];
            dq[1][j]=max(inc,exc);
        }
        dq[0]=dq[1];
    }

    return dq[0][maxWeight];
}
*/

// space and time optimization
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dq(2, vector<int>(maxWeight+1,-1) );

    for(int j=0;j<=maxWeight;j++)
    {
        dq[0][j]=0;
    }

    int preRow=0,postRow=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=maxWeight;j++)
        {
            int inc=0;
            if(j>=weight[i-1])
            {
                inc=value[i-1]+dq[preRow][j-weight[i-1]];
            }

            int exc=dq[preRow][j];
            dq[postRow][j]=max(inc,exc);
        }
        int temp=preRow;preRow=postRow;postRow=temp;
    }

    return dq[preRow][maxWeight];
}

int main()
{
    int n=4,maxWeight=5;
    vector<int> weight={1,2,4,5};
    vector<int> value={5,4,8,6};

    cout<<knapsack(weight,value,n,maxWeight);
    return 0;
}

