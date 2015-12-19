class Solution {
  int* heap;
  int capacity;
  int heapSize;
public:
  int parent(int idx) { return (idx - 1) / 2; }
  int leftChildIdx(int idx)  { return 2 * idx + 1; }
  int rightChildIdx(int idx) { return 2 * idx + 2; }
  void insertKey(int key);
  void maxHeapify(int idx);
  int extractMax();
  int findKthLargest(vector<int>& nums, int k);
  int findKthLargestUtil(vector<int>& nums, int begin, int end, int k);
  int partition(vector<int>& nums, int begin, int end);
};

void Solution::insertKey(int key) {
  if (heapSize == capacity) { return; }
  heap[heapSize++] = key;
  int idx = heapSize - 1;
  while (idx && heap[parent(idx)] < heap[idx]) {
    swap(heap[parent(idx)], heap[idx]);
    idx = parent(idx);
  }
}

void Solution::maxHeapify(int idx) {
  int left = leftChildIdx(idx);
  int right = rightChildIdx(idx);
  int largestSoFar = idx;
  if (left < heapSize && heap[left] > heap[largestSoFar])   largestSoFar = left;
  if (right < heapSize && heap[right] > heap[largestSoFar])  largestSoFar = right;
  if (largestSoFar != idx) {
    swap(heap[largestSoFar], heap[idx]);
    maxHeapify(largestSoFar);
  }
} 

int Solution::extractMax() {
  if (!heapSize)  return INT_MIN;
  if (heapSize == 1) { return heap[--heapSize]; }
  int root = heap[0];
  heap[0] = heap[--heapSize];
  maxHeapify(0);
  return root;
}

int Solution::findKthLargestUtil(vector<int>& nums, int begin, int end, int k) {
  int idx = partition(nums, begin, end);
  if (k == end - idx + 1)  return nums[idx];
  if (k < end - idx + 1)  return findKthLargestUtil(nums, idx + 1, end, k);
  return findKthLargestUtil(nums, begin, idx - 1, k - (end - idx + 1));
}

int Solution::partition(vector<int>& nums, int begin, int end) {
  if (begin == end)  return begin;
  int pivot = nums[end];
  int i = begin, j = end - 1;
  while (i <= j) {
    while (i <= j && nums[i] <= pivot)  ++i;
    while (i <= j && nums[j] >= pivot)  --j;
    if (i < j)  swap(nums[i++], nums[j--]);
  }
  swap(nums[i], nums[end]);
  return i;
}

int Solution::findKthLargest(vector<int>& nums, int k) {
  // Method 1: Using max heap - O(n + k log n) time and O(n) space.
  /*capacity = nums.size();
  heap = new int[capacity];
  heapSize = 0;
  for (int i = 0; i < nums.size(); i++)  insertKey(nums[i]);
  int out = INT_MIN;
  for (int i = 0; i < k; i++)  out = extractMax();
  return out;*/
  
  // Method 2: Using sorting - O(n log n) time.
  /*sort(nums.begin(), nums.end());
  int out = 0;
  for (int i = 0, j = nums.size() - 1; i < k && j >= 0; i++, j--)  out = nums[j];
  return out;*/

  /* Method 3: Using quickselect - O(n) average time and O(n^2) worst-case time.
   * Worst-case time occurs when picking a corner element as the pivot.
   * An alternative is to perform a randomized quickselect where the pivot is 
   * picked randomly. But even this method can pick a corner element as pivot.
   * However, we assume that the random number generator is equally likely to 
   * generate any number in the input range.
   */
  if (nums.empty())  return INT_MIN;
  return findKthLargestUtil(nums, 0, nums.size() - 1, k);
}
