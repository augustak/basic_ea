#include "evolutionary_algorithm.hpp"

#include <sstream>
#include <algorithm>
#include <cmath>

typedef std::stringstream sstream;

namespace ea
{

evolutionary_algorithm::evolutionary_algorithm(std::size_t size,
        double mut_rate, double cross_rate, double children_mult, 
        const std::string& out, bool dflag) :
    development(new basic_development(DEFAULT_BIT_CHUNK_SIZE)),
    fitness(new basic_fitness()),
    adult_selection(new basic_adult_selection()),
    parent_selection(new basic_parent_selection()),
    genetic_operator(new basic_genetic_operator()),
    ideal_individual(new basic_ideal_individual()),
    POP_SIZE(size),
    MUTATION_RATE(mut_rate),
    CROSSOVER_RATE(cross_rate),
    CHILDREN_MULTIPLIER(children_mult),
    csv(out),
    debug(out),
    debug_flag(dflag)
{
    adult_selection->set_population_size(POP_SIZE);
    genetic_operator->set_mutation_rate(MUTATION_RATE);
    genetic_operator->set_crossover_rate(CROSSOVER_RATE);
    parent_selection->set_children_multiplier(CHILDREN_MULTIPLIER);
}

evolutionary_algorithm::evolutionary_algorithm(basic_development* dev,
        basic_fitness* fit, basic_adult_selection* adult,
        basic_parent_selection* parent, basic_genetic_operator* gen,
        basic_ideal_individual* ideal, std::size_t size,
        double mut_rate, double cross_rate, double children_mult,
        const std::string& out, bool dflag) :
    development(dev),
    fitness(fit),
    adult_selection(adult),
    parent_selection(parent),
    genetic_operator(gen),
    ideal_individual(ideal),
    POP_SIZE(size),
    MUTATION_RATE(mut_rate),
    CROSSOVER_RATE(cross_rate),
    CHILDREN_MULTIPLIER(children_mult),
    csv(out),
    debug(out),
    debug_flag(dflag)
{
    adult_selection->set_population_size(POP_SIZE);
    genetic_operator->set_mutation_rate(MUTATION_RATE);
    genetic_operator->set_crossover_rate(CROSSOVER_RATE);
    parent_selection->set_children_multiplier(CHILDREN_MULTIPLIER);
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
    // write data to stream and csv file
    write_data();
    // check for the ideal individual if any
    for(std::size_t i = 0; i < population.size(); ++i)
    {
        if((*ideal_individual)(population[i]))
        {
            children.clear();
            // return the ideal individual
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

    // no ideal individual found
    return 0;
}

void evolutionary_algorithm::write_data()
{
    individual_vector::iterator it = std::max_element(population.begin(), population.end(),
            &compare_individuals);
    double max_fitness = (*it)->fitness();
    double avg = average_fitness(population);
    double std = average_fitness(population);
    csv.write(3, max_fitness, avg, std);
    if(debug_flag)
    {
        //print_individuals(population);
        for(std::size_t i = 0; i < population.size(); ++i)
        {
            sstream ss;
            ss << "id: " << i << "\tphenotype:\t";
            for(std::size_t j = 0; j < population[i]->phenotype()->size(); ++j)
            {
                ss << " " << (*population[i]->phenotype())[j];
            }
            ss << "\tgenotype:";
            for(std::size_t j = 0; j < population[i]->genotype()->size(); ++j)
            {
                if(j % development->bit_chunk_size()==0) ss << " ";
                ss << (*population[i]->genotype())[j];
            }
            debug.write(1, ss.str().c_str());
        }
    }
}

}
