#ifndef EVOLUTIONARY_ALGORITHM_HPP
#define EVOLUTIONARY_ALGORITHM_HPP

#include "basic_genotype.hpp"
#include "basic_phenotype.hpp"
#include "basic_development.hpp"
#include "basic_fitness.hpp"
#include "basic_adult_selection.hpp"
#include "basic_parent_selection.hpp"
#include "basic_genetic_operator.hpp"

namespace ea
{

class evolutionary_algorithm
{
    public:
        // constructors
        evolutionary_algorithm();
        evolutionary_algorithm(basic_development*, basic_fitness*,
                basic_adult_selection*, basic_parent_selection*,
                basic_genetic_operator*);
        ~evolutionary_algorithm();
        // TEH function
        void simulate_generation();
        // modifiers
        void init_children(const genotype_vector& child) { children = child; }
    private:
        basic_development* development;
        basic_fitness* fitness;
        basic_adult_selection* adult_selection;
        basic_parent_selection* parent_selection;
        basic_genetic_operator* genetic_operator;
        individual_vector population;
        genotype_vector children;
};

}

#endif
