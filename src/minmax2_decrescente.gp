set datafile separator ","
set terminal png size 900,400
set output 'MinMax2 Decrescente.png'
set title 'Tempo de execução para MinMax2'
set xlabel 'Tamanho do vetor'
set ylabel 'Tempo de execução (ms)'  
plot '../datasets/resultados_minMax2.csv' every ::9::12 using 1:4 with lp lw 2 lc rgb 'blue' title 'MinMax2 Decrescente'
