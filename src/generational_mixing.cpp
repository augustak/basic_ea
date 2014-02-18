#include "generational_mixing.hpp"

#include <algorithm>

namespace ea
{

void generational_mixing::operator()(const individual_vector& young_adults, 
        individual_vector& population) const
{
    individual_vector all;
    all.reserve(young_adults.size() + population.size());
    all.insert(all.end(), young_adults.begin(), young_adults.end());
    all.insert(all.end(), population.begin(), population.end());
    std::sort(all.begin(), all.end(), &reverse_compare_individuals);
    population.clear();
    for(std::size_t i = 0; i < POP_SIZE; ++i)
    {
        population.push_back(all[i]);
    }
    for(std::size_t i = POP_SIZE; i < all.size(); ++i)
    {
        free_individual(all[i]);
    }
}

}
