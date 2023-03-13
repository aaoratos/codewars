def move_zeros(array):
    result = [x for x in array if x != 0]
    result.extend([0] * (len(array) - len(result)))
    return result
