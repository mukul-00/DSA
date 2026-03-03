#-------------BETTER SOLUTION-----------------------------

# nums = [1, 2, 0, 2, 1, 0, 0, 1]

# cnt0 = 0
# cnt1 = 0
# cnt2 = 0

# # Count 0s, 1s, 2s
# for i in range(len(nums)):
#     if nums[i] == 0:
#         cnt0 += 1
#     elif nums[i] == 1:
#         cnt1 += 1
#     else:
#         cnt2 += 1

# # Fill 0s
# for i in range(cnt0):
#     nums[i] = 0

# # Fill 1s
# for i in range(cnt0, cnt0 + cnt1):
#     nums[i] = 1

# # Fill 2s
# for i in range(cnt0 + cnt1, cnt0 + cnt1 + cnt2):
#     nums[i] = 2

# print(nums)

    
#-----------------OPTIMAL SOLUTION-------------------------
nums = [1, 2, 0, 2, 1, 0, 0, 1]

low = 0
mid = 0
high = len(nums) - 1

while (mid <= high):
    if(nums[mid] == 0):
        nums[low], nums[mid] = nums[mid], nums[low]
        low += 1
        mid += 1

    elif(nums[mid] == 1):
        mid += 1

    else:
        nums[mid], nums[high] = nums[high], nums[mid]
        high -= 1
print(nums)

#https://youtu.be/tp8JIuCXBaU?si=iqXyFgTjQy_JVtHF