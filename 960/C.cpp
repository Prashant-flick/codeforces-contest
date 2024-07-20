#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll int
#define ull unsigned int
#define loop(i, a, b) for (int i = a; i <= b; i++)

void run() {
    int n;
    cin>>n;
    vector<int> a(n,0),mad(n,0);
    map<int,int> mp;
    int cmax=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
        if(mp[a[i]]>1){
            cmax=max(cmax,a[i]);
        }
        mad[i]=cmax;
    }
    int sum = accumulate(a.begin(), a.end(), 0) + accumulate(mad.begin(), mad.end(), 0);
    while(accumulate(mad.begin(),mad.end(),0)>0){
        map<int,int> mp1;
        int cumax=2;
        for(int i=0;i<mad.size();i++){
            mp1[mad[i]]++;
            if(mp1[mad[i]]>1){
                cumax=max(cumax,mad[i]);
            }
            mad[i]=cumax;
        }
        sum+=accumulate(mad.begin(), mad.end(), 0);
    }
    cout<<sum<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        run();
    }
    return 0;
}