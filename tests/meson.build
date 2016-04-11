boost_testing = dependency('boost', modules: 'test')

libmapgen = shared_library('mapgen', 'mapgen/mapgen.cpp')

mapgen_test = executable('mapgen_test', 'mapgen_test.cpp',
	include_directories: salesman_awesome_inc,
	link_with: [libsalesman_awesome, libmapgen],
	dependencies: boost_testing)

test('MapGen Test', mapgen_test, args: ['-l', 'test_suite'])
