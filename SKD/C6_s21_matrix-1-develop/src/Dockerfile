# Используем базовый образ Ubuntu
FROM ubuntu:latest

# Создаем пользователя
# RUN useradd -m dockeruser

# Обновляем пакеты и устанавливаем необходимые инструменты
RUN apt update && apt install -y \
    build-essential \
    check \
    lcov \
    gcc \
    valgrind \
    xdg-utils \
    gcovr \
    && apt clean && rm -rf /var/lib/apt/lists/*
    
# Устанавливаем рабочую директорию
WORKDIR /app

# Копируем файлы проекта в контейнер
COPY . /app

# Компилируем проект и генерируем gcov отчеты
RUN make && make gcov_report_1

# Удаляем ненужные файлы
RUN rm /app/Dockerfile /app/docker-compose.yml

# Удаляем ненужные утилиты
# RUN rm -f /usr/sbin/unix_chkpwd /usr/lib/dbus-1.0/dbus-daemon-launch-helper /usr/bin/gpasswd

# Снижаем привилегии необходимых утилит
# RUN chmod u-s /usr/bin/su /usr/bin/passwd /usr/bin/chsh /usr/bin/mount /usr/bin/newgrp /usr/bin/chfn /usr/bin/umount
# RUN chmod g-s /usr/sbin/pam_extrausers_chkpwd /usr/bin/chage /usr/bin/expiry

# Переключаемся на созданного пользователя
# USER dockeruser

# Добавляем инструкцию HEALTHCHECK
HEALTHCHECK CMD curl --fail http://localhost:8080/health || exit 1

# Команда по умолчанию для запуска контейнера
CMD ["make", "test", "gcov_report_1"]
