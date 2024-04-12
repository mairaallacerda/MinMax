set datafile separator ","
set terminal png size 900,400
set output 'MinMax1 Aleatório.png'
set title 'Tempo de execução para MinMax1'
set xlabel 'Tamanho do vetor'
set ylabel 'Tempo de execução (ms)'  
plot '../datasets/resultados_minMax1.csv' every ::1::4 using 1:4 with lp lw 2 lc rgb 'blue' title 'MinMax1 - Aleatório'
