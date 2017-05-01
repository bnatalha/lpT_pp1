# by @bnatalha
#
# Para executar:
#	$ gnuplot stats.gnuplot

clear
reset
set key off

set terminal png size 850,700 enhanced font 'Helvetica,10'
set output 'Multiplicacao_Matriz.png'

set title 'Crescimento do tempo de execução das funções multiplicaR() e multiplicaI()'

set xlabel "Dimensões das matrizez 'M' utilizadas na multipplicação (M_x_,_x)"
#set xtics (" 2"2, "   4"4, " 8"8, 16, 32,64,128,256,512,1024)
set xtics (2, 16, 32,64,128,256,512,1024)
set xtic rotate by -90 scale -1,5				

set ylabel "Tempo médio de uma execução (em centésimos)"
#set ytics 1250
set ytics (100, 750, 4100, 32500)
set yrange[00:32900]
set ytic scale -1				

set style data lines							
set style line 1 lw 2 lc rgb "blue" pointtype 4	

set key outside below right

plot "stats-ite.dat" using 1:3 title "MultiplicaI()" smooth freq with lines, \
	"stats-rec.dat" using 1:3 title "MultiplicaR()" smooth freq with lines 