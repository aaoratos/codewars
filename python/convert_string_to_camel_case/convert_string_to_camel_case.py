def to_camel_case(text):
    if not text:
        return text
    s = text.replace('-', ' ').replace('_', ' ').split()
    return s[0] + ''.join([x.title() for x in s[1:]])
