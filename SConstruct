env = Environment()
env.Replace(CXX = "g++-4.8")

env['CXXFLAGS'] = '-fPIC -g -ggdb -Wall -pedantic -std=c++0x'
# env['LIBS']     = 'sfml-window', 'sfml-system'  # 'SDL m ...'
lib_target = 'basic_ea'
target  = 'ea'

sources = Split("""
        src/main.cpp
        src/basic_genotype.cpp
        src/basic_phenotype.cpp
        src/basic_individual.cpp
        src/basic_development.cpp
        src/one_max_development.cpp
        src/surprising_sequences_development.cpp
        src/basic_fitness.cpp
        src/surprising_sequences_fitness.cpp
        src/bit_string_fitness.cpp
        src/basic_adult_selection.cpp
        src/full_generational_replacement.cpp
        src/over_production.cpp
        src/generational_mixing.cpp
        src/basic_parent_selection.cpp
        src/fitness_proportionate.cpp
        src/sigma_scaling.cpp
        src/boltzmann_scaling.cpp
        src/tournament_selection.cpp
        src/basic_genetic_operator.cpp
        src/basic_ideal_individual.cpp
        src/one_max_ideal.cpp
        src/surprising_sequences_ideal.cpp
        src/evolutionary_algorithm.cpp
        src/csv_writer.cpp
        src/debug_writer.cpp
""")

env.Program(target, sources)
env.StaticLibrary(lib_target, sources)
