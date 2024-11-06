#!/bin/bash
rm -rfd build/ CMakeUserPresets.json Portal2D Portal2D.exe
conan install . --output-folder=build --build=missing
