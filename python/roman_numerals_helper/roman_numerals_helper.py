class RomanNumerals:
    numerals_ = {
        'M': 1000, 'CM': 900, 'D': 500,
        'CD': 400, 'C': 100, 'XC': 90,
        'L': 50, 'XL': 40, 'X': 10,
        'IX': 9, 'V': 5, 'IV': 4, 'I': 1
    }

    @staticmethod
    def to_roman(cls, val: int) -> str:
        result = ''
        for roman, arab in cls.numerals_.items():
            result += roman * (val // arab)
            val %= arab
        return result

    @staticmethod
    def from_roman(cls, roman: str) -> int:
        result = 0
        for i in range(len(roman)):
            try:
                if cls.numerals_[roman[i]] < cls.numerals_[roman[i + 1]]:
                    result -= cls.numerals_[roman[i]]
                else:
                    result += cls.numerals_[roman[i]]
            except (IndexError, KeyError):
                result += cls.numerals_[roman[i]]
        return result
