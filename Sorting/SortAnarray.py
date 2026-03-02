class Solution:
    def sortArray(self, nums):
        
        def merge(arr, low, mid, high):
            temp = []
            i = low
            j = mid + 1

            while i <= mid and j <= high:
                if arr[i] <= arr[j]:
                    temp.append(arr[i])
                    i += 1
                else:
                    temp.append(arr[j])
                    j += 1

            while i <= mid:
                temp.append(arr[i])
                i += 1

            while j <= high:
                temp.append(arr[j])
                j += 1

            for k in range(len(temp)):
                arr[low + k] = temp[k]


        def splitAndMerge(arr, low, high):
            if low >= high:
                return

            mid = (low + high) // 2

            splitAndMerge(arr, low, mid)
            splitAndMerge(arr, mid + 1, high)

            merge(arr, low, mid, high)


        splitAndMerge(nums, 0, len(nums) - 1)
        return nums