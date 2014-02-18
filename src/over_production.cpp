#include "over_production.hpp"

#include <algorithm>

namespace ea
{

void over_production::operator()(const individual_vector& young_adults, 
        individual_vector& population) const
{
    free_individuals(population);
    population.clear();
    individual_vector copy = young_adults;
    std::sort(copy.begin(), copy.end(), &reverse_compare_individuals);
    for(std::size_t i = 0; i < POP_SIZE; ++i)
    {
        population.push_back(copy[i]);
    }
    for(std::size_t i = POP_SIZE; i < copy.size(); ++i)
    {
        free_individual(copy[i]);
    }
}

}
