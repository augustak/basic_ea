#include "surprising_sequences_ideal.hpp"

#include <cmath>

#include "surprising_sequences_fitness.hpp"

namespace ea
{

bool surprising_sequences_local_ideal::operator()(basic_individual* individual) const
{
    if(individual->fitness() == (int)max_local_fitness(individual->phenotype()->size())) return true;
    return false;
}

bool surprising_sequences_global_ideal::operator()(basic_individual* individual) const
{
    if(individual->fitness() == (int)max_global_fitness(individual->phenotype()->size())) return true;
    return false;
}

}
