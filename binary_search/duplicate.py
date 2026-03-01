class Solution:
    def findDuplicate(self, nums: list[int]) -> int:
        l = 1
        r = len(nums) - 1   # n

        while l < r:
            mid = (l + r) // 2

            # hum vahi count++ kiye jo mid aur mid ke equal hai
            count = 0
            for num in nums:
                if num <= mid:
                    count += 1

            if count > mid:
                r = mid
            else:
                l = mid + 1

        return l
    
    # another method
    
        # nums.sort()
        # for i in range(len(nums) - 1):
        #     if(nums[i] == nums[i + 1]):
        #         return nums[i]


def main():
    nums = [1, 3, 4, 2, 2]   # test case
    sol = Solution()
    ans = sol.findDuplicate(nums)
    print("Duplicate number is:", ans)


if __name__ == "__main__":
    main()
