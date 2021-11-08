# sphere.ру содержит описание шара
from random import randrange
from shape import *
from math import pi

class sphere(shape):
    # Инициализация шара
    def __init__(self):
        self.r = 0

    # Рандомная генерация шара
    def in_rand(self):
        self.r = randrange(50) + 1
        pass

    # Чтение шара из файла
    def read_string_arr(self, str_arr, i):
        if i >= len(str_arr):
            return 0
        self.r = int(str_arr[i])
        i += 1
        return i

    # Вывод шара в консоль
    def print(self):
        print("Sphere: r = ", self.r, ". Surface square = ", self.surf_sq())
        pass

    # Вывод шара в поток (для записи в файл)
    def write(self, ostream):
        ostream.write("Sphere: r = {}. Surface square = {}".format(self.r, self.surf_sq()))
        pass

    # Поиск площади поверхности шара
    def surf_sq(self):
        return float((self.r ** 2) * pi * 4)
        pass
