def is_valid_walk(walk):
    direction_weights = {'n': 2, 's': -2, 'e': 1, 'w': -1}
    walk_checksum = 0
    for i in walk:
        walk_checksum += direction_weights[i]
    return walk_checksum == 0 and len(walk) == 10
