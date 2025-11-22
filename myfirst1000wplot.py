# %%
import matplotlib.pyplot as plt

# -------------------------------------------------
# CF logic: count number of integer intersection points
# -------------------------------------------------
def count_integer_points(P, Q):
    po = sum(1 for x in P if x % 2 != 0)
    pe = len(P) - po
    qo = sum(1 for x in Q if x % 2 != 0)
    qe = len(Q) - qo

    return po * qo + pe * qe


# -------------------------------------------------
# Compute actual intersection points
# Each P gives line  y =  x + P
# Each Q gives line  y = -x + Q
#
# Intersection:
#   x = (Q - P) / 2
#   y = x + P
# But we only keep integer (x, y)
# -------------------------------------------------
def compute_integer_points(P, Q):
    points = []

    for p in P:
        for q in Q:
            if (q - p) % 2 == 0:
                x = (q - p) // 2
                y = x + p
                points.append((x, y))

    return points


# -------------------------------------------------
# Plot the lines + integer intersection points
# -------------------------------------------------
def plot_lines_and_points(P, Q, points):

    # pick a sane plotting range
    all_vals = P + Q
    mn = min(all_vals) - 10
    mx = max(all_vals) + 10

    X = range(mn, mx + 1)

    # Plot lines y = x + p
    for p in P:
        Y = [x + p for x in X]
        plt.plot(X, Y, linewidth=0.8)

    # Plot lines y = -x + q
    for q in Q:
        Y = [-x + q for x in X]
        plt.plot(X, Y, linewidth=0.8)

    # Plot integer intersection points
    if points:
        px = [x for x, y in points]
        py = [y for x, y in points]
        plt.scatter(px, py, s=20, marker="o")

    plt.title("Lines and Integer Intersection Points")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.grid(True)
    plt.show()


# -------------------------------------------------
# Main
# -------------------------------------------------
t = int(input())
while t > 0:
    t -= 1

    n = int(input())
    P = list(map(int, input().split()))

    m = int(input())
    Q = list(map(int, input().split()))

    ans = count_integer_points(P, Q)
    print(ans)

    # generate integer points (for graph)
    pts = compute_integer_points(P, Q)

    # Show graph
    plot_lines_and_points(P, Q, pts)
