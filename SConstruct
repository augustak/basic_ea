env = Environment()
env.Replace(CXX = "g++-4.8")

env['CXXFLAGS'] = '-g -ggdb -Wall -pedantic -std=c++0x'
# env['LIBS']     = 'sfml-window', 'sfml-system'  # 'SDL m ...'

target  = 'ea'

sources = Split("""
        src/main.cpp
        src/basic_genotype.cpp
        src/basic_phenotype.cpp
        src/basic_individual.cpp
        src/basic_development.cpp
        src/basic_fitness.cpp
        src/basic_adult_selection.cpp
        src/basic_parent_selection.cpp
        src/basic_genetic_operator.cpp
        src/evolutionary_algorithm.cpp
""")

env.Program(target, sources)
