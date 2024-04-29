# simple-calculator

This project is a simple calculator that can do operations( Addition(+) , Subtraction(-) , Multiplication(*) , Division(/) )
only between two integers (numbers without fractions) and result is an integer

## Devices used:
-Atmega32 (where we put our code to do specific functions)
-LCD 16x2 (for displaying entered numbers, operation and result)
-Keypad 4x4 ( for entering numbers and operation and equal sign(=) )

## tools used:
-Proteus 8 Professional
-Atmel Studio 6.0


## Disadvantages:
-it can't do operations between numbers that has more than two digits ( digit for ones and digit for tens)

-if we want to do operations between numbers that each of them has one digit we should enter 0 for each number to put 0 in digit for tens

-if we enter one digit and do operation with it it considers it as digit for tens

for example if we enter 1 then our project will understand it is 10 not 1
so we should enter 01 to make our project understand it as 1 not 10

-it cannot do operations on fractions or number with a fraction correctly and result cannot be a fraction

for example if we divide 5/2 we will get 2 not 2.5 as 0.5 is ignored

## note:
-some problems were encountered in Atmel studio so you will find that there are addtitional files in file of this project which makes size of project bigger than expected so you can take code copy paste only not using same file of my own atmel studio.

