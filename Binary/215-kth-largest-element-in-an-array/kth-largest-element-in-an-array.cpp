class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      multiset<int> s;

for(int x : nums)
    s.insert(x);

auto it = s.rbegin();

for(int i = 1; i < k; i++)
    it++;

return *it;
    }
};