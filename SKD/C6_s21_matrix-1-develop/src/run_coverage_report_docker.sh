#!/bin/bash

# Шаг 1: Построение Docker образа
echo "Сборка Docker образа..."
docker build -t s21_matrix .

# Проверка успешности сборки
if [ $? -ne 0 ]; then
  echo "Ошибка при сборке Docker образа"
  exit 1
fi

# Шаг 2: Запуск контейнера в фоновом режиме
echo "Запуск контейнера..."
docker run -d --name s21_matrix_container s21_matrix

# Проверка успешности запуска контейнера
if [ $? -ne 0 ]; then
  echo "Ошибка при запуске контейнера"
  exit 1
fi

# Ожидание завершения работы контейнера
echo "Ожидание завершения работы контейнера..."
docker wait s21_matrix_container

# Шаг 3: Копирование отчета покрытия на хост-машину
echo "Копирование отчета покрытия..."
docker cp s21_matrix_container:/app/report ./report

# Проверка успешности копирования
if [ $? -ne 0 ]; then
  echo "Ошибка при копировании отчета покрытия"
  exit 1
fi

# Шаг 4: Остановка и удаление контейнера
echo "Остановка и удаление контейнера..."
docker stop s21_matrix_container
docker rm s21_matrix_container

# Проверка успешности остановки и удаления контейнера
if [ $? -ne 0 ]; then
  echo "Ошибка при остановке и удалении контейнера"
  exit 1
fi

# Шаг 5: Открытие отчета в браузере
echo "Открытие отчета в браузере..."
xdg-open ./report/index.html

echo "Скрипт успешно выполнен!"

# Шаг 6:
make valg
