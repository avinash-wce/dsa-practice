class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        unordered_map<int,int> NS;
        for(int i = nums2.size() - 1; i >= 0; --i){
            while(s.size() > 0 && s.top() <= nums2[i]){
                s.pop();
            }
            if(s.empty()){
                NS[nums2[i]] = -1;
            } else{
                NS[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); ++i){
            nums1[i] = NS[nums1[i]];
        }
        return nums1;
    }
};