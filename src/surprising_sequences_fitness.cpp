#include "surprising_sequences_fitness.hpp"

#include <algorithm>

namespace ea
{

int surprising_sequences_fitness::operator()(const basic_phenotype* phen) const
{
    int fitness = max_global_fitness(phen->size()) - global_conflicts(phen);
    return fitness;
}

unsigned int local_conflicts(const basic_phenotype* phenotype)
{
    std::vector<pair> discovered;
    unsigned int conflicts = 0;
    for(std::size_t i = 0; i < phenotype->size()-1; ++i)
    {
        pair p((*phenotype)[i], (*phenotype)[i+1]);
        if(std::find(discovered.begin(), discovered.end(), p) != discovered.end())
        {
            ++conflicts;
        }
        else
        {
            discovered.push_back(p);
        }
    }
    return conflicts;
}

unsigned int global_conflicts(const basic_phenotype* phenotype)
{
    std::vector<triple> discovered;
    unsigned int conflicts = 0;
    for(std::size_t i = 0; i < phenotype->size()-1; ++i)
    {
        for(std::size_t j = i+1; j < phenotype->size(); ++j)
        {
            triple t((*phenotype)[i], (*phenotype)[j], j-i-1);
            if(std::find(discovered.begin(), discovered.end(), t) != discovered.end())
            {
                ++conflicts;
            }
            else
            {
                discovered.push_back(t);
            }
        }
    }
    return conflicts;
}

}
