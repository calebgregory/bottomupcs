#!/bin/bash

if [ -z "$1" ]; then
  echo "supply path to a C file"
  exit 1
fi

dir="build/$1"
mkdir -p "$dir"

binary="$dir/out"
clang "$1" -o "$binary"
"$binary"
