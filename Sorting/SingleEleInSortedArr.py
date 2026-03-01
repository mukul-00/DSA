# BRUTE FORCE
# arr = [1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6]

# def singleElement(arr):
#     n = len(arr)

#     if(n == 1):
#         return arr[0]

#     for i in range(n):

#         # first position
#         if i == 0:
#             if arr[i] != arr[i + 1]:
#                 return arr[i]

#         # last position
#         elif i == n - 1:
#             if arr[i] != arr[i - 1]:
#                 return arr[i]

#         # middle elements
#         else:
#             if arr[i] != arr[i + 1] and arr[i] != arr[i - 1]:
#                 return arr[i]

#     return -1  # if no single element found

# ans = singleElement(arr)
# print(ans) 

# OPTIMIZED (Binary search)
class Solution:
    def singleNonDuplicate(self, nums: list[int]) -> int:
        n = len(nums)
        low = 1
        high = n - 2

        #if size of nums is 1 that mean its only element 
        if(n == 1):
            return nums[0]

        #check condition for fist position
        if(nums[0] != nums[1]):
            return nums[0]

        #check condition for 2nd position
        if(nums[n - 1] != nums[n - 2]):
            return nums[n - 1]

        #binary search
        while(low <= high):
            mid = (low + high) // 2

            # agr mid ke agli bali same nhi hai toh vahi hai single non duplicate element
            if(nums[mid] != nums[mid + 1] and nums[mid] != nums[mid - 1]):
                return nums[mid]

            # to eliminate left half (even, odd)
            if(mid % 2 == 1 and nums[mid] == nums[mid - 1]
               or mid % 2 == 0 and nums[mid] == nums[mid + 1]):
               low = mid + 1 #eliminate the left search(half)

            # to eliminate right half (odd, even)
            else:
                high = mid - 1
        
        return -1


# 🔹 main
if __name__ == "__main__":
    nums = [1,1,2,2,3,3,4,5,5,6,6]

    obj = Solution()
    ans = obj.singleNonDuplicate(nums)

    print(ans)


