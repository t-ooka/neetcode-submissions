class KthLargest {
private:
    int k_;
    priority_queue<int, vector<int>, greater<int>> min_heap_;

public:
    KthLargest(int k, vector<int>& nums) : k_(k) {
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (min_heap_.size() < k_) {
            min_heap_.push(val);
        } else if (val > min_heap_.top()) {
            min_heap_.pop();
            min_heap_.push(val);
        }

        return min_heap_.top();
    }
};