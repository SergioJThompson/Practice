def encode(text):
    return insert_spaces(encode_without_spaces(text))


def decode(text):
    return encode_without_spaces(text)


def encode_without_spaces(text):
    encoded = ""
    for ch in text:
        if ch.isalpha():
            ch = encode_char(ch.lower())
        if ch.isalnum():
            encoded += ch
    return encoded


def encode_char(ch):
    return chr(122 - (ord(ch) - 97))


def insert_spaces(s):
    idx = 5
    while idx < len(s):
        s = s[:idx] + " " + s[idx:]
        idx += 6
    return s
