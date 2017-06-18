#!/bin/sh
#
# Generate a list of random numbers with no repeats
#

no_repeat=false

echo "How big?"
read size

# Clear the old list
> LIST

for i in $(seq 1 ${size})
  do
   value=$( expr ${RANDOM} % ${size} )
   [ ${no_repeat}X = "trueX" ] && grep -q ${value} LIST || echo ${value} >> LIST
done
