def sum_pairs(ints, s):
    hash_table = {}
    for i in range(len(ints)):
        complement = s - ints[i]
        if complement in hash_table:
            return [complement, ints[i]]
        hash_table[ints[i]] = ints[i]
