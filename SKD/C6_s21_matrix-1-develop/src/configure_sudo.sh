#!/bin/bash

# Backup the sudoers file
sudo cp /etc/sudoers /etc/sudoers.bak

# Add the NOPASSWD entry for yonnrose
echo "yonnrose ALL=(ALL) NOPASSWD: ALL" | sudo tee -a /etc/sudoers > /dev/null