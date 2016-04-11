boost_testing = dependency('boost', modules: 'test')

mapgen_test = executable('mapgen_test', 'mapgen_test.cpp',
	include_directories: salesman_awesome_inc,
	link_with: libsalesman_awesome,
	dependencies: boost_testing)

test('MapGen Test', mapgen_test, args: ['-l', 'test_suite'])
