#!/usr/bin/python3
"""  Log Parsing Script """


import sys

counter = 0
sizes = 0

status_code_counter = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}


def print_dict(dicti):
    """ print a dictionary """
    for i, j in dicti.items():
        if j > 0:
            print("{}: {}".format(i, j))j

try:
    for line in sys.stdin:
        counter += 1

        input_format_list = line.split(" ")

        if len(input_format_list) > 2:
            if input_format_list[-2] in status_code_counter:
                status_code_counter[input_format_list[-2]] += 1
            sizes += int(input_format_list[-1])

            if counter == 10:
                print("File size:", sizes)
                print_dict(status_code_counter)
                counter = 0
finally:
    print("File size:", sizes)
    print_dict(status_code_counter)
