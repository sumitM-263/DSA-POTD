#include <bits/stdc++.h>
using namespace std;

int maxScore(string s){

    int n=s.size();
    int ans=0;

    for(int i=0;i<n-1;i++){

        int zeros=0,ones=0;

        for(int j=0;j<=i;j++) if(s[j]=='0') zeros++;

        for(int k=i+1;k<n;k++) if(s[k]=='1') ones++;

        ans=max(ans,zeros+ones);
    }

    return ans;
}


int maxScore1(string s){

    int n=s.size();

    int ans=0;

    int zeros=0,ones=0;

    for(auto i:s) i=='0'? zeros++: ones++;

    int z=0,o=0;
    for(int i=0;i<n-1;i++){
        s[i]=='0'? z++: o++;

        ans=max(ans,z+(ones-o));

    }

    return ans;
}

int main(){

    
    string s="011101";
    cout << maxScore1(s) << '\n';

    return 0;
}