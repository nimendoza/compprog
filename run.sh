#!/bin/bash

path=$1

g++ "${path}/solution.cpp" -o "${path}/output.exe"
eval "./${path}/output.exe"
