class Solution {
public:

    void heapify(vector<int>& nums, int i, int n) {

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        int largest = i;

        if (left < n && nums[left] > nums[largest])
            largest = left;

        if (right < n && nums[right] > nums[largest])
            largest = right;

        if (largest != i) {
            swap(nums[i], nums[largest]);

            heapify(nums, largest, n);
        }
    }

    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, i, n);
        }

        for (int i = n - 1; i > 0; i--) {

            swap(nums[0], nums[i]);
            
            heapify(nums, 0, i);
        }

        return nums;
    }
};