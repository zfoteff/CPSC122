#to run: make
calc: CalcTst.o Calc.o stack2.o list1.o
	g++ -o calc CalcTst.o Calc.o stack2.o list1.o

CalcTst.o: CalcTst.cpp
	g++ -c CalcTst.cpp 

Calc.o: Calc.cpp
	g++ -c Calc.cpp 

stack1.o: stack1.cpp
	g++ -c stack2.cpp 

list1.o: list1.cpp
	g++ -c list1.cpp 
