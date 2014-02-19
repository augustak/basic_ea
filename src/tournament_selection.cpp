#include "tournament_selection.hpp"

#include <algorithm>
#include <cstdlib>

namespace ea
{

individual_pair_vector tournament_selection::operator()(const individual_vector& adults)
{
    individual_pair_vector parents;
    const std::size_t NUM_CHILDREN = adults.size();
    float selection_probability;
    const std::size_t POOL_SIZE = rand() % adults.size();

    for(std::size_t i = 0; i < NUM_CHILDREN; ++i)
    {
        // first parent
        selection_probability = 0.2;
        std::size_t left_parent = 0;
        individual_vector pool;
        for(std::size_t j = 0; j < POOL_SIZE; ++j)
        {
            pool.push_back(adults[rand() % adults.size()]);
        }
        std::sort(pool.begin(), pool.end(), &reverse_compare_individuals);
        for(std::size_t j = 0; j < pool.size(); ++j)
        {
            float random = float(rand())/RAND_MAX;
            if(random < selection_probability)
            {
                left_parent = j;
                break;
            }
            selection_probability *= (1.0 - selection_probability);
        }
        // clear pool
        pool.clear();

        // second parent
        // reset selection probability
        selection_probability = 0.2;
        std::size_t right_parent = 0;
        for(std::size_t j = 0; j < POOL_SIZE; ++j)
        {
            pool.push_back(adults[rand() % adults.size()]);
        }
        std::sort(pool.begin(), pool.end(), &reverse_compare_individuals);
        for(std::size_t j = 0; j < pool.size(); ++j)
        {
            float random = float(rand())/RAND_MAX;
            if(random < selection_probability)
            {
                right_parent = j;
                break;
            }
            selection_probability *= (1.0 - selection_probability);
        }
        
        parents.push_back(std::make_pair(adults[left_parent], adults[right_parent]));
    }

    return parents;
}

}
