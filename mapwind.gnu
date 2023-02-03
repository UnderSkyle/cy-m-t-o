


set terminal png size 1080,920 enhanced font default
set output 'output.png'
unset key
set title 'graphique des vents'
set xlabel 'longitude'
set ylabel 'latitude'
set xrange [*:*]
set yrange [*:*]
plot 'ordereddataw' using 2:1:($3*10):($4*10) with vectors head filled
