#! /usr/bin/python
# coding:utf-8

# this mac use the python27 so should use the future module 
from __future__ import print_function


# Somme python cookbook case

record = ("hello", "world", "leemaster", (123, 456, 789))

# unpack the tuple could use this method
hello, world, name, arr = record

def solve_last_n_items():
    """
    use the namespace to specific the enviroment of the import 
    """
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

def finding_nxest_object_inset():
    """
    finding the N est object or number in some set 
    """
    import heapq
    portfolio = [
       {'name': 'IBM', 'shares': 100, 'price': 91.1},
       {'name': 'AAPL', 'shares': 50, 'price': 543.22},
       {'name': 'FB', 'shares': 200, 'price': 21.09},
       {'name': 'HPQ', 'shares': 35, 'price': 31.75},
       {'name': 'YHOO', 'shares': 45, 'price': 16.35},
       {'name': 'ACME', 'shares': 75, 'price': 115.65}
    ]
    # the lambda keword will use the yield partten to generate the key in evert interation 
    heapq.nsmallest(3, portfolio, key=lambda s : s['price'])

def implement_priority_queue():
    import heapq

    class PriorityQueue():

        def __init__(self):
            self.queue = []
            self._index = 0

        def push(self, item, priority):
            heapq.heappush(self.queue, (-priority, self._index,item))
            self._index += 1
        
        def pop(self):
            heapq.heappop(self.queue)[-1]
