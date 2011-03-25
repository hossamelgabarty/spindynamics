#!/bin/bash
echo "plotting files from: $1"

plt_base=/tmp/.plt_$(basename $1)_

if [ -d $1 ]; then
  cat $1/* | sort -g > ${plt_base}raw
else
  cat $1 | sort -g > ${plt_base}raw
fi

./convolute/convolute $1 > ${plt_base}conv
a=($(basename $1 | tr ":" "\n"))
t="Spectrum for ${a[2]} 1H, ${a[3]} 14H, mwFreq = ${a[4]} GHz, B-Range: ${a[0]} (${a[1]} steps) ${a[5]}"
echo "$GNUPLOT_CMD set title '$t';
      set xlabel 'static B-field in Tesla';
      set ylabel 'intensity in a.u.';
      set grid;
      plot '${plt_base}conv' w lines notitle, '${plt_base}raw' w impulses notitle" | gnuplot -persist
