#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
 
typedef unsigned long long ull;
typedef long long ll;
 
int n;
int a[200200];
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
 
    ll res=0;
    int gc,curdif,x,x1;
    for(int i=1;i<=n;++i){
        gc=a[i];
        curdif=-1;

        for(int j=i+1;j<=n;++j){
            x=(a[j]%a[i])+a[i];
 
            x%=gc;
            x1=gc-x;
            curdif = max(curdif,min(x,x1));
 
            if(gc<=curdif+1){
                res+=(ll(n-j+1))*((ll)curdif);
                break;
            }
            
            res+=(ll)curdif;
            gc=__gcd(gc,x);
        }
    }
    cout<<res<<"\n";
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
/*
 
*/