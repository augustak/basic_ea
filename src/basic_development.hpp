#ifndef BASIC_DEVELOPMENT_HPP
#define BASIC_DEVELOPMENT_HPP

#include "basic_genotype.hpp"
#include "basic_phenotype.hpp"

namespace ea
{

const std::size_t DEFAULT_BIT_CHUNK_SIZE = 8;

class basic_development
{
    public:
        basic_development(std::size_t size) : BIT_CHUNK_SIZE(size) {}
        virtual ~basic_development() {}
        virtual basic_phenotype* operator()(const basic_genotype*) const;
        std::size_t bit_chunk_size() const { return BIT_CHUNK_SIZE; }
    protected:
        const std::size_t BIT_CHUNK_SIZE;
};

}

#endif
