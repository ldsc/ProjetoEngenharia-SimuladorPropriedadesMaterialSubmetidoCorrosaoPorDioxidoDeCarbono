reset
set title""
set xlabel "Temperatura (ºC)"
set ylabel "Tenacidade a fratura (MPa m^0.5)"
f(x) = a*x + b
fit f(x) 'tenacidadeAFratura.txt' via a,b 
plot 'tenacidadeAFratura.txt', f(x)
set term post eps enhanced color
set out 'TenacidadeAFratura.eps' 
