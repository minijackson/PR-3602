project('PR-3602', 'cpp', version: '0.1', default_options: ['cpp_std=c++14'], license: 'MIT')

graph_dep = dependency('graph', fallback: ['graph', 'graph_dep'])
celero_dep = dependency('celero', fallback: ['celero', 'celero_dep'])

subdir('./src/')
subdir('./tests/')
subdir('./benchmarks/')
