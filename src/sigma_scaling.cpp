#include "sigma_scaling.hpp"

#include <cstdlib>

namespace ea
{

individual_pair_vector sigma_scaling::operator()(const individual_vector& adults)
{
    individual_pair_vector parents;

    std::vector<double> sigmas(adults.size());
    double avg = average_fitness(adults);
    double std = standard_deviation(adults);
    double total_sigma = 0.0;
    for(std::size_t i = 0; i < sigmas.size(); ++i)
    {
        sigmas[i] = sigma(adults[i], avg, std);
        total_sigma += sigmas[i];
    }

    const std::size_t NUM_CHILDREN = adults.size() * children_multiplier_;
    for(std::size_t i = 0; i < NUM_CHILDREN; ++i)
    {
        int left_parent = rand() % adults.size();
        float left_rand = float(rand())/RAND_MAX;
        for(std::size_t j = 0; j < adults.size(); ++j)
        {
            left_rand -= sigmas[j]/total_sigma;
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
            right_rand -= sigmas[j]/total_sigma;
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

double sigma(basic_individual* individual, double avg, double std)
{
    return 1 + ((individual->fitness() - avg) / (2*std));
}

}
