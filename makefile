all:
	g++ -std=c++11 main.cpp snake.cpp input.cpp snake_map.cpp -o snake -lpthread