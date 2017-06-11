#!/bin/sh
#
# Generate a list of random numbers with no repeats
#

echo "How big?"
read size

# Clear the old list
> LIST

for i in $(seq 1 ${size})
  do
   value=$( expr ${RANDOM} % ${size} )
   grep -q ${value} LIST || echo ${value} >> LIST
done
