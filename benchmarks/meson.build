tsp_solver_benchmark = executable('tspsolver_benchmark', 'tspsolver_benchmark.cpp',
	include_directories: salesman_awesome_inc,
	link_with: [libsalesman_awesome, libmapgen],
	dependencies: [graph_dep,celero_dep])

main = executable('main', 'main.cpp',
	include_directories: salesman_awesome_inc,
	link_with: [libsalesman_awesome, libmapgen],
	dependencies: [graph_dep,celero_dep])

benchmark('TSP Solver', tsp_solver_benchmark, args: ['-t', 'tspsolver_benchmark.csv'])
