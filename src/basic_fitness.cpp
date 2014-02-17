#include "basic_fitness.hpp"

namespace ea
{

int basic_fitness::operator()(const basic_phenotype* phen) const
{
    int sum = 0;
    for(std::size_t i = 0; i < phen->size(); ++i)
    {
        sum += (*phen)[i];
    }
    return sum;
}

}
