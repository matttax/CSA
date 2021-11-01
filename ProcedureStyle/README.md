**Задание:**
<br/>Обобщённый артефакт: объемная (трехмерная) геометрическая фигура.
<br/>Базовые альтернативы:
<br/>&nbsp;&nbsp;&nbsp;&nbsp;•	Шар (целочисленный радиус)
<br/>&nbsp;&nbsp;&nbsp;&nbsp;•	Параллелепипед (три целочисленных ребра)
<br/>&nbsp;&nbsp;&nbsp;&nbsp;•	Правильный тетраэдр (длина ребра – целое)
<br/>Общая функция для всех альтернатив: вычисление площади поверхности.
<br/>Обработка данных: сортировка с помощью прямого выбора (Straight Selection).

**Файлы:**
<br/>•	main.cpp(2,06 KB):
<br/>&nbsp;&nbsp;&nbsp;&nbsp;Содержит функцию main, через неё происходит заполнение контейнера, чтение файла и т.д. Используется для тестирования.
<br/>•	container.cpp(1,73 KB) & container.h(1,19 КB):
<br/>&nbsp;&nbsp;&nbsp;&nbsp;Структура данных для хранения геометрических фигур.
<br/>•	shape.cpp(2,4 KB) & shape.h(1.11 KB):
<br/>&nbsp;&nbsp;&nbsp;&nbsp;Описание обобщённой фигуры. Содержит функции чтения, поиска площади поверхности и рандомной генерации.
<br/>•	sphere.cpp(717 В) & sphere.h(674 В);
<br/>•	parallelepiped.cpp(956 B) & parallelepiped.h(874 B);
<br/>•	reget.cpp(908 В) & regtet.h(824 В):
<br/>&nbsp;&nbsp;&nbsp;&nbsp;Описания фигур. Описаны функции чтения, поиска площади поверхности и рандомной генерации.
<br/>•	rand.h(255 В): 
<br/>&nbsp;&nbsp;&nbsp;&nbsp;Генератор случайных чисел от 1 до 20.

**Команды для терминала:**
<br/>./task01 -f [inputFileName] [outputFileName] [sortedOutputFileName] - ввод фигур из файла.
<br/>./task01 -n [number] [outputFileName] [sortedOutputFileName] - рандомная генерация n фигур.

**Тесты:**
<br/>6 тестов папке tests. Проверяются в том числе неоднозначные случаи.


![alt text](https://github.com/matttax/CSA/blob/main/ProcedureStyle/architecture.jpg)
