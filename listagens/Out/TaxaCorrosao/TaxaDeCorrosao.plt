reset
set title""
set xlabel "Temperatura (ºC)"
set ylabel "Taxa de Corrosão (mm/y)"
f(x) = a*x + b
fit f(x) 'TaxaDeCorrosao.txt' via a,b 
plot 'TaxaDeCorrosao.txt', f(x)
set term post eps enhanced color
set out 'TaxaDeCorrosao.eps' 
