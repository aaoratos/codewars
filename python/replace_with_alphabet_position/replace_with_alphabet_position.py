import string


def alphabet_position(text: str) -> str:
    alpha_pos = dict(zip(string.ascii_lowercase, range(1, 27)))
    new_text = list(filter(lambda x: x.isalpha(), text.lower()))
    new_text = list(map(lambda x: str(alpha_pos[x]), new_text))
    ' '.join(new_text)
