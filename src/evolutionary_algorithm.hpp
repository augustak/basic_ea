#ifndef EVOLUTIONARY_ALGORITHM_HPP
#define EVOLUTIONARY_ALGORITHM_HPP

#include "basic_genotype.hpp"
#include "basic_phenotype.hpp"
#include "basic_development.hpp"
#include "basic_fitness.hpp"
#include "basic_adult_selection.hpp"
#include "basic_parent_selection.hpp"
#include "basic_genetic_operator.hpp"
#include "basic_ideal_individual.hpp"
#include "csv_writer.hpp"
#include "debug_writer.hpp"

namespace ea
{

class evolutionary_algorithm
{
    public:
        // constructors
        evolutionary_algorithm(std::size_t, double, double, double, const std::string&, 
                bool, const std::string&);
        evolutionary_algorithm(basic_development*, basic_fitness*,
                basic_adult_selection*, basic_parent_selection*,
                basic_genetic_operator*, basic_ideal_individual*,
                std::size_t, double, double, double, const std::string&, bool,
                const std::string&);
        ~evolutionary_algorithm();
        // TEH function
        basic_individual* simulate_generation();
        // modifiers
        void init_children(const genotype_vector& child) { children = child; }
        // write data
        void write_data();
    private:
        // evolutionary algorithms
        basic_development* development;
        basic_fitness* fitness;
        basic_adult_selection* adult_selection;
        basic_parent_selection* parent_selection;
        basic_genetic_operator* genetic_operator;
        // functor to check for the ideal individual
        basic_ideal_individual* ideal_individual;
        // population and size
        const std::size_t POP_SIZE;
        const double MUTATION_RATE;
        const double CROSSOVER_RATE;
        const double CHILDREN_MULTIPLIER;
        individual_vector population;
        genotype_vector children;
        // csv writer
        csv_writer csv;
        debug_writer debug;
        bool debug_flag;
};

}

#endif
