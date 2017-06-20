#!/bin/sh
#
# Generate a list of random numbers with no repeats
#

echo "How big?"
read size

# Clear the old list
> LIST

/usr/bin/shuf -i 1-${size} -n ${size} > LIST
