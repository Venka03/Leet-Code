import math
    


expression = "-1/2+1/2"

addition = True
numerator = 0
denominator = 1
result_numerator = 0
result_denominator = 1
last_operation = 0

for i in range(len(expression)):
    if expression[i] == '-':
        if not expression[last_operation:i]:
            denominator = 1
        else:
            denominator = int(expression[last_operation:i])
        result_numerator = result_numerator * denominator - (-1)**addition * result_denominator * numerator
        result_denominator *= denominator
        gcd = math.gcd(result_denominator, result_numerator)
        result_numerator //= gcd
        result_denominator //= gcd
        last_operation = i+1
    elif expression[i] == '/':
        numerator = int(expression[last_operation:i])
        last_operation = i+1
        addition = False
        
    elif expression[i] == '+':
        if not expression[last_operation:i]:
            denominator = 1
        else:
            denominator = int(expression[last_operation:i])
        result_numerator = result_numerator * denominator - (-1)**addition * result_denominator * numerator
        result_denominator *= denominator
        gcd = math.gcd(result_denominator, result_numerator)
        result_numerator //= gcd
        result_denominator //= gcd
        last_operation = i+1
        addition = True

result_numerator = result_numerator * denominator - (-1)**addition * result_denominator * numerator
result_denominator *= denominator
gcd = math.gcd(result_denominator, result_numerator)
result_numerator //= gcd
result_denominator //= gcd
last_operation = i+1


print(f"{result_numerator}/{result_denominator}")