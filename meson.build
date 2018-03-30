project('PR-3602', 'cpp', version: '0.1', default_options: ['cpp_std=c++14'], license: 'MIT')

add_global_arguments(['-fdiagnostics-color=always', '-Wno-padded'], language: 'cpp')

graph_dep = dependency('graph', fallback: ['graph', 'graph_dep'])
celero_dep = dependency('celero', fallback: ['celero', 'celero_dep'])

subdir('./src/')
subdir('./tests/')
subdir('./benchmarks/')
