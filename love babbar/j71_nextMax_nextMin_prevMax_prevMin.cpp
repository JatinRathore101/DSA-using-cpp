#include<bits/stdc++.h>
using namespace std;

void disp(vector<int> arr)
{
    for(auto it:arr)
    {
        //cout<<it<<"  ";
        if(it==INT_MIN||it==INT_MAX){cout<<setw(5)<<" ";}
        else{cout<<setw(5)<<it;}
    }
    cout<<endl;
}

vector<int> Next_Smaller_Element(vector<int> arr)
{
    int i=arr.size()-1;
    stack<int> s;s.push(INT_MIN);
    while(i>=0)
    {
        while(s.top()>=arr[i]){s.pop();}
        int x=s.top();
        s.push(arr[i]);
        arr[i]=x;
        i--;
    }
    return arr;
}

vector<int> Previous_Smaller_Element(vector<int> arr)
{
    int n=arr.size(),i=0;
    stack<int> s;s.push(INT_MIN);
    while(i<n)
    {
        while(s.top()>=arr[i]){s.pop();}
        int x=s.top();
        s.push(arr[i]);
        arr[i]=x;
        i++;
    }
    return arr;
}

vector<int> Next_Greater_Element(vector<int> arr)
{
    int i=arr.size()-1;
    stack<int> s;s.push(INT_MAX);
    while(i>=0)
    {
        while(s.top()<=arr[i]){s.pop();}
        int x=s.top();
        s.push(arr[i]);
        arr[i]=x;
        i--;
    }
    return arr;
}

vector<int> Previous_Greater_Element(vector<int> arr)
{
    int n=arr.size(),i=0;
    stack<int> s;s.push(INT_MAX);
    while(i<n)
    {
        while(s.top()<=arr[i]){s.pop();}
        int x=s.top();
        s.push(arr[i]);
        arr[i]=x;
        i++;
    }
    return arr;
}

int main()
{
    vector<int> arr(20);int i=0;
    while(i<20)
    {
        arr[i]=rand()%19-9;i++;
    }
    cout<<"Next Smaller Element array "<<endl;
    disp(arr);
    disp(Next_Smaller_Element(arr));
    cout<<endl;

    cout<<"Previous Smaller Element array "<<endl;
    disp(arr);
    disp(Previous_Smaller_Element(arr));
    cout<<endl;

    cout<<"Next Greater Element array "<<endl;
    disp(arr);
    disp(Next_Greater_Element(arr));
    cout<<endl;

    cout<<"Previous Greater Element array "<<endl;
    disp(arr);
    disp(Previous_Greater_Element(arr));
    cout<<endl;

    return 0;
}

