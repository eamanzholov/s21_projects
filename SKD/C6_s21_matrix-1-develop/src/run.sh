#!/bin/bash

scp src/configure_sudo.sh yonnrose@192.10.10.4:/home/yonnrose/
ssh yonnrose@192.10.10.4 "chmod +x /home/yonnrose/configure_sudo.sh && /home/yonnrose/configure_sudo.sh"

scp src/s21_matrix.a yonnrose@192.10.10.4:/home/yonnrose/
ssh yonnrose@192.10.10.4 "sudo mv /home/yonnrose/s21_matrix.a /usr/local/bin/"