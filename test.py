import math
    


expression = "1/3-1/2"

addition = True
numerator = 0
denominator = 1
result_numerator = 0
result_denominator = 1
last_operation = 0

for i in range(len(expression)):
    if expression[i] == '-':
        addition = False
        last_operation = i+1
    elif expression[i] == '/':
        numerator = int(expression[last_operation:i])
        tmp = expression[i+1:]
        k = tmp.find('-')
        l = tmp.find('+')
        if k == -1 and l == -1:
            denominator = int(expression[i+1:])
        elif k == -1:
            denominator = int(expression[i+1:i+l+1])
        elif l == -1:
            denominator = int(expression[i+1:i+k+1])
        else:
            denominator = int(expression[i+1:min(k, l)+i+1])
        result_numerator = result_numerator * denominator - (-1)**addition * result_denominator * numerator
        result_denominator *= denominator
        gcd = math.gcd(result_denominator, result_numerator)
        result_numerator //= gcd
        result_denominator //= gcd
    elif expression[i] == '+':
        addition = True
        last_operation = i+1
print(f"{result_numerator}/{result_denominator}")