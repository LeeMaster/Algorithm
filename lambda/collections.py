#! /usr/bin/python
# coding:utf-8


# Somme python cookbook case

record = ("hello", "world", "leemaster", (123, 456, 789))

# unpack the tuple could use this method
hello, world, name, arr = record

def solve_last_n_items():
    from collections import deque

    def search(lines,pattern,history=5):
        previous_lines = deque(maxlen=history)
        for line in lines:
            if pattern in line:
                yield line, previous_lines
            previous_lines.append(line)

    if __name__ == "__main__":
        with open("somefile.txt") as f:
            for line, prevlines in search(f, "python", 5):
                for pline in prevlines:
                    print (pline,end='')
                print(line,end='')
                print('-',*20)

