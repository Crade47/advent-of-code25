#!/bin/bash

if [ -z "$1" ]; then
  echo "provide path"
  exit 1
fi
DIR_PATH=$1

g++ -std=c++17 -O3 -o "$DIR_PATH/solution" "$DIR_PATH/solution.cpp"

"./$DIR_PATH/solution"
