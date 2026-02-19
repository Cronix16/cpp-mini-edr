#!/bin/bash
echo "Compiling Mini-EDR"
g++ -std=c++17 edr.cpp -o edr

if[$? -eq 0]; then
echo "Build successfull! Run with sudo ./edr"
else
echo "Build failed"
fi
