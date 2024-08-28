#!/bin/bash

# Read a single key press
read -t 0.01 -n 1 key

if [ "$key" = "k" ]; then
    exit 20
elif [ "$key" = "K" ]; then
    exit 20
elif [ "$key" = "m" ]; then
    exit 21
elif [ "$key" = "M" ]; then
    exit 21
elif [ "$key" = "x" ]; then
    exit 10
elif [ "$key" = "X" ]; then
    exit 10
else exit 0
fi