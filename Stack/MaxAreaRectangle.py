def NSL(arr):
    left = []
    st = []  # stack of (index)

    for i in range(len(arr)):
        while len(st) > 0 and arr[st[-1]] >= arr[i]:
            st.pop()

        if len(st) == 0:
            left.append(-1)
        else:
            left.append(st[-1])

        st.append(i)

    return left


def NSR(arr):
    right = []
    st = []

    n = len(arr)

    for i in range(n - 1, -1, -1):
        while len(st) > 0 and arr[st[-1]] >= arr[i]:
            st.pop()

        if len(st) == 0:
            right.append(n)
        else:
            right.append(st[-1])

        st.append(i)

    right.reverse()
    return right


def getMaxArea(arr):
    left = NSL(arr)
    right = NSR(arr)

    max_area = 0

    for i in range(len(arr)):
        width = right[i] - left[i] - 1
        area = arr[i] * width
        max_area = max(max_area, area)

    return max_area

def maxAreaRectangle(arr):
    n = len(arr)
    m = len(arr[0])

    v = [0] * m   # start with all 0s
    max_area = 0

    for i in range(n):
        for j in range(m):
            if arr[i][j] == "0":
                v[j] = 0
            else:
                v[j] += 1

        max_area = max(max_area, getMaxArea(v))

    return max_area

    # n = len(arr)
    # m = len(arr[0])

    # v = []

    # # copy first row
    # for j in range(m):
    #     v.append(int(arr[0][j]))

    # max_area = getMaxArea(v)

    # # process remaining rows
    # for i in range(1, n):
    #     for j in range(m):
    #         if arr[i][j] == "0":
    #             v[j] = 0
    #         else:
    #             v[j] += 1

    #     max_area = max(max_area, getMaxArea(v))

    # print(max_area)



# main function
if __name__ == "__main__":

    arr = [["1","0","1","0","0"],
           ["1","0","1","1","1"],
           ["1","1","1","1","1"],
           ["1","0","0","1","0"]]

    result = maxAreaRectangle(arr)
    print(result)