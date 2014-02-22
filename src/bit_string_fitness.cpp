#include "bit_string_fitness.hpp"

namespace ea
{

int bit_string_fitness::operator()(const basic_phenotype* phen) const
{
    int sum = 0;
    for(std::size_t i = 0; i < phen->size(); ++i)
    {
        if((*phen)[i] == BIT_STRING[i]) ++sum;
    }
    return sum;
}

}
