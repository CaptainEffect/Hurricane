import numpy as np
from PIL import Image
from IPython.display import display

# --------------------------------------------------
# Resolution
# --------------------------------------------------

WIDTH = 800
HEIGHT = 480

# --------------------------------------------------
# Coordinates
# --------------------------------------------------

x = np.linspace(-4, 4, WIDTH)
y = np.linspace(-2.4, 2.4, HEIGHT)

X, Y = np.meshgrid(x, y)

# --------------------------------------------------
# Functions inspired by your equations
# --------------------------------------------------

def R(s):
    return 0.9 + 0.3*np.cos(3*s*s)

def U(v, s):
    return (
        np.cos(4*s*s)*(X + v/5000)
        + np.sin(4*s*s)*(Y + v/10000)
        + 1.5*np.cos(7*s*s)
    )

def V(v, s):
    return (
        np.cos(4*s*s)*(Y + v/10000)
        - np.sin(4*s*s)*(X + v/5000)
        + 1.5*np.cos(2*s*s)
    )

def B(v, s):
    theta = np.arctan2(V(v, s), U(v, s))

    return np.exp(
        -2*np.abs(
            np.cos((12 + 2*(-1)**s)*theta)
        )
    )

def J(v, s):

    uu = U(v, s)
    vv = V(v, s)

    r = np.sqrt(uu**2 + vv**2)

    return np.exp(
        -20*np.abs(
            r - R(s)*(0.7 + 0.3*B(v, s))
        )
    )

def W(v, s):

    uu = U(v, s)
    vv = V(v, s)

    radial = uu**2 + vv**2

    return (
        np.sin(radial*(v+1))
        + np.cos(0.5*radial + s)
    )

def H(v):

    result = np.zeros_like(X)

    for s in range(1, 41):

        result += (
            J(v, s)
            * W(v, s)
        )

    result += 0.5*np.sin(3*X)
    result += 0.5*np.cos(3*Y)
    result += 0.3*np.sin(5*X*Y)

    return result

# --------------------------------------------------
# Stable color mapping
# --------------------------------------------------

def F(z):

    z = (z - z.min()) / (z.max() - z.min() + 1e-8)

    return (255*z).astype(np.uint8)

# --------------------------------------------------
# RGB
# --------------------------------------------------

RCH = F(H(0))
GCH = F(H(1))
BCH = F(H(2))

img = np.dstack([RCH, GCH, BCH])

Image.fromarray(img).save("equation_art.png")

print("saved")

display(Image.fromarray(img))
