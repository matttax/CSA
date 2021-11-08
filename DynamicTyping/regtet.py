# triangle.ру содержит функции обработки правильного тэтраэдра
from random import randrange
from shape import *
from math import sqrt

class regtet(shape):
    # Инициализация правильного тэтраэдра
    def __init__(self):
        self.edge = 0

    # Рандомная генерация правильного тэтраэдра
    def in_rand(self):
        self.edge = randrange(50) + 1
        pass

    # Чтение правильного тэтраэдра из файла
    def read_string_arr(self, str_arr, i):
        if i >= len(str_arr):
            return 0
        self.edge = int(str_arr[i])
        i += 1
        return i

    # Вывод правильного тэтраэдра в консоль
    def print(self):
        print("Regular tetrahedron: edge = ", self.edge, ". Surface square = ", self.surf_sq())
        pass

    # Вывод правильного тэтраэдра в поток (для записи в файл)
    def write(self, ostream):
        ostream.write("Regular tetrahedron: edge = {}. Surface square = {}".format(self.edge, self.surf_sq()))
        pass

    # Поиск площади поверхности правильного тэтраэдра
    def surf_sq(self):
        return float((self.edge ** 2) * sqrt(3))
        pass
