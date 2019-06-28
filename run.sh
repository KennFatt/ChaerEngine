#!/bin/bash

# Use current milisecond as build id.
TIMESTAMP=$(date +%s)

# Fire the builder.
build() {
    make BUILD_ID=$TIMESTAMP
}

# Execute the output.
run() {
    ./out/*_$TIMESTAMP $TIMESTAMP
}

case "$1" in
    --clean-test | -ct)
        rm out/chaerengine_test_*
        clear
        echo "Cleaning all the test files."
    ;;

    *)
        build && run
    ;;
esac