#ifndef OVER_PRODUCTION_HPP
#define OVER_PRODUCTION_HPP

#include "basic_adult_selection.hpp"

namespace ea
{

class over_production : public basic_adult_selection
{
    public:
        over_production(bool elitism, std::size_t count) : basic_adult_selection(elitism, count) {}
        virtual void operator()(const std::vector<basic_individual*>&,
                std::vector<basic_individual*>&) const;
};

}

#endif
