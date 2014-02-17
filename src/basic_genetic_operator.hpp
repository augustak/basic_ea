#ifndef BASIC_GENETIC_OPERATOR_HPP
#define BASIC_GENETIC_OPERATOR_HPP

#include <utility>
#include <vector>

#include "basic_genotype.hpp"

namespace ea
{

class basic_genetic_operator
{
    public:
        virtual ~basic_genetic_operator() {}
        virtual std::vector<basic_genotype*> operator()(
                const basic_genotype*, const basic_genotype*);
};

void mutation(basic_genotype*);
genotype_pair one_crossover(const basic_genotype*, const basic_genotype*);
genotype_pair two_crossover(const basic_genotype*, const basic_genotype*);

}

#endif
