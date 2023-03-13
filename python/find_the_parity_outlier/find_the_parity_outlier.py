def find_outlier(integers=[2, 4, 6, 8, 10, 3]):
    evens = [x for x in integers if x % 2 == 0]
    odds = [x for x in integers if x % 2 != 0]
    return evens[0] if len(evens) < len(odds) else odds[0]
