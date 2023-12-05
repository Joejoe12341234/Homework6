from __future__ import annotations

import numpy.typing


class HarmonicOscillator:
    def integrate(
        self, stepsize: float, steps: int, init_y: tuple[float, float]
    ) -> numpy.typing.NDArray[numpy.float64]:
        ...
