#include "evolutionary_algorithm.hpp"

namespace ea
{

evolutionary_algorithm::evolutionary_algorithm() :
    development(new basic_development()),
    fitness(new basic_fitness()),
    adult_selection(new basic_adult_selection()),
    parent_selection(new basic_parent_selection()),
    genetic_operator(new basic_genetic_operator())
{
}

evolutionary_algorithm::evolutionary_algorithm(basic_development* dev,
        basic_fitness* fit, basic_adult_selection* adult,
        basic_parent_selection* parent, basic_genetic_operator* gen) :
    development(dev),
    fitness(fit),
    adult_selection(adult),
    parent_selection(parent),
    genetic_operator(gen)
{
}

evolutionary_algorithm::~evolutionary_algorithm()
{
    delete development;
    delete fitness;
    delete adult_selection;
    delete parent_selection;
    delete genetic_operator;
    free_individuals(population);
}

void evolutionary_algorithm::simulate_generation()
{
    // develop phenotypes from genotypes
    phenotype_vector phenotypes;
    for(std::size_t i = 0; i < children.size(); ++i)
    {
        phenotypes.push_back((*development)(children[i]));
    }
    // generate individuals
    individual_vector young_adults;
    for(std::size_t i = 0; i < phenotypes.size(); ++i)
    {
        young_adults.push_back(new basic_individual(children[i], phenotypes[i]));
    }
    // calculate fitness of individuals
    for(std::size_t i = 0; i < young_adults.size(); ++i)
    {
        young_adults[i]->set_fitness((*fitness)(young_adults[i]->phenotype()));
    }
    // adult selection
    (*adult_selection)(young_adults, population);
    std::cout << "********************Population***********************" << std::endl;
    for(std::size_t i = 0; i < population.size(); ++i)
    {
        std::cout << population[i]->info() << std::endl;
    }
    
    // parent selection
    individual_pair_vector parents = (*parent_selection)(population);
    // mate parents
    children.clear();
    for(std::size_t i = 0; i < parents.size(); ++i)
    {
        genotype_vector child = (*genetic_operator)(parents[i].first->genotype(), 
                    parents[i].second->genotype());
        for(std::size_t j = 0; j < child.size(); ++j)
        {
            children.push_back(child[j]);
        }
    }
}

}
