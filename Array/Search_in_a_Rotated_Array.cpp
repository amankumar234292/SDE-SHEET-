// #include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;
// #define ll              long long int
// #define endl            "\n"
// #define MOD             1e9 + 7
// #define test()          ll t; cin>>t; while(t--)
// #define precision(x,y)  fixed<<setprecision(y)<<x
// #define ordered_set     tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
// bool compare(ll a,ll b)
// {
//     return a<b;
// }

// int search_(int A[], int low, int high, int key)
// {
//     while(low<=high)
//     {
//         int mid=(low+high)/2;

//         if(A[mid]==key)
//         return mid;

//         else if(A[low]<=A[mid])
//         {
//             if(key>=A[low] and key<=A[mid])
//             high=mid-1;

//             else 
//             low=mid+1;   
//         }


//         else if(A[mid]<=A[high])
//         {
//             if(key>=A[mid] and key<=A[high])
//             low=mid+1;

//             else 
//             high=mid-1;
//         }
//     }

//     return -1;
// }

// int main ()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);  
//     // test()
//     {
//         ll i,j,n,key;
//         cin>>n>>key;

//         int arr[n];

//         for(i=0;i<n;i++)
//         cin>>arr[i];

//         cout<<search_(arr,0,n-1, key );

//     }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(vector<vector<char>>v,ll n,ll m)
{
    ll dp[n][m],i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        dp[i][j]=0;
    }

    // set last column of dp 
    for(i=0;i<n;i++)
    {
        if(v[i][m-1]=='1')
        dp[i][m-1]=1;
    }

    // set last row of dp
    for(i=0;i<m;i++)
    {
        if(v[n-1][i]=='1')
        dp[n-1][i]=1;
    }

    // set first column of dp
    for(i=0;i<n;i++)
    {
        if(v[i][0]=='1')
        dp[i][0]=1;
    }


    // constructing the dp array 
    for(i=n-2;i>=0;i--)
    {
        for(j=m-2;j>=1;j--)
        {
            if(v[i][j]=='1')
            dp[i][j]=min({dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]})+1;
        }
    }

    ll ans=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            ans=max(ans,dp[i][j]);
        }
    }

    return ans;
}


int main ()
{


    vector<vector<char>>v 
    {
            {'0','0','1','0','1','0','0'},
            {'0','1','1','1','1','1','0'},
            {'1','1','1','1','1','1','1'},
            {'0','1','1','1','1','1','0'},
            {'0','0','1','0','1','0','0'},
    };

    ll row=v.size();
    ll col=v[0].size();
    ll ans=INT_MIN;
    ll cnt=4;

    // code for rotating n*m matrix 4 time to check maximum triangle 
    while(cnt--)
    {

        vector<vector<char>>rot(col, vector<char>(row));
        int i,j;
        for(i=0;i<row;i++)
            for(j=0;j<col;j++)
                rot[j][row-1-i]=v[i][j];

        swap(row,col);
        v=rot;

        ans=max(ans, solve(v,row, col));
        
    }

    cout<<ans<<endl;

    return 0;
}