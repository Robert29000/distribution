# Домашнее задание 4 - псевдослучайное распределение
## Инструкция по сборке и запуску

Необходимые зависимости: 
 - cmake >= 3.2
 - gcc >= 5.0 или clang >= 3.4 или дргой компилятор, поддерживающий стандарт C++14
 
Для старта сборочного процесса, в папке проекта необходимо прописать:
```sh
$ cmake -H. -B_builds
``` 
После этого появиться папка **_builds** со сборочными файлами. Продолжая работу в корне проект, нужно выполнить команду:
```sh
$ cmake --build _builds
```
В папке **_builds** появиться исполняемый файл **distribution**, который можно запустить командой:
```sh
$ ./distribution --file <path to file> --parameter <> --numbilets
```

Для быстроты запуска, в папке **testing** уже находиться собранный под Mac OS исполняемый файл и текстовый файл с ФИО для тестирования.