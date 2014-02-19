#include "basic_individual.hpp"

#include <cmath>

namespace ea
{

basic_individual::basic_individual(basic_genotype* gen, basic_phenotype* phen) :
    genotype_(gen), phenotype_(phen)
{}

basic_individual::~basic_individual()
{
    delete genotype_;
    delete phenotype_;
}

std::string basic_individual::info() const
{
    std::stringstream ret;
    ret << "phenotype: ";
    for(std::size_t i = 0; i < phenotype_->size(); ++i)
    {
        ret << "\t" << (*phenotype_)[i];
    }
    ret << "\t\tgenotype: ";
    for(std::size_t i = 0; i < genotype_->size(); ++i)
    {
        ret << (*genotype_)[i];
        if(i%8==7) ret << " ";
    }
    return ret.str();
}

bool compare_individuals(basic_individual* lhs, basic_individual* rhs)
{
    return *lhs < *rhs;
}

bool reverse_compare_individuals(basic_individual* lhs, basic_individual* rhs)
{
    return *rhs < *lhs;
}

void free_individual(basic_individual* individual)
{
    delete individual;
}

void free_individuals(std::vector<basic_individual*>& individuals)
{
    for(std::size_t i = 0; i < individuals.size(); ++i)
    {
        delete individuals[i];
    }
    individuals.clear();
}

void print_individuals(const std::vector<basic_individual*>& individuals)
{
    for(std::size_t i = 0; i < individuals.size(); ++i)
    {
        std::cout << "id: " << i << "\t\t" << individuals[i]->info() << std::endl;
    }
}

double total_fitness(const individual_vector& population)
{
    double sum = 0.0;
    for(std::size_t i = 0; i < population.size(); ++i)
    {
        sum += population[i]->fitness();
    }
    return sum;
}

double average_fitness(const individual_vector& population)
{
    return total_fitness(population) / population.size();
}

double standard_deviation(const individual_vector& population)
{
    double std = 0.0;
    double avg = average_fitness(population);
    for(std::size_t i = 0; i < population.size(); ++i)
    {
        std += std::pow(population[i]->fitness() - avg, 2);
    }
    return std::sqrt(std / population.size());
}

}
