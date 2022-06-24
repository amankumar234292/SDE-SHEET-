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

int findPairSum(vector<int> arr, int target)
{
    int pivot=-1,i,j,n=arr.size();

    for(i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            pivot=i;
            break;
        }
    }
    int first;
    int second;
    int cnt=0;
    int cnt2=0;

    if(pivot==-1){
        first=0;
        second=n-1;
    }

    else {
        first=pivot+1;
        second=pivot;
    }
   
    while(first!=second)
    {
        // cout<<first<<" "<<second<<endl;
        if(arr[first]+arr[second]==target)
        return true;

        else if(arr[first]+arr[second]<target)
        {
            first++;
            if(first==n)
            {
                if(cnt==2)
                break;
                first=0;
                cnt++;
            }
        }

        else 
        {
            second--;
            if(second<0)
            {
                if(cnt2==2)
                break;
                second=n-1;
                cnt2++;
            }
        }
    }

    return false;
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
        ll i,j,n,k;
        cin>>n>>k;

        vector<int>v(n);

        for(i=0;i<n;i++)
        cin>>v[i];

        cout<< findPairSum(v,k)<<endl;
    }
    return 0;
}
