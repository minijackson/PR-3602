project('PR-3602', 'cpp', version: '0.1', default_options: ['cpp_std=c++14'], license: 'MIT')

add_global_arguments(['-fdiagnostics-color=always', '-Wno-padded'], language: 'cpp')

boost_dep = dependency('boost', modules: ['graph'])

subdir('./src/')
subdir('./tests/')
