class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        unordered_set<int> st;

        for(int num : nums) {

            if(st.count(num))
                return num;

            st.insert(num);
        }

        return -1;
    }
};