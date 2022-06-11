from abc import ABC, abstractmethod

class TNumber(ABC):
    @abstractmethod
    def get_last_digit(self):
        raise NotImplementedError

    @abstractmethod
    def get_first_digit(self):
        raise NotImplementedError

    @abstractmethod
    def get_digits_sum(self):
        raise NotImplementedError



