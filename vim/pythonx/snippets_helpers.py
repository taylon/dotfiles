import re
import inflect

p = inflect.engine()


def is_test_file(file_name: str):
    return re.match(".+[\._]{1}test[\._]{1}", file_name)


def singular_noun(noun: str):
    value = p.singular_noun(noun) if len(noun) > 0 else ""

    return value if value else ""
