#!/bin/bash

# Compilar TROCO
echo "$(date) Compilando troco.c"
gcc -Wall -ansi -O2 -o .saldo desculpa.c
if [ $? == 0 ]; then
  echo "$(date) Compilação concluída com suceosso"
else
  echo "$(date) Erro ao compilar troco.c... Abortando testes"
  exit 1
fi

echo "$(date) Iniciando testes: Verifique o arquivo testes.log"
echo "Arquivo de log dos teste de troco em $(date)" > testes.log
for i in 1 2 3 4 5 6 7 8 9 ; do
  for j in saldo/test$i/in*; do
    ./.saldo < $j > ttt
    diff ttt saldo/test$i/out${j##saldo/test$i/in} > teste$i_${j##saldo/test$i/in}.diff
    if [ $? == 0 ]; then
      echo "OK $j" >> testes.log
    else
    	echo "NOK $j: Verifique as diferenças no arquivo teste$i_${j##saldo/test$i/in}.diff" >> testes.log
    fi
  done
done
rm ttt
echo "$(date) Testes finalizados"
