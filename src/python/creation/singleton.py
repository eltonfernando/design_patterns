# -*- coding: utf-8 -*-
class Singleton(type):
    _instances = {}

    def __call__(cls, *args, **kwargs):
        if cls not in cls._instances:
            cls._instances[cls] = super(Singleton, cls).__call__(*args, **kwargs)
        return cls._instances[cls]


class SingletonClass(metaclass=Singleton):
    def __init__(self, name: str):
        self.name = name


if __name__ == "__main__":
    a = SingletonClass("a")
    b = SingletonClass("b")
    print(a.name, b.name)
    print(id(a), id(b))
