# GeneticFunctionOptimizer
## General:
C++ program for function optimization using a genetic algorithm. The program is equipped with a comprehensive suite of functionalities to efficiently search for optimal solutions in various scenarios. It features a modular design, enabling easy integration of custom objective functions and constraints.

The program uses an evolutionary algorithm to iteratively evolve a population of individuals over a specified number of generations. It applies selection, crossover, and mutation operations to create new generations of individuals. The fitness of each individual is evaluated based on the chosen objective function.  

The program supports multiple built-in objective functions (such as Quadratic, Rosenbrock, Cubic) and allows users to define their custom objective functions. It also provides flexibility in setting constraints on the optimization problem.

After the optimization process is complete, the program prints the optimal solution found, including the extremum value, the corresponding point in the function's domain, and the constraints applied.

## Features:
- Flexible Objective Functions: The program accommodates diverse objective functions, including built-in options like Quadratic, Rosenbrock, and Cubic, as well as the ability to define custom functions.
- Constraint Handling: Users can specify constraints to define feasible solution spaces for optimization problems.
- Customization: Parameters such as population size, mutation rate, and generations are customizable, tailoring the algorithm to specific optimization tasks.
- Extrema Detection: The program is capable of searching for both function minima and maxima, allowing adaptability to different optimization goals.

## Usage:
### Command-line options
Program offers various command-line options to customize the optimization process:
- `-f <function>: Specify the custom function to be optimized. Default: Rosenbrock.`
- `-c <constraints_file>: Read constraints from the specified file.`
- `-g <generations>: Specify the number of generations. Default: 500.`
- `-p <population>: Specify the population size. Default: 50.`
- `-m <mutation-rate>: Specify the mutation rate. Default: 0.01.`
- `-e <min/max>: Specify whether to find the function minimum or maximum. Default: minimum.`
- `h: Display the help message.`

### Constraints file structure:
- Each line in the file represents a constraint for a particular dimension.
- The minimum and maximum values for that dimension are separated by a space.
- Each line should contain only two numeric values: the minimum and maximum constraint values.

File structure:
~~~
min_value_1 max_value_1
min_value_2 max_value_2
min_value_3 max_value_3
...
~~~

Example:
~~~
-1.0 1.0
0.5 2.5
-10.0 0.0
~~~

### Function parsing:
The program supports following:
- Constants: `_pi = ~3.14`, `_e = ~2.72`
- Functions: `sin(x)`, `cos(x)`, `tan(x)`, `abs(x)`, `sqrt(x)`
- Arguments: `x0`, `x1`, `x2`, ...

Example functions:
-     "(x0-1)^2 + 1"
-     "(sin( _pi/2 ) * x0) + x1"

### Execution:
~~~
./optimization_program
~~~
By default, the program will use the Rosenbrock function, run for 500 generations with a population size of 50, a mutation rate of 0.01, and search for the function minimum.    

~~~
./optimization_program -e max -f "x0^2"
~~~
The program will optimize the quadratic function, searching for its maximum.    

~~~
./optimization_program -f "sin(x0*x1)" -c constraints.txt -g 1000 -p 75 -m 0.05 -e min
~~~
The program will use a user-defined custom function and read constraints from the constraints.txt file. It will search for the function minimum, run for 1000 generations with a population size of 75, and a mutation rate of 0.05.



    
