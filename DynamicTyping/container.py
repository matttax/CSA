# container.ру контейнер для фигур
from random import randrange
from parallelepiped import parallelepiped
from regtet import regtet
from sphere import sphere


class container:
    # Контейнер на основе одномерного массива
    def __init__(self):
        self.store = []

    # Ввод содержимого контейнера из массива
    def read_string_arr(self, str_arr):
        i = 0  # Индекс, задающий текущую строку в массиве
        figNum = 0
        while i < len(str_arr):
            str = str_arr[i]
            print(str)
            key = int(str)
            if key == 1:
                i += 1
                shape = sphere()
                i = shape.read_string_arr(str_arr, i)
            elif key == 2:
                i += 1
                shape = parallelepiped()
                i = shape.read_string_arr(str_arr, i)
            elif key == 3:
                i += 1
                shape = regtet()
                i = shape.read_string_arr(str_arr, i)
            else:
                return figNum
            if i == 0:
                return figNum
            figNum += 1
            self.store.append(shape)
        return figNum

    # Случайный ввод содержимого контейнера
    def in_rand(self, count):
        for i in range(count):
            key = randrange(3) + 1
            if key == 1:
                rand_shape = sphere()
                rand_shape.in_rand()
                self.store.append(rand_shape)
            elif key == 2:
                rand_shape = parallelepiped()
                rand_shape.in_rand()
                self.store.append(rand_shape)
            elif key == 3:
                rand_shape = regtet()
                rand_shape.in_rand()
                self.store.append(rand_shape)
        pass

    # Вывод содержимого контейнера в консоль
    def print(self, sorted):
        print("Sorted container contains" if sorted else "Container contains", len(self.store), "elements:")
        for shape in self.store:
            shape.print()
        pass

    # Вывод содержимого контейнера в указанный поток
    def write(self, ostream, sorted):
        if (sorted):
            ostream.write("Container contains {} elements:\n".format(len(self.store)))
        else:
            ostream.write("Sorted container contains {} elements:\n".format(len(self.store)))
        for shape in self.store:
            shape.write(ostream)
            ostream.write("\n")
        pass

    # Сортировка фигур в контейнере по возрастанию
    def straightsel_sort(self):
        for i in range(len(self.store)):
            min_idx = i
            for j in range(i + 1, len(self.store)):
                if self.store[min_idx].surf_sq() > self.store[j].surf_sq():
                    min_idx = j
            self.store[i], self.store[min_idx] = self.store[min_idx], self.store[i]
        pass
