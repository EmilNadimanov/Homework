carry = 0
while (n > 0)
    C[n + 1] = (A[n] + B[n] + carry) % 2
    if A[n] + B[n] + carry < 2
        carry = 0
    else
        carry = 1
    n--
C[n] = carry