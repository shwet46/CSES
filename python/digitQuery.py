pref = [0]
for i in range(18):
    pref.append((i + 1) * (9 * 10 ** (i)) + pref[-1])

for _ in range(int(input())):
    k = int(input())

    digits = 0
    for i, e in enumerate(pref):
        if e >= k:
            digits = i
            k -= pref[i - 1]
            break

    num, digit = divmod(k, digits)
    if digit == 0:
        digit = digits
    else:
        num += 1

    print(str(10 ** (digits - 1) + num - 1)[digit - 1])