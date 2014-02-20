#include "surprising_sequences_development.hpp"

#include <cmath>
#include <vector>
#include <iostream>

namespace ea
{

surprising_sequences_development::surprising_sequences_development(std::size_t num_symbols) :
    basic_development(num_symbols-1)
{
}

basic_phenotype* surprising_sequences_development::operator()(const basic_genotype* gen) const
{
    std::vector<unsigned int> data;
    for(std::size_t i = 0; i < gen->size()/BIT_CHUNK_SIZE; ++i)
    {
        unsigned int pheno = 0;
        for(std::size_t j = i*BIT_CHUNK_SIZE; j < (i+1)*BIT_CHUNK_SIZE; ++j)
        {
            if((*gen)[j] == 1) ++pheno;
        }
        data.push_back(pheno);
    }
    return new basic_phenotype(data);
}

}
