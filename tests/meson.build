boost_testing = dependency('boost', modules: 'test')

libmapgen = shared_library('mapgen', 'mapgen/mapgen.cpp', dependencies: graph_dep)

heuristics_test = executable('heuristics_test', 'heuristics_test.cpp',
	include_directories: salesman_awesome_inc,
	link_with: [libsalesman_awesome, libmapgen],
	dependencies: [boost_testing, graph_dep])

mapgen_test = executable('mapgen_test', 'mapgen_test.cpp',
	include_directories: salesman_awesome_inc,
	link_with: [libsalesman_awesome, libmapgen],
	dependencies: [boost_testing, graph_dep])

solver_test = executable('solver_test', 'solver_test.cpp',
	include_directories: salesman_awesome_inc,
	link_with: [libsalesman_awesome, libmapgen],
	dependencies: [boost_testing, graph_dep])

test('Heuristics Test', heuristics_test, args: ['-l', 'test_suite'])
test('MapGen Test', mapgen_test, args: ['-l', 'test_suite'])
test('Solver Test', solver_test, args: ['-l', 'test_suite'])
