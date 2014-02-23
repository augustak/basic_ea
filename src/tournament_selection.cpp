#include "tournament_selection.hpp"

#include <algorithm>
#include <cstdlib>

namespace ea
{

individual_pair_vector tournament_selection::operator()(const individual_vector& adults)
{
    individual_pair_vector parents;
    const std::size_t NUM_CHILDREN = adults.size() * children_multiplier_;
    float selection_probability;
    const std::size_t POOL_SIZE = double(adults.size()) * POOL_MULTIPLIER;
    individual_vector pool;
    for(std::size_t j = 0; j < POOL_SIZE; ++j)
    {
        pool.push_back(adults[rand() % adults.size()]);
    }
    std::sort(pool.begin(), pool.end(), &reverse_compare_individuals);

    for(std::size_t i = 0; i < NUM_CHILDREN; ++i)
    {
        // first parent
        selection_probability = P;
        std::size_t left_parent = 0;
        float random = float(rand())/RAND_MAX;
        for(std::size_t j = 0; j < pool.size(); ++j)
        {
            random -= selection_probability;
            if(random < 0)
            {
                left_parent = j;
                break;
            }
            selection_probability *= (1-P);
        }

        // second parent
        // reset selection probability
        selection_probability = P;
        std::size_t right_parent = 0;
        random = float(rand())/RAND_MAX;
        for(std::size_t j = 0; j < pool.size(); ++j)
        {
            random -= selection_probability;
            if(random < 0)
            {
                right_parent = j;
                break;
            }
            selection_probability *= (1-P);
        }

        while(left_parent == right_parent) right_parent = rand()%pool.size();
        
        parents.push_back(std::make_pair(pool[left_parent], pool[right_parent]));
    }

    return parents;
}

}
