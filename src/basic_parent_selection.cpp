#include "basic_parent_selection.hpp"

namespace ea
{

individual_pair_vector basic_parent_selection::operator()(const individual_vector& adults)
{
    individual_pair_vector parents;
    unsigned int children = 0;
    for(std::size_t i = 0; i < adults.size(); ++i)
    {
        for(std::size_t j = i; j < adults.size(); ++j)
        {
            if(i == j) continue;
            parents.push_back(std::make_pair(adults[i], adults[j]));
            ++children;
            if(children == adults.size() * children_multiplier_) break;
        }
        if(children == adults.size() * children_multiplier_) break;
    }
    return parents;
}

}
