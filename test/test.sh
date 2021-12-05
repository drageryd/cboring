#!/usr/bin/env bash

# Stand in test directory
cd "$(dirname "$(realpath "$0")")"

# Get test dependencies
# Not adding these as submodules keeps the repo clean when imported as library
# Getting a certain release keeps tests from breaking in the future.
DEPS="dependencies"
UNITY_VER="2.5.2"

if [[ ! -d ${DEPS} ]]
then
    echo "Downloading necessary tools into working directory"
    # Creating a temporary directory for tests
    mkdir -p ${DEPS}
    cd ${DEPS}
    echo "Getting Unity"
    curl -L https://github.com/ThrowTheSwitch/Unity/archive/refs/tags/v${UNITY_VER}.tar.gz | tar -xz
    cd ..
fi

# Build and run test
make clean
make CJSON_PATH="cJSON-${CJSON_VER}" UNITY_PATH="Unity-${UNITY_VER}"
./test
