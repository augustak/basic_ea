#include "full_generational_replacement.hpp"

#include <algorithm>

namespace ea
{

void full_generational_replacement::operator()(
        const individual_vector& young_adults, 
        individual_vector& population) const
{
    free_individuals(population);
    population.clear();
    for(std::size_t i = 0; i < young_adults.size(); ++i)
    {
        population.push_back(young_adults[i]);
    }
}

}
