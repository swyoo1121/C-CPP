#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int card[50001];
int maxtmp_org[50001];
int maxtmp_rev[50001];
vector <int> L_org, L_rev;


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>card[i];
    }
    
    for(int i=0;i<n;i++){
        if(i==0){
            L_org.push_back(card[i]);
            maxtmp_org[i]=1;
        }
        else{
            if(L_org[L_org.size()-1]<card[i]) L_org.push_back(card[i]);
            else *(lower_bound(L_org.begin(), L_org.end(), card[i])) = card[i];
            maxtmp_org[i]=L_org.size();
        }
    }

    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            L_rev.push_back(card[i]);
            maxtmp_rev[i]=1;
        }
        else{
            if(L_rev[L_rev.size()-1]<card[i]) L_rev.push_back(card[i]);
            else *(lower_bound(L_rev.begin(), L_rev.end(), card[i])) = card[i];
            maxtmp_rev[i]=L_rev.size();
        }
    }


    int ans=0;
    for(int i=0;i<n;i++){
        ans = max(ans, maxtmp_org[i]+maxtmp_rev[i]-1);
    }

    cout<<ans;
    return 0;
}