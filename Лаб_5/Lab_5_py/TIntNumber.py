from TNumber import *

class TIntNumber(TNumber):
    def __init__(self, integral):
        self.__interal = integral

    def get_digits_sum(self):
        digits_sum = 0
        temp_num = abs(self.__interal)
        while temp_num:
            digits_sum += temp_num % 10
            temp_num //= 10

        return digits_sum

    def get_last_digit(self):
        return self.__interal % 10

    def get_first_digit(self):
        temp_num = abs(self.__interal)

        while temp_num >= 10:
            temp_num //= 10

        return temp_num