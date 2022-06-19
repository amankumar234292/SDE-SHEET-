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

vector<int> usingHashing(vector<int>a)
{
    vector<int>ans(2,0);
    int n=a.size();
    unordered_map<int,bool>mp;
    int i;
    for(i=0;i<n;i++)
    mp[i+1]=false;
        
    for(i=0;i<n;i++)
    {
        if(mp[a[i]]==false)
        mp[a[i]]=true;
            
        else if(mp[a[i]]==true)
        ans[0]=a[i];
        
    }
        
    for(auto i:mp)
    {
        if(i.second==false)
        {
            ans[1]=i.first;
        }
    }
        
    return ans;
}


vector<int> numberTheory(vector<int>v)
{
    int S=(v.size()*(v.size()+1))/2;
    int sum=accumulate(v.begin(),v.end(),0);

    int difference=S-sum;
    // cout<<difference<<endl;

    int squareSum=0;
    int square=(v.size()*(v.size()+1)*(2*v.size()+1))/6;

    for(auto i:v)
    squareSum+=i*i;

    int square_diff=square-squareSum;
    // cout<<square_diff<<endl;

    int add=square_diff/difference;
    // cout<<add<<endl;

    int first=(add+difference)/2;
    int second=(add-difference)/2;

    vector<int>ans(2);
    ans[0]=first;
    ans[1]=second;

    return ans;
}


vector<int> xorMethod(vector<int>v)
{
    int n=v.size(),i,xor_;

    xor_=v[0];
    for(i=1;i<n;i++)
    xor_^=v[i];

    for (i = 1; i <= n; i++)
        xor_ = xor_ ^ i;
    // cout<<xor_<<endl;

    int set_bit_no = xor_ & ~(xor_ - 1);
    int x=0, y=0;
    for(i=0;i<n;i++)
    {
        if(v[i]&set_bit_no)
        x^=v[i];

        else 
        y^=v[i];
    }
    for(i=1;i<=n;i++)
    {
        if(set_bit_no&i)
        x^=i;

        else 
        y^=i;
    }
    // cout<<x<<" "<<y<<endl;

    int cnt=0;

    for(i=0;i<n;i++)
    {
        if(v[i]==x)
        cnt++;
    }

    if(cnt>=1)
    return {x,y};

    return {y,x};
}

int main ()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    // test()
    {
        ll i,j,n;
        cin>>n;

        vector<int>v(n);

        for(i=0;i<n;i++)
        cin>>v[i];

        for(auto i:xorMethod(v))
        cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}