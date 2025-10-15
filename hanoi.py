# Recursive Python function to solve tower of hanoi


def TH(n, from_rod, to_rod, aux_rod):
    if n == 0:
        return
    TH(n-1, from_rod, aux_rod, to_rod)
    print("Move disk", n, "from rod", from_rod, "to rod", to_rod)
    TH(n-1, aux_rod, to_rod, from_rod)


# Driver code
N = 3

# A, C, B are the name of rods
TH(N, 'A', 'C', 'B')