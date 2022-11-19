#!/bin/bash
echo "Решение квадратного уравнения"
read -e -p "Введите старший коэффициент: " a
read -e -p "Введите второй коэффициент: " b
read -e -p "Введите свободный член: " c

f=-1
z=0
D=$(((b)*(b)-4*(a)*(c)))
if [[ "$D" -lt "$z" ]]; then
        echo "Корней нет"
else
        D=$(echo "$D" |awk '{print sqrt($1)}')
        x1=$(((f*b+D)/(a+a)))
        x2=$(((f*b-D)/(a+a)))
        echo $x1
        echo $x2
fi
