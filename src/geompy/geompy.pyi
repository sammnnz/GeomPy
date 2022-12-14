from __future__ import annotations
from typing import Any, Generator, Optional, overload, Sequence, Tuple, Type, TYPE_CHECKING, Union
from _typing import RealNumber

Point2D = Union["point", Tuple["RealNumber", "RealNumber"]]
Points = Union["point", Sequence["point"]]

# noinspection SpellCheckingInspection
def generate_random_polygon(center: Point2D, radius: RealNumber = ..., verts_num: int = ...) -> polygon: ...

class polygon(object):
    # noinspection PyShadowingNames
    def is_inner_point(self, point: Point2D) -> bool: ...
    def __getitem__(self, index: int) -> Point2D: ...
    def __init__(self, *args: Point2D) -> None: ...
    @staticmethod
    def __new__(cls: Type[polygon], *args: Point2D, **kwargs: Any) -> polygon: ...
    # noinspection SpellCheckingInspection
    verts: Tuple[Point2D, ...] = ...

# https://github.com/python/typeshed/issues/7855#issuecomment-1128857842
if TYPE_CHECKING:
    _Tuple = Tuple[RealNumber]
else:
    _Tuple = Tuple

class point(_Tuple):
    @overload
    def __new__(cls: Type[point], x: RealNumber) -> point: ...
    @overload
    def __new__(cls: Type[point], x: RealNumber, y: RealNumber) -> point: ...
    @overload
    def __new__(cls: Type[point], x: RealNumber, y: RealNumber, z:RealNumber) -> point: ...
    @overload
    def __new__(cls: Type[point], *args: RealNumber) -> point: ...

class Render(object):
    # TODO: write annotations for `ax` и `fig`
    ax: Any
    fig: Any
    def __init__(self) -> None: ...
    def display(self, x: Optional[RealNumber] = ..., y: Optional[RealNumber] = ..., block: bool = ...) -> None: ...
    def points(self, p: Points, c: str = ..., s: Union[RealNumber, Sequence[RealNumber]] = ...) -> None: ...
    def polygon(self, p: polygon, c: str = ...) -> None: ...

# TODO: check annotation (return value)
def random_points(count: int, radius: RealNumber, x: RealNumber, y: RealNumber) -> Generator[point, Any, None]: ...