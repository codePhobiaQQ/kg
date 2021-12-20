run: compile  
	./a.out > ./FilesData/result.txt

compile:
	g++ -std=c++11 main.cpp ./KgClass/KgClass.cpp
	
