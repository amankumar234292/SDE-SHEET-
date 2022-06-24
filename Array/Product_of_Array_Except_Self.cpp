#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll              long long int
#define endl            "\n"
#define MOD             1e9 + 7
#define test()          ll t; cin>>t; while(t--)
#define precision(x,y)  fixed<<setprecision(y)<<x
#define ordered_set     tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
bool compare(ll a,ll b)
{
    return a<b;
}

// using division operator
vector<int> productExceptSelf(vector<int>& nums) 
{
    vector<int>ans;
    int totalProduct=1;
    int cnt0=0;

    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=0)
        totalProduct*=nums[i];
        else cnt0++;
    }
    cout<<totalProduct<<endl;

    for(int i=0;i<nums.size();i++)
    {
        if(cnt0>1)
        ans.push_back(0);

        else if(cnt0==1)
        {
            if(nums[i]==0)
            ans.push_back(totalProduct);

            else 
            ans.push_back(0);
        }

        else 
        ans.push_back(totalProduct/nums[i]);
    } 

    return ans;       
}

// using without division operaotr 

vector<int> productExceptSelf2(vector<int>& nums) 
{
    vector<int>ans(nums.size());
    vector<int>prefix(nums.size()),postfix(nums.size());
    int product=1;

    for(int i=0;i<nums.size();i++)
    {
        product*=nums[i];
        prefix[i]=product;
    } 

    product=1;
    for(int i=nums.size()-1;i>=0;i--)
    {
        product*=nums[i];
        postfix[i]=product;
    }

    for(int i=0;i<nums.size();i++)
    {
        if(i==0)
        ans[i]=postfix[1];

        else if(i==nums.size()-1)
        ans[i]=prefix[nums.size()-2];

        else 
        ans[i]=prefix[i-1]*postfix[i+1];
    }

    return ans;
}

int main ()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    test()
    {
        ll i,j,n;
        cin>>n;

        vector<int>v(n);

        for(i=0;i<n;i++)
        cin>>v[i];

        for(auto i:productExceptSelf2(v))
        cout<<i<<" ";
        cout<<endl;
      
    }
    return 0;
}