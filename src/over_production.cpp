#include "over_production.hpp"

#include <algorithm>

namespace ea
{

void over_production::operator()(const individual_vector& young_adults, 
        individual_vector& population) const
{
    individual_vector elites;
    if(population.size() >= count_ && elitism_)
    {
        std::sort(population.begin(), population.end(), &reverse_compare_individuals);
        for(std::size_t i = 0; i < count_; ++i)
        {
            elites.push_back(population[i]);
        }
        for(std::size_t i = count_; i < population.size(); ++i)
        {
            free_individual(population[i]);
        }
    }
    else free_individuals(population);
    population.clear();
    individual_vector copy = young_adults;
    for(std::size_t i = 0; i < elites.size(); ++i)
    {
        population.push_back(elites[i]);
    }
    std::sort(copy.begin(), copy.end(), &reverse_compare_individuals);
    for(std::size_t i = 0; i < pop_size_ - elites.size(); ++i)
    {
        population.push_back(copy[i]);
    }
    for(std::size_t i = pop_size_ - elites.size(); i < copy.size(); ++i)
    {
        free_individual(copy[i]);
    }
}

}
