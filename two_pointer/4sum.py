def fourSum(nums, target):
    nums.sort()
    n = len(nums)
    ans = []

    for i in range(n):
        # skip duplicates for i
        if i > 0 and nums[i] == nums[i - 1]:
            continue

        for j in range(i + 1, n):
            # skip duplicates for j
            if j > i + 1 and nums[j] == nums[j - 1]:
                continue

            p = j + 1
            q = n - 1

            while p < q:
                sum = nums[i] + nums[j] + nums[p] + nums[q]

                if sum < target:
                    p += 1
                elif sum > target:
                    q -= 1
                else:
                    ans.append([nums[i], nums[j], nums[p], nums[q]])
                    p += 1
                    q -= 1

                    # skip duplicates for p
                    while p < q and nums[p] == nums[p - 1]:
                        p += 1

                    # skip duplicates for q
                    while p < q and nums[q] == nums[q + 1]:
                        q -= 1

    return ans


# 🔹 Main function
if __name__ == "__main__":
    nums = list(map(int, input("Enter numbers: ").split()))
    target = int(input("Enter target: "))

    result = fourSum(nums, target)

    print("Quadruplets:")
    for quad in result:
        print(quad)