from PIL import Image, ImageDraw
from typing import Tuple, List
from math import floor, ceil, sqrt


Color = Tuple[int, int, int]

CELL_WIDTH = 50
CELL_HEIGHT = 50

def decompose(n: int) -> Tuple[int, int]:

    for div in range(int(sqrt(n)) + 1, 0, -1):

        if n % div == 0:
            return (div, n // div)


def encrypt_one(char: str, triplet: str) -> Color:

    r = ord(char) + ord(triplet[0]) - 64
    g = ord(char) + ord(triplet[1]) - 64
    b = ord(char) + ord(triplet[2]) - 64

    return (r, g, b)


def get_triplet(key: str, i: int) -> str:

    res = ""

    for j in range(3):
        res += key[(i + j) % len(key)]

    return res


def encrypt(text: str, key: str) -> Image:
    
    w, h = decompose(len(text))
    im = Image.new("RGB", (w * CELL_WIDTH, h * CELL_HEIGHT))
    drawing_context = ImageDraw.Draw(im)

    i = 0

    # x * y == len(text)
    for x in range(w):
        for y in range(h):

            cell_color = encrypt_one(text[i], get_triplet(key, i))

            left_upper = (x * CELL_WIDTH, y * CELL_HEIGHT)
            right_lower = ((x + 1) * CELL_WIDTH, (y + 1) * CELL_HEIGHT)
            drawing_context.rectangle((left_upper, right_lower), fill = cell_color)

            i += 1

    return im



def de_encrypt_one(color: Color, triplet: str) -> str:

    val = color[0] - ord(triplet[0]) + 64

    if val > 126 or val < 32:
        return ""

    return chr(val)


def de_encrypt(encrypted: Image, key: str) -> str:

    w, h = encrypted.width // CELL_WIDTH, encrypted.height // CELL_HEIGHT

    i = 0
    res = ""
    for x in range(w):
        for y in range(h):

            cell_color = encrypted.getpixel((x * CELL_WIDTH, y * CELL_HEIGHT))
            res += de_encrypt_one(cell_color, get_triplet(key, i))

            i += 1

    return res
