#ifndef BASIC_INDIVIDUAL_HPP
#define BASIC_INDIVIDUAL_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "basic_genotype.hpp"
#include "basic_phenotype.hpp"

namespace ea
{

class basic_individual
{
    public:
        // constructors
        basic_individual(basic_genotype*, basic_phenotype*);
        virtual ~basic_individual();
        // modifiers
        void set_fitness(int f) { fitness_ = f; }
        // accessors
        const basic_genotype* genotype() const { return genotype_; }
        const basic_phenotype* phenotype() const { return phenotype_; }
        int fitness() const { return fitness_; }
        // info
        virtual std::string info() const;
    private:
        // internal data
        basic_genotype* genotype_;
        basic_phenotype* phenotype_;
        int fitness_;
};

void free_individuals(std::vector<basic_individual*>&);
void print_individuals(const std::vector<basic_individual*>&);

typedef std::pair<basic_individual*, basic_individual*> individual_pair;
typedef std::vector<individual_pair> individual_pair_vector;
typedef std::vector<basic_individual*> individual_vector;

}

#endif
