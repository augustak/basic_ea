#include "surprising_sequences_development.hpp"

#include <cmath>
#include <vector>
#include <iostream>

namespace ea
{

surprising_sequences_development::surprising_sequences_development(unsigned int symbols) :
    basic_development(SS_BIT_CHUNK), SYMBOLS(symbols)
{
}

basic_phenotype* surprising_sequences_development::operator()(const basic_genotype* gen) const
{
    std::vector<unsigned int> data;
    for(std::size_t i = 0; i < gen->size()/BIT_CHUNK_SIZE; ++i)
    {
        unsigned int pheno = 0;
        for(std::size_t j = i*BIT_CHUNK_SIZE, k = 0; j < (i+1)*BIT_CHUNK_SIZE; ++j, ++k)
        {
            if((*gen)[j] == 1) pheno += std::pow(2, k);
        }
        unsigned int chunk = std::pow(2, SS_BIT_CHUNK);
        chunk = chunk / SYMBOLS + 1;
        data.push_back(pheno/chunk);
    }
    return new basic_phenotype(data);
}

}
