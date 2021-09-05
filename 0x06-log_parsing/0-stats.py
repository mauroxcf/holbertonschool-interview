#!/usr/bin/python3
'''Log Parsing'''
import sys


def print_stats(total_size, codes_count):
    '''print the stats of the parser
    Args:
        total_size is the acumulated size of the files parsed
        codes_count is a dict with the count for each code
    return: nothing
    '''
    print("File size: {:d}".format(total_size))
    for k, v in sorted(codes_count.items()):
        print("{}: {}".format(k, v))


count = 0
total_size = 0
status_codes = ["200", "301", "400", "401", "403", "404", "405", "500"]
codes_count = {}
val_str = "GET /projects/260 HTTP/1.1"
try:
    for line in sys.stdin:
        if val_str in line:
            split = line.split(' ')
            if len(split) < 4:
                continue
            try:
                total_size += int(split[-1])
            except Exception:
                continue
            code = split[-2]
            if code in status_codes:
                if code in codes_count.keys():
                    codes_count[code] += 1
                else:
                    codes_count[code] = 1
        count += 1
        if count % 10 == 0:
            print_stats(total_size, codes_count)
    else:
        print_stats(total_size, codes_count)
except KeyboardInterrupt:
    print_stats(total_size, codes_count)
