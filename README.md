# reveerse_file
консольное приложение, которое получает на вход бинарный файл произвольного размера и в качестве результата создает новый файл, в котором содержимое входного файла записано в обратном порядке (побайтно). Имена входного и выходного файлов должны передаваться через параметры командной строки:
[[
program.exe input.dat output.dat
]]

Например, если на входе файл input.dat в котором записаны байты {0x0A, 0x00, 0x20, 0xFF}, то на выходе должен быть файл output.dat в котором записаны байты {0xFF, 0x20, 0x00, 0x0A}.
