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
        void set_mutation_rate(double mut_rate) { mutation_rate_ = mut_rate; }
        void set_crossover_rate(double cross_rate) { crossover_rate_ = cross_rate; }
    protected:
        double mutation_rate_;
        double crossover_rate_;
};

void mutation(basic_genotype*);
genotype_pair one_crossover(const basic_genotype*, const basic_genotype*);
genotype_pair two_crossover(const basic_genotype*, const basic_genotype*);
basic_genotype* one_crossover_single(const basic_genotype*, const basic_genotype*);
basic_genotype* two_crossover_single(const basic_genotype*, const basic_genotype*);

}

#endif
