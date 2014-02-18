#include "one_max_ideal.hpp"

#include <cmath>

namespace ea
{

bool one_max_ideal::operator()(basic_individual* individual) const
{
    std::size_t num_bits = individual->genotype()->size();
    if(individual->fitness() < int(num_bits)) return false;
    /*
    const std::size_t BIT_CHUNK_SIZE = 8;
    for(std::size_t i = 0; i < num_bits/BIT_CHUNK_SIZE; ++i)
    {
        if((*individual->phenotype())[i] < 255) return false;
    }
    if(num_bits%BIT_CHUNK_SIZE != 0)
    {
        unsigned int pheno = 0;
        for(std::size_t i = 0; i < num_bits%BIT_CHUNK_SIZE; ++i)
        {
            pheno += std::pow(2, i);
        }
        if((*individual->phenotype())[num_bits/BIT_CHUNK_SIZE] < pheno)
        {
            return false;
        }
    }
    */
    return true;
}

}
