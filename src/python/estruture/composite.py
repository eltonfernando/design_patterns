# -*- coding: utf-8 -*-
from abc import ABC, abstractmethod
from typing import List

# Componente base
class FileSystemItem(ABC):
    @abstractmethod
    def show(self, indent=0):
        pass


# Folha
class File(FileSystemItem):
    def __init__(self, name: str):
        self.name = name

    def show(self, indent=0):
        print("  " * indent + f"- {self.name}")


# Composite
class Folder(FileSystemItem):
    def __init__(self, name: str):
        self.name = name
        self.children: List[FileSystemItem] = []

    def add(self, item: FileSystemItem):
        self.children.append(item)

    def show(self, indent=0):
        print("  " * indent + f"[Folder] {self.name}")
        for child in self.children:
            child.show(indent + 1)


# Exemplo de uso
root = Folder("root")
root.add(File("arquivo1.txt"))
root.add(File("arquivo2.txt"))

subfolder = Folder("imagens")
subfolder.add(File("foto1.jpg"))
subfolder.add(File("foto2.jpg"))

root.add(subfolder)

root.show()
