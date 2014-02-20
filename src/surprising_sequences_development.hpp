#ifndef SURPRISING_SEQUENCES_DEVELOPMENT_HPP
#define SURPRISING_SEQUENCES_DEVELOPMENT_HPP

#include "basic_genotype.hpp"
#include "basic_phenotype.hpp"
#include "basic_development.hpp"

namespace ea
{

class surprising_sequences_development : public basic_development
{
    public:
        surprising_sequences_development(std::size_t);
        virtual ~surprising_sequences_development() {}
        virtual basic_phenotype* operator()(const basic_genotype*) const;
};

}

#endif
