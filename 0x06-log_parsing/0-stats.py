#!/usr/bin/python3
""" Log parsing Project """
import sys


r = 1
t_size = 0
errors = {"200": 0, "301": 0, "400": 0, "401": 0,
          "403": 0, "404": 0, "405": 0, "500": 0}

try:
    for i in sys.stdin:
        l = i.split(" ")
        if len(l) >= 2:
            size = int(l[-1].replace("\n", ""))
            t_size += size
            if l[-2] in errors:
                errors[l[-2]] += 1
            if r % 10 == 0:
                print("File size: {}".format(t_size))
                for m in sorted(errors.keys()):
                    if errors[m] != 0:
                        print("{}: {}".format(m, errors[m]))
            r += 1
except AssertionError as error:
    pass
finally:
    print("File size: {}".format(t_size))
    for j in sorted(errors.keys()):
        if errors[m] != 0:
            print("{}: {}".format(m, errors[m]))

