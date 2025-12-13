def generate_gray_code(n):
    result = []
    for i in range(1 << n):  #
        gray_code = i ^ (i >> 1)
        result.append(f"{gray_code:0{n}b}")
    return result

n = int(input())

gray_codes = generate_gray_code(n)
for code in gray_codes:
    print(code)
