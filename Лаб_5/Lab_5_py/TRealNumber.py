from TNumber import *

class TRealNumber(TNumber):
    def __init__(self, integral, fraction):
        self.__integral = integral
        self.__fraction = fraction

    def get_first_digit(self):
        temp_num = abs(self.__integral)
        while temp_num >= 10:
            temp_num //= 10

        return temp_num

    def get_last_digit(self):
        return self.__fraction % 10

    def get_digits_sum(self):
        digits_sum = 0
        # Sum for integer part of number
        temp_num = abs(self.__integral())

        while temp_num:
            digits_sum += temp_num % 10
            temp_num //= 10

        #Sum fo fractional part of number
        temp_num = self.__fraction()

        while temp_num:
            digits_sum += temp_num % 10
            temp_num //= 10

        return digits_sum
