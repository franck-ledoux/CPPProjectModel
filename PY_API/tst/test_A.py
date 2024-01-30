import sys
from pyapi import *


def test_A_f():
    a = A()
    assert a.f(3) == 4