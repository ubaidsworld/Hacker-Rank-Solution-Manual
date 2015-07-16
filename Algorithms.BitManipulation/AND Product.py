def compute( l,  r):
    x = l ^ r
    x |= (x >> 1)
    x |= (x >> 2)
    x |= (x >> 4)
    x |= (x >> 8)
    x |= (x >> 16)
    return l & ~x;

case_num = int(raw_input())
for _ in xrange(case_num):
    ls = map(lambda x : int(x), raw_input().strip().split(' '))
    l = ls[0]
    r = ls[1]
    print compute(l, r);
