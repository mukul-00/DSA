        
def addBinary(a: str, b: str) -> str:
    ans = ""
    carry = 0

    a, b = a[::-1], b[::-1]  # reverse strings

    for i in range(max(len(a), len(b))):

        if i < len(a):
            digit1 = ord(a[i]) - ord('0') #convert char -> int
        else:
            digit1 = 0

        if i < len(b):
            digit2 = ord(b[i]) - ord('0')
        else:
            digit2 = 0

        total = digit1 + digit2 + carry

        value = str(total % 2) # 1 + 1 = 2 (2 % 2 -> value = 0)
        ans = value + ans

        carry = total // 2 # 1 + 1 = 2 (2 / 2 -> carry = 1)

    if carry == 1:
        ans = "1" + ans

    return ans


def main():
    a = "11"
    b = "01"

    res = addBinary(a, b)
    print(res)

if __name__ == "__main__":
    main()



# ------- shorter method ----------------
# def addBinary(a: str, b: str) -> str:
#     ans = ""
#     carry = 0

#     a, b = a[::-1], b[::-1]  # reverse to process from LSB

#     for i in range(max(len(a), len(b))):
#         digit1 = int(a[i]) if i < len(a) else 0
#         digit2 = int(b[i]) if i < len(b) else 0

#         total = digit1 + digit2 + carry

#         ans = str(total % 2) + ans   # current bit
#         carry = total // 2           # carry

#     if carry:
#         ans = "1" + ans              # leftover carry

#     return ans

# def main():
#     a = "11"
#     b = "01"

#     res = addBinary(a, b)
#     print(res)
    
# if __name__ == "__main__":
#     main()