#ifndef TOURNAMENT_SELECTION_HPP
#define TOURNAMENT_SELECTION_HPP

#include "basic_individual.hpp"
#include "basic_parent_selection.hpp"

namespace ea
{

class tournament_selection : public basic_parent_selection
{
    public:
        tournament_selection(double pool_mult, double p) : POOL_MULTIPLIER(pool_mult), P(p) {}
        virtual individual_pair_vector operator()(const individual_vector&);
    private:
        const double POOL_MULTIPLIER;
        const double P;
};

}

#endif
