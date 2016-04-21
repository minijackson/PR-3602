project('PR-3602', 'cpp', version: '0.1', default_options: ['cpp_std=c++14'], license: 'MIT')

boost_dep = dependency('boost', modules: ['graph'])

graph_dep = dependency('graph', fallback: ['graph', 'graph_dep'])

subdir('./src/')
subdir('./tests/')
