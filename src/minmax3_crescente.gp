set datafile separator ","
set terminal png size 900,400
set output 'MinMax3 Crescente.png'
set title 'Tempo de execução para MinMax3'
set xlabel 'Tamanho do vetor'
set ylabel 'Tempo de execução (ms)'  
plot '../datasets/resultados_minMax3.csv' every ::5::8 using 1:4 with lp lw 2 lc rgb 'blue' title 'MinMax3 Crescente'
