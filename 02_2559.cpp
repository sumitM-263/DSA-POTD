#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
}

// brute force
vector<int> count(vector<string>& words, vector<vector<int>>& queries){

    vector<int> ans;

    for(int i=0;i<queries.size();i++){

        int cnt=0;

        int j=queries[i][0];

        for(;j<=queries[i][1];j++){
            if(isVowel(words[j][0]) and isVowel(words[j][words[j].size()-1])) cnt++;
        }
        
        ans.push_back(cnt);
    }

    for(int& i: ans) cout << i << ' ';
    cout << '\n';
}


// better approach
vector<int> count1(vector<string>& words, vector<vector<int>>& queries){

    vector<int> ans;

    // prefix sum array
    vector<int> A(words.size());

    for(int i=0;i<words.size();i++){
        if(isVowel(words[i][0]) and isVowel(words[i][words[i].size()-1])) A[i]+=1;
    }


    for(int i=1;i<A.size();i++){
        A[i]=A[i]+A[i-1];
    }

    for(int i=0;i<queries.size();i++){
        int l=queries[i][0];
        int r=queries[i][1];

        if(l==0) ans.push_back(A[r]);
        else ans.push_back(A[r]-A[l-1]);
    }

    for(int& i:ans) cout << i << " ";
    
}

int main(){

    int n;
    cin >> n;

    vector<string> words(n);
    for(int i=0;i<n;i++) cin >> words[i];

    int m;
    cin >> m;

    vector<vector<int>> queries;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        queries.push_back({a,b});
    }

    count1(words,queries);


    return 0;
}