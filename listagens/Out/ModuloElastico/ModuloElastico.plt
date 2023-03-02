reset
set title""
set xlabel "Temperatura (ºC)"
set ylabel "Modulo Elastico (GPa)"
f(x) = a*x + b
fit f(x) 'moduloElastico.txt' via a,b 
plot 'moduloElastico.txt', f(x)
set term post eps enhanced color
set out 'ModuloElastico.eps' 
