#!/bin/bash

if [[ $1 == "/bin/bash" ]]
then
    /bin/bash
    exit 0
fi

if ! [[ -d build ]]
then
    mkdir build
    cmake -S . -B ./build
fi

if cmake --build ./build -j8
then
    ./build/$1
else
    rm -rf ./build/*
    cmake -S . -B ./build
    cmake --build ./build -j 8
    ./build/$1
fi