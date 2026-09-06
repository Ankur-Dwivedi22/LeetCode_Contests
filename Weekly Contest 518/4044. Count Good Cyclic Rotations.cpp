// TC : O(N)
// SC : O(N)
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        for(int num : nums){
            arr.push_back(num);
        }
        
        vector<long long> pre(2*n+1, 0);
        for(int i=1; i<=2*n; i++){
            pre[i] = pre[i-1] + arr[i-1];
            // cout<<pre[i]<<" ";
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            int l = i, r = i + n;
            long long left = pre[l+n/2] - pre[l];
            long long right = pre[r] - pre[l+n/2];
            // cout<<left<<" "<<right<<"\n";
            if(left > right) ans++;
        }

        return ans;
    }
};
