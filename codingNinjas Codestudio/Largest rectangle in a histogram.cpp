#include<bits/stdc++.h>
using namespace std;

void disp(vector<int>arr)
{
    for(auto it:arr)
    {
        if(it==-1){cout<<setw(5)<<" ";}
        else{cout<<setw(5)<<it;}
    }
    cout<<endl;
}

vector<int> Next_Smaller_element_Index(vector<int> arr)
{
    stack<int> s;s.push(-1);
    vector<int> ans(arr.size());
    int i=arr.size()-1;
    while(i>=0)
    {
        while(s.top()!=-1&&arr[s.top()]>=arr[i]){s.pop();}
        int x=s.top();
        s.push(i);
        ans[i]=x;
        i--;
    }
    return ans;
}

vector<int> Previous_Smaller_element_Index(vector<int> arr)
{
    stack<int> s;s.push(-1);
    vector<int> ans(arr.size());
    int n=arr.size(),i=0;
    while(i<n)
    {
        while(s.top()!=-1&&arr[s.top()]>=arr[i]){s.pop();}
        int x=s.top();
        s.push(i);
        ans[i]=x;
        i++;
    }
    return ans;
}


/*
int largestRectangle(vector < int > & heights)
{
    heights.push_back(0);heights.push_back(0);int n=heights.size();
    vector<int> temp(n);temp[0]=0;
    for(int i=1;i<n;i++)
    {
        temp[i]=heights[i-1];
    }
    heights=temp;

    vector<int> nse=Next_Smaller_element_Index(heights);
    vector<int> pse=Previous_Smaller_element_Index(heights);
    int Area=0;

    for(int i=0;i<n;i++)
    {
        int base=1;
        if(pse[i]!=-1){base+=i-pse[i]-1;}
        if(nse[i]!=-1){base+=nse[i]-i-1;};
        Area=max(Area,base*heights[i]);
    }
    return Area;
}
*/

int largestRectangle(vector < int > & heights)
{
    int n=heights.size();

    vector<int> nse=Next_Smaller_element_Index(heights);
    vector<int> pse=Previous_Smaller_element_Index(heights);
    int Area=0;

    for(int i=0;i<n;i++)
    {
        int base=1;
        if(pse[i]!=-1){base+=i-pse[i]-1;}
        else{base+=i;}
        if(nse[i]!=-1){base+=nse[i]-i-1;}
        else{base+=n-i-1;}
        Area=max(Area,base*heights[i]);
    }
    return Area;
}

int main()
{
    vector<int> heights={10,6,10,5,3,4,4,6,9,10};
    cout<<endl<<largestRectangle(heights);

    /*
    disp(heights);
    disp(Previous_Smaller_element_Index(heights));
    disp(Next_Smaller_element_Index(heights));
    */

    return 0;
}

