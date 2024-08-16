#!/bin/bash

echo "Launching..."

west build -b chessboard -t menuconfig app

# If the build fails, exit the script
if [ $? -ne 0 ]; then
    echo "Build failed!"
    exit 1
fi

