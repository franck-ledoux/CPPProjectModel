import sys
from pyapi import B


def test_B_g():
    b = B.cb()
    assert b.g(3) == True

def test_B_g2():
    b = B.cb()
    assert b.g(-1) == False