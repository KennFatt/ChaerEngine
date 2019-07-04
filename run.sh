#!/bin/bash

STABLE_DIR=out/stable
TEST_DIR=out/test

# Use current milisecond as build id.
TIMESTAMP=$(date +%s)

# Fire the builder.
build() {
    make BUILD_ID=$TIMESTAMP DEFAULT_BUILD_MODE=$1
}

# Execute the output.
run() {
    case "$1" in
        stable)
            ./out/$1/$TIMESTAMP/*_$TIMESTAMP stable_$TIMESTAMP
            ;;
        test)
            ./out/$1/*_$TIMESTAMP test_$TIMESTAMP
            ;;
        *)
            echo "Unknown parameter $1"
            ;;
    esac
}

# If everything work as expected.
# Use: --stable.
stable_opt() {
    mkdir $STABLE_DIR/$TIMESTAMP
    local stable_out=$STABLE_DIR/$TIMESTAMP
    cp unittest.c $stable_out/unittest_$TIMESTAMP.c
}

# This prevent Makefiles to occuring an error cause directory is not exist.
mkdir -p $STABLE_DIR/object
mkdir -p $TEST_DIR/object

case "$1" in
    --clean-test | -ct)
        rm $TEST_DIR/chaerengine_test_*
        clear
        echo "Cleaning all the test files."
    ;;

    --stable | -s)
        stable_opt
        build stable && run stable
        ;;

    *)
        build test && run test
    ;;
esac