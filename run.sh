#!/bin/bash

# Use current milisecond as build id.
TIMESTAMP=$(date +%s)

# Fire the builder.
build() {
    make BUILD_ID=$TIMESTAMP
}

# Execute the output.
run() {
    ./out/*_$TIMESTAMP
}

build && run