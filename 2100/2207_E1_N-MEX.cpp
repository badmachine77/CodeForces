#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod197 = 1e9 + 7;

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

ll res[200200];
ll a[200200];
ll n;
bool used[200200];

void solve(){
    //cout<<endl<<endl;
    
    cin>>n;
    for(int i=0;i<n+100;++i){
        used[i]=0;
        a[i]=0;
    }

    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        if(a[i]>n){
            cout<<"NO"<<endl;
            return ;
        }
        used[a[i]]=1;
    }

    ll cnt=n-1;
    while(cnt>-1 && used[cnt]){--cnt;}

    if(a[1]==n){
        res[1]=cnt;
        --cnt;
        while(cnt>-1 && used[cnt]){--cnt;}
    }
    else if(a[1]==n-1){
        res[1]=n+10;
    }
    else {
        cout<<"NO"<<endl;
        return ;
    }
    for(int i=2;i<=n;++i){
        if(a[i]==a[i-1]){
            if(cnt==-1){
                cout<<"NO"<<endl;
                return ;
            }
            res[i]=cnt;
            --cnt;
            while(cnt>-1 && used[cnt]){--cnt;}
        }
        else if(a[i]<a[i-1]){
            if(cnt>a[i]){
                cout<<"NO"<<endl;
                return ;
            }
            else {
                res[i] = n+10;
            }
        }
        else {
            cout<<"NO"<<endl;
            return ;
        }
    }

    if(cnt!=-1){
        cout<<"NO"<<endl;
        return ;
    }

    cout<<"YES"<<endl;
    for(int i=1;i<n;++i)cout<<res[i]<<" ";
    cout<<res[n]<<endl;
}

int main(){

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/*
6
3
3 3 1
3
2 1 3
1
0
1
2
4
7 5 2 2
6
6 6 6 4 3 3


6 5 4 3 2 1

1<6 1
2<6 2
3<6 3
2<4 4
2<3 5
3<3 6

5 2 1 5 2 0


xoxxxoxxxoxoxxo


skip turn mahane 1e9+7

mahane na po malko - sushtoto mqsto
skip turn - iztrel nagore.. skip string xxx i tam
manane na neshto otgore - iztrel tam
*/