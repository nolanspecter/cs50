from cs50 import get_int, get_string


def main():
    number = get_string("Number: ")
    length = len(number)
    number = int(number)
    sum1 = 0
    sum2 = 0
    first = number

    if length != 13 and length != 15 and length != 16:
        print("INVALID")
        return 0

    while number > 0:
        mod1 = number % 10
        number = number // 10
        sum1 += mod1

        mod2 = (number % 10) * 2
        number = number // 10
        digit1 = mod2 % 10
        digit2 = mod2 // 10
        sum2 = sum2 + digit1 + digit2

    check = sum1 + sum2

    if check % 10 != 0:
        print("INVALID")
        return 0

    while first > 100:
        first = first // 10

    if first // 10 == 4:
        print("VISA")
    elif first // 10 == 5 and (0 < first % 10 and first % 10 < 6):
        print("MASTERCARD")
    elif first // 10 == 3 and (first % 10 == 4 or first % 10 == 7):
        print("AMEX")
    else:
        print("INVALID")


main()