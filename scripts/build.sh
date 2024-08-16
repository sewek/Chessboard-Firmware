#!/bin/bash

echo "Building the project..."

west build -p -b chessboard app

# If the build fails, exit the script
if [ $? -ne 0 ]; then
    echo "Build failed!"
    exit 1
fi

echo "Build successful!"
