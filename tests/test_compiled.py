from __future__ import annotations

from pytest import approx

from se_for_sci_hw6 import HarmonicOscillator


def test_simple():
    a = HarmonicOscillator().integrate(0.01, 1000, (1, 0))

    assert a.shape == (1000, 2)
    assert a[0] == approx([1, 0])
    assert a[-1] == approx([-0.88790741, 0.56273912])
