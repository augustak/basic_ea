#include "boltzmann_scaling.hpp"

#include <cmath>
#include <cstdlib>

namespace ea
{
boltzmann_scaling::boltzmann_scaling(double t, double d_t) :
    temp_(t), d_temp_(d_t) 
{
}

individual_pair_vector boltzmann_scaling::operator()(const individual_vector& adults)
{
    individual_pair_vector parents;

    std::vector<double> boltzmanns(adults.size());
    double total_boltzmann = 0.0;
    for(std::size_t i = 0; i < boltzmanns.size(); ++i)
    {
        boltzmanns[i] = std::pow(M_E, double(adults[i]->fitness())/temp_);
        total_boltzmann += boltzmanns[i];
    }

    const std::size_t NUM_CHILDREN = adults.size();
    for(std::size_t i = 0; i < NUM_CHILDREN; ++i)
    {
        int left_parent = rand() % adults.size();
        float left_rand = float(rand())/RAND_MAX;
        for(std::size_t j = 0; j < adults.size(); ++j)
        {
            left_rand -= boltzmanns[j]/total_boltzmann;
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
            right_rand -= boltzmanns[j]/total_boltzmann;
            if(right_rand < 0.0)
            {
                right_parent = j;
                break;
            }
        }

        while(left_parent == right_parent) right_parent = rand()%adults.size();

        parents.push_back(std::make_pair(adults[left_parent], adults[right_parent]));
    }
    temp_ -= d_temp_;
    if(temp_ <= 0) temp_ = 0.1;
    return parents;
}

}
