# main.py обеспечивает простое тестирование
import sys
from container import *

if __name__ == '__main__':
    inputFileName = ""
    output_file_name1 = ""
    output_file_name2 = ""
    if sys.argv[1] == "-f":
        inputFileName = sys.argv[2]
        output_file_name1 = sys.argv[3]
        output_file_name2 = sys.argv[4]
        # Чтение исходного файла, содержащего данные, разделенные пробелами и переводами строки
        ifile = open(inputFileName)
        data = ifile.read()
        ifile.close()
        # Формирование массива строк, содержащего чистые данные в виде массива строк символов.
        str_array = data.replace("\n", " ").split(" ")
        container = container()
        container.read_string_arr(str_array)
    elif sys.argv[1] == "-n":
        container = container()
        container.in_rand(int(sys.argv[2]))
        output_file_name1 = sys.argv[3]
        output_file_name2 = sys.argv[4]
    else:
        print("Incorrect command line! "
              "You should write: \n\tpython main -f <inputFileName> <outputFileName1> <outputFileName2>\n"
              "or\tpython main -n <number of shapes> <outputFileName1> <outputFileName2>")
        exit()

    print('Start')

    # Вывод содержимого контейнера в файл и в консоль
    container.print(0)
    print()
    ofile = open(output_file_name1, 'w')
    container.write(ofile, 1)
    ofile.close()

    # Вывод отсортированного контейнера в файл и в консоль
    container.straightsel_sort()
    container.print(1)
    ofile = open(output_file_name2, 'w')
    container.write(ofile, 0)
    ofile.close()

    print('Finish')
