class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        // Hai phần tử đầu tiên
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        // Phân phối các phần tử từ chỉ số 2 trở đi
        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        // Nối arr2 vào sau arr1
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        return arr1;
    }
};