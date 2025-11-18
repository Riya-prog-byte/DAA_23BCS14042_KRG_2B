//geeks for geeks
class Solution {
  public:
  vector<int> preGreaterEle(vector<int>& arr) {
    int n = arr.size();
  
    // initialize all PGEs as -1
    vector<int> result(n, -1); 
    
    // stack to keep track of elements
    stack<int> st; 

    // traverse the array from left to right
    for (int i = 0; i < n; i++) {
        
        // pop elements from stack which are <= current element
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // if stack is not empty, top element is PGE
        if (!st.empty()) {
            result[i] = st.top();
        }

        // push current element onto stack
        st.push(arr[i]);
    }

    return result;
}

};


//leetcode
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> subNum;
        subNum[0] = 1;
        int total = 0, count = 0;

        for (int n : nums) {
            total += n;

            if (subNum.find(total - k) != subNum.end()) {
                count += subNum[total - k];
            }

            subNum[total]++;
        }

        return count;
    }
};
