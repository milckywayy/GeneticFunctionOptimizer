main.exe: ./main.cpp ./population.cpp ./individuals/individual.cpp ./objectives/quadratic.cpp ./constraints/constraints.cpp ./utils/randomNumberGenerator.cpp ./selections/tournamentSelection.cpp
	g++ -o ./main.exe ./main.cpp ./population.cpp ./individuals/individual.cpp ./objectives/quadratic.cpp ./constraints/constraints.cpp ./utils/randomNumberGenerator.cpp ./selections/tournamentSelection.cpp
	