#include "one_max_ideal.hpp"

#include <cmath>

namespace ea
{

bool one_max_ideal::operator()(basic_individual* individual) const
{
    std::size_t num_bits = individual->genotype()->size();
    if(individual->fitness() < int(num_bits)) return false;

    return true;
}

}
