from cs50 import get_string


def main():
    text = get_string("Text: ")
    word_count = 1
    sentence_count = 0
    char_count = 0
    for c in text:
        if c.isalpha():
            char_count += 1
        elif c == " ":
            word_count += 1
        elif c == "!" or c == "?" or c == ".":
            sentence_count += 1

    l = (char_count / word_count) * 100
    s = (sentence_count / word_count) * 100
    level = compute_score(l, s)

    if level < 1:
        print("Before Grade 1")
    elif level > 16:
        print("Grade 16+")
    else:
        print("Grade " + str(level))


def compute_score(L, S):
    return round(0.0588 * L - 0.296 * S - 15.8)


main()