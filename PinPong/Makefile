CC = g++
PrjName = pinpong
SRC = *.cpp
FLAGS =-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

compile: $(SRC)

	$(CC) $(SRC) -o $(PrjName) $(FLAGS)

compile_run: 

	$(CC) $(SRC) -o $(PrjName) $(FLAGS)
	./$(PrjName)
