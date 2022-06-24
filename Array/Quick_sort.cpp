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

int partition(vector<int>&v, int low, int high)
{
    int pivot=v[high];
    int i=low-1;

    for(int j=low;j<high;j++)
    {
        if(v[j]>pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }

    i++;
    swap(v[i], v[high]);

    return i;
}
void quickSort(vector<int>&v, int low, int high)
{

    if(low<high)
    { 
        int partitionIndex=partition(v, low, high);
        quickSort(v, low, partitionIndex-1);
        quickSort(v,partitionIndex+1, high);
    }
}


// time complexity - avg(nlogn), worst(n^2)
// worst case occur when the pivot is always the smallest element or largest element 

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

        quickSort(v,0,n-1);

        for(auto i:v)
        cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}