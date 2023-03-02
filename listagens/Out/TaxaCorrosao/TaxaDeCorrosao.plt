reset
set title""
set xlabel "Temperatura (�C)"
set ylabel "Taxa de Corros�o (mm/y)"
f(x) = a*x + b
fit f(x) 'TaxaDeCorrosao.txt' via a,b 
plot 'TaxaDeCorrosao.txt', f(x)
set term post eps enhanced color
set out 'TaxaDeCorrosao.eps' 
