# parallelepiped.ру - содержит описание параллелепипеда
from random import randrange
from shape import *

class parallelepiped(shape):
    # Инициализация параллелепипеда
    def __init__(self):
        self.a = 0
        self.b = 0
        self.c = 0

    # Рандомная генерация параллелепипеда
    def in_rand(self):
        self.a = randrange(50) + 1
        self.b = randrange(50) + 1
        self.c = randrange(50) + 1
        pass

    # Чтение параллелепипеда из файла
    def read_string_arr(self, str_arr, i):
        if i >= len(str_arr) - 2:
            return 0
        self.a = int(str_arr[i])
        self.b = int(str_arr[i+1])
        self.c = int(str_arr[i+2])
        i += 3
        return i

    # Вывод параллелепипеда в консоль
    def print(self):
        print("Parallelepiped: a = ", self.a, ", b = ", self.b, ", c = ", self.c, ". Surface square = ", self.surf_sq())
        pass

    # Вывод параллелепипеда в поток (для записи в файл)
    def write(self, ostream):
        ostream.write("Parallelepiped: a = {}, b = {}, c = {}. Surface square = {}".
                      format(self.a, self.b, self.c, self.surf_sq()))
        pass

    # Поиск площади поверхности параллелепипеда
    def surf_sq(self):
        return float(2 * (self.a * self.b + self.b * self.c + self.c * self.a))
        pass
