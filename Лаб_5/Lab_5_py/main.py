from TIntNumber import TIntNumber
from TRealNumber import TRealNumber
import random


def get_first_dgt_sum(number_lst):
    sum = 0
    for num in number_lst:
        sum += num.get_first_digit()

    return sum

def get_last_dgt_sum(number_lst):
    sum = 0
    for num in number_lst:
        sum += num.get_last_digit()

    return  sum


def run():
    n = int(input('Enter n: '))
    m = int(input('Enter m: '))

    LOWER_BOUND = -1000
    UPPER_BOUND = 1000

    TIntNumber_list = [TIntNumber(random.randrange(LOWER_BOUND, UPPER_BOUND)) for _ in range(m)]
    TRealNumber_list = [TRealNumber(random.randrange(LOWER_BOUND, UPPER_BOUND), random.randrange(UPPER_BOUND)) for _ in range(n)]

    first_dgt_sum = get_first_dgt_sum(TIntNumber_list)
    last_dgt_sum = get_last_dgt_sum(TRealNumber_list)

    print('First digits sum of integer numbers:', first_dgt_sum)
    print('Last digits sum of real numbers:', last_dgt_sum)

if __name__ == '__main__':
    run()
