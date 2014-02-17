#include "basic_individual.hpp"

namespace ea
{

basic_individual::basic_individual(basic_genotype* gen, basic_phenotype* phen) :
    genotype_(gen), phenotype_(phen)
{}

basic_individual::~basic_individual()
{
    delete genotype_;
    delete phenotype_;
}

std::string basic_individual::info() const
{
    std::stringstream ret;
    ret << "phenotype: ";
    for(std::size_t i = 0; i < phenotype_->size(); ++i)
    {
        ret << "\t" << (*phenotype_)[i];
    }
    ret << "\t\tgenotype: ";
    for(std::size_t i = 0; i < genotype_->size(); ++i)
    {
        ret << (*genotype_)[i];
        if(i%8==7) ret << " ";
    }
    return ret.str();
}

void free_individuals(std::vector<basic_individual*>& individuals)
{
    for(std::size_t i = 0; i < individuals.size(); ++i)
    {
        delete individuals[i];
    }
    individuals.clear();
}

void print_individuals(const std::vector<basic_individual*>& individuals)
{
    for(std::size_t i = 0; i < individuals.size(); ++i)
    {
        std::cout << individuals[i]->info() << std::endl;
    }
}

}
