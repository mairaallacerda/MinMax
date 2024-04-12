set datafile separator ","
set terminal png size 900,400
set output 'MinMax1 Decrescente.png'
set title 'Tempo de execução para MinMax1'
set xlabel 'Tamanho do vetor'
set ylabel 'Tempo de execução (ms)'  
plot '../datasets/resultados_minMax1.csv' every ::9::12 using 1:4 with lp lw 2 lc rgb 'blue' title 'MinMax1 Decrescente'
