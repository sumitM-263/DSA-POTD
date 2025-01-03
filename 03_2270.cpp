#include <bits/stdc++.h>
using namespace std;

long long count(vector<int>& nums){
    long long ans=0;
    int n=nums.size();

    long long leftSum=0;

    for(int i=0;i<n-1;i++){
        leftSum+=nums[i];

        long long rightSum=0;
        for(int j=i+1;j<n;j++){
            rightSum+=nums[j];
        }

        if(leftSum>=rightSum) ans++;
    }

    return ans;
}

long long count1(vector<int>& nums){
    long long ans=0;
    int n=nums.size();

    long long totalSum=0;
    for(auto& i:nums) totalSum+=i;

    long long leftSum=0;

    for(int i=0;i<n-1;i++){
        leftSum+=nums[i];

        if(leftSum>=(totalSum-leftSum)) ans++;
    }

    return ans;
}

int main(){

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    long long ans=count1(nums);

    cout << ans << '\n';

}