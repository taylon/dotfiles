import re

def is_test_file(file_name: str):
    return re.match('.+[\._]{1}test[\._]{1}', file_name)
