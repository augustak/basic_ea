#include "evolutionary_algorithm.hpp"

#include <cmath>

namespace ea
{

evolutionary_algorithm::evolutionary_algorithm(std::size_t size) :
    development(new basic_development()),
    fitness(new basic_fitness()),
    adult_selection(new basic_adult_selection()),
    parent_selection(new basic_parent_selection()),
    genetic_operator(new basic_genetic_operator()),
    ideal_individual(new basic_ideal_individual()),
    POP_SIZE(size)
{
    adult_selection->set_population_size(POP_SIZE);
}

evolutionary_algorithm::evolutionary_algorithm(basic_development* dev,
        basic_fitness* fit, basic_adult_selection* adult,
        basic_parent_selection* parent, basic_genetic_operator* gen,
        basic_ideal_individual* ideal, std::size_t size) :
    development(dev),
    fitness(fit),
    adult_selection(adult),
    parent_selection(parent),
    genetic_operator(gen),
    ideal_individual(ideal),
    POP_SIZE(size)
{
    adult_selection->set_population_size(POP_SIZE);
}

evolutionary_algorithm::~evolutionary_algorithm()
{
    delete development;
    delete fitness;
    delete adult_selection;
    delete parent_selection;
    delete genetic_operator;
    delete ideal_individual;
    free_individuals(population);
}

basic_individual* evolutionary_algorithm::simulate_generation()
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
    // print averages
    unsigned int fitness_sum = 0;
    double max_fitness = population[0]->fitness();
    for(std::size_t i = 0; i < population.size(); ++i)
    {
        if(population[i]->fitness() > max_fitness) max_fitness = population[i]->fitness();
        fitness_sum += population[i]->fitness();
    }
    std::cout << fitness_sum << " " << population.size() << std::endl;
    double average_fitness = double(fitness_sum)/population.size();
    std::cout << average_fitness << std::endl;
    double std = 0.0;
    for(std::size_t i = 0; i < population.size(); ++i)
    {
        std += std::pow(population[i]->fitness() - average_fitness, 2);
    }
    std = std::sqrt(std/population.size());
    csv.write(3, max_fitness, average_fitness, std);
    //std::cout << "fitness sum: " << fitness_sum << std::endl;
    //print_individuals(population);
    // check for the ideal individual if any
    for(std::size_t i = 0; i < population.size(); ++i)
    {
        if((*ideal_individual)(population[i]))
        {
            children.clear();
            return population[i];
        }
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

    return 0;
}

}
