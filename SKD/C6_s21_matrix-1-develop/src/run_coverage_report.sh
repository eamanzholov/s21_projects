#!/bin/bash

echo "Запуск docker-compose..."
docker-compose up --build

# Проверка успешности запуска контейнера
if [ $? -ne 0 ]; then
  echo "Ошибка при запуске контейнера"
  exit 1
fi

# Экспорт контейнера в файл:
docker save -o s21_matrix.tar src_s21_matrix

# Остановка и удаление контейнера
echo "Остановка и удаление контейнера..."
docker stop s21_matrix_container
docker rm s21_matrix_container

# Проверка успешности остановки и удаления контейнера
if [ $? -ne 0 ]; then
  echo "Ошибка при остановке и удалении контейнера"
  exit 1
fi

echo "Открытие отчета в браузере..."
xdg-open ./report/index.html

echo "Скрипт успешно выполнен!"