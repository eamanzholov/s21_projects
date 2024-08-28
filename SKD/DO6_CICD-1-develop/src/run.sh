#!/bin/bash

scp src/configure_sudo.sh yonnrose@192.10.10.2:/home/yonnrose/
ssh yonnrose@192.10.10.2 "chmod +x /home/yonnrose/configure_sudo.sh && /home/yonnrose/configure_sudo.sh"

scp src/cat/s21_cat yonnrose@192.10.10.2:/home/yonnrose/
ssh yonnrose@192.10.10.2 "sudo mv /home/yonnrose/s21_cat /usr/local/bin/"
scp src/grep/s21_grep yonnrose@192.10.10.2:/home/yonnrose/
ssh yonnrose@192.10.10.2 "sudo mv /home/yonnrose/s21_grep /usr/local/bin/"
