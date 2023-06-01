#include<bits/stdc++.h>
using namespace std;

int sumOfMaxAndMin2(vector<int> &nums, int n, int k) // this algorithm is even verified by stress test // can't say why it cant pass codestudio grader //
{
    deque<int> dqmax,dqmin;
    int i=k-1,j=0,sum=0;
    while(i<n)
    {
        while(j<=i)
        {
            while(!dqmax.empty()&&nums[dqmax.back()]<=nums[j])
            {
                dqmax.pop_back();
            }
            dqmax.push_back(j);
            while(!dqmin.empty()&&nums[dqmin.back()]>=nums[j])
            {
                dqmin.pop_back();
            }
            dqmin.push_back(j);
            j++;
        }

        while(dqmax.front()<i-k+1){dqmax.pop_front();}
        while(dqmin.front()<i-k+1){dqmin.pop_front();}

        sum+=nums[dqmax.front()]+nums[dqmin.front()];
        i++;
    }
    return sum;
}

long long sumOfMaxAndMin(vector<int> &nums, int n, int k)
{
    long long sum=0;
    int i=0,j=0;
    set<pair<int,int>> s;

    while(i<n)
    {
        while(j<k&&(i+j)<n)
        {
            s.insert({nums[i+j],i+j});
            j++;
        }
        if(s.size()<k){break;}
        auto it=s.begin();
        sum+=(*it).first;
        it=s.end();--it;
        sum+=(*it).first;
        s.erase({nums[i],i});
        i++;j=k-1;
    }
    s.clear();
    return sum;
}

int main()
{
    /*
    // stress test

    while(true)
    {
        int n=rand()%100000+1;int k=rand()%n+1,i=0;//cin>>n>>k;
        vector<int> nums;
        while(i<n)
        {
            nums.push_back(rand()%1000000000);
            cout<<nums[i]<<"  ";
            i++;
        }

        int x=sumOfMaxAndMin2(nums,n,k)-sumOfMaxAndMin(nums,n,k);
        cout<<x;
        if(x!=0)
        {
            cout<<endl<<endl;
            cout<<"n = "<<n<<"         k = "<<k<<endl;
            for(auto it:nums){cout<<it<<"  ";}
            cout<<endl;
            break;
        }
    }
    */

    int n=rand()%100000+1;int k=rand()%n+1,i=0;//cin>>n>>k;
    vector<int> nums;
    while(i<n)
    {
        nums.push_back(rand()%1000000000);
        cout<<nums[i]<<"  ";
        i++;
    }
    cout<<endl<<sumOfMaxAndMin(nums,n,k);
    cout<<endl<<sumOfMaxAndMin2(nums,n,k);

    return 0;
}


/*
int sumOfMaxAndMin(vector<int> &nums, int n, int k)
{

    deque<int> maxi(k);
    deque<int> mini(k);

    //Addition of first k size window

    for(int i=0; i<k; i++) {

        while(!maxi.empty() && nums[maxi.back()] <= nums[i])
            maxi.pop_back();

        while(!mini.empty() && nums[mini.back()] >= nums[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;

    ans += nums[maxi.front()] + nums[mini.front()];

    //remaining windows ko process karlo
    for(int i=k; i<n; i++)
    {



        //next window

        //removal
        while(!maxi.empty() && i - maxi.front() >=k) {
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >=k) {
            mini.pop_front();
        }

        //addition

        while(!maxi.empty() && nums[maxi.back()] <= nums[i])
            maxi.pop_back();

        while(!mini.empty() && nums[mini.back()] >= nums[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);

        ans += nums[maxi.front()] + nums[mini.front()];
    }
    return ans;
}

*/
