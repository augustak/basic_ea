#include "basic_adult_selection.hpp"

namespace ea
{

void basic_adult_selection::operator()(
        const std::vector<basic_individual*>& young_adults, 
        std::vector<basic_individual*>& population) const
{
    std::vector<basic_individual*>::const_iterator it;
    for(it = young_adults.begin(); it != young_adults.end(); ++it)
    {
        population.push_back(*it);
    }
}

}
