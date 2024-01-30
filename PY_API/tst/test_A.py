import sys
from pyapi import A


def test_A_f():
    a = A.ca()
    assert a.f(3) == 4