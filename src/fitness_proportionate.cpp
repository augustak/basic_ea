#include "fitness_proportionate.hpp"

#include <cstdlib>

namespace ea
{

individual_pair_vector fitness_proportionate::operator()(const individual_vector& adults)
{
    individual_pair_vector parents;
    float fitness_sum = 0.0;
    for(std::size_t i = 0; i < adults.size(); ++i)
    {
        fitness_sum += adults[i]->fitness();
    }
    // number of children (parents) to make
    const std::size_t NUM_CHILDREN = adults.size() * children_multiplier_;
    for(std::size_t i = 0; i < NUM_CHILDREN; ++i)
    {
        int left_parent = rand() % adults.size();
        float left_rand = float(rand())/RAND_MAX;
        for(std::size_t j = 0; j < adults.size(); ++j)
        {
            left_rand -= float(adults[j]->fitness())/fitness_sum;
            if(left_rand < 0.0)
            {
                left_parent = j;
                break;
            }
        }

        int right_parent = rand() % adults.size();
        float right_rand = float(rand())/RAND_MAX;
        for(std::size_t j = 0; j < adults.size(); ++j)
        {
            right_rand -= float(adults[j]->fitness())/fitness_sum;
            if(right_rand < 0.0)
            {
                right_parent = j;
                break;
            }
        }

        while(left_parent == right_parent) right_parent = rand()%adults.size();

        parents.push_back(std::make_pair(adults[left_parent], adults[right_parent]));
    }

    return parents;
}

}
