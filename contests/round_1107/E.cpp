#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const ll mod197 = 1e9 + 7;

vector<ll> fact;

ll fastpow(ll number,ll power,ll mod){
    ll answer = 1;
    
    while(power){
        if(power%2){
            answer = (answer * number) % mod;
        }
        number = (number * number) % mod;
        power /= 2;
    }

    return answer;
}

void init_fact(ll n, ll mod){
    fact = vector<ll>(n+1);

    fact[0]=1;
    for(ll i=1;i<=n;++i){
        fact[i] = (fact[i-1]*i)%mod;
    }
}

ll C(ll from,ll take, ll mod){
    ll res = fact[from];
    res = (res*fastpow(fact[take],mod-2,mod))%mod;
    res = (res*fastpow(fact[from-take],mod-2,mod))%mod;
    return res;
}

vector<ll> v[200200];
ll sz[200200];
ll sum1[200200];
ll sum2[200200];
ll par[200200];
ll a[200200];
bool sqs[1001000];
ll n;

void dfs(ll pos){
    sz[pos]=1;
    for(ll i : v[pos]){
        if(sz[i]==0){
            par[i]=pos;
            dfs(i);
            sz[pos]+=sz[i];
        }
    }
}

void solve(){
    cin>>n;
    for(ll i=1;i<=n;++i){
        cin>>a[i];
        sz[i]=0;
        v[i].clear();
    }    

    for(ll i=1,x,y;i<n;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);
    ll res=0;
    //cout<<"----------\n"<<endl;
    vector<ll> nums;
    for(ll i=1;i<=n;++i){
        if(sqs[a[i]]==0)continue;
        nums.clear();

        for(ll j : v[i]){
            if(j==par[i])continue;
            nums.push_back(sz[j]);
        }
        if(n-sz[i])nums.push_back(n-sz[i]);

        //cout<<i<<" - ";
        //for(ll j : nums)cout<<j<<" ";cout<<endl;
        
        if(nums.size()<2)continue;

        sum1[nums.size()]=0;
        sum2[nums.size()]=0;
        for(ll j=nums.size()-1;j>=0;--j){
            sum1[j]=sum1[j+1]+nums[j];
            sum2[j]=sum2[j+1]+sum1[j+1]*nums[j];;
        }

        /*
        for(ll j=0;j<nums.size();++j){
            cout<<sum1[j]<<" ";
        }cout<<endl;
        for(ll j=0;j<nums.size();++j){
            cout<<sum2[j]<<" ";
        }cout<<endl;
        */
        for(ll j=nums.size()-2;j-1>=0;--j){
            res+=sum2[j]*nums[j-1];
        }
        for(ll j=nums.size()-1;j-1>=0;--j){
            res+=sum1[j]*nums[j-1];
        }

    }
    //cout<<"-------";
    cout<<res<<endl;
}

int main(){
    for(ll i=1;;++i){
        if(i*i>1000000)break;
        else sqs[i*i]=1;
    }

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}
/*

*/