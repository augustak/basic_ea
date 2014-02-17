#include "basic_phenotype.hpp"

namespace ea
{

basic_phenotype::basic_phenotype(const std::vector<unsigned int>& data) :
    phenome_(data)
{
}

inline basic_phenotype::iterator basic_phenotype::begin()
{
    return phenome_.begin();
}

inline basic_phenotype::const_iterator basic_phenotype::begin() const
{
    return phenome_.begin();
}

inline basic_phenotype::iterator basic_phenotype::end()
{
    return phenome_.end();
}

inline basic_phenotype::const_iterator basic_phenotype::end() const
{
    return phenome_.end();
}

}
