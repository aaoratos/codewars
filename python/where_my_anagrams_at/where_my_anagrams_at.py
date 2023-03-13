def anagrams(word, words):
    result = []
    for w in words:
        if set(list(word)) == set(list(w)) and len(word) == len(w):
            result.append(w)
    return result
