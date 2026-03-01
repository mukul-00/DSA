# def pow(x: float, n: int)-> float:
#     ans = 1.0

#     # for negative powers 
#     if(n < 0):
#         x = 1 / x
#         n = -n

#     while(n > 0):

#         #if n is odd then make it like this x * x^(n-1)
#         if(n % 2 == 1):
#             ans = ans * x
#             n = n - 1

#         #n is even then make it x^n = (x^2)^(n/2)
#         else:
#             x = x*x
#             n = n//2
    
#     return ans

# def main():
#     print(pow(2, 3))
#     print(pow(2, -2))   


# main()


#-----------use recursion----------------
def pow(x: float, n: int)-> float:

    #base case
    if(n==0):
        return 1.0;

    #recursive call
    half = pow(x, n//2)

    #processing
    if(n % 2 == 0):
        return half * half
    else:
        return x * half * half
    

def main():
    print(pow(2, 5))


main()