#include "one_max_development.hpp"

#include <cmath>
#include <vector>
#include <iostream>

namespace ea
{

basic_phenotype* one_max_development::operator()(const basic_genotype* gen) const
{
    std::vector<unsigned int> data;
    unsigned int sum = 0;
    for(std::size_t i = 0; i < gen->size(); ++i)
    {
        if((*gen)[i] == 1) ++sum;
    }
    data.push_back(sum);
    return new basic_phenotype(data);
}

}
