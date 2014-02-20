#include <iostream>
#include <initializer_list>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <sstream>
#include <cstring>

typedef std::stringstream sstream;

#include "basic_phenotype.hpp"
#include "basic_genotype.hpp"
#include "basic_development.hpp"
#include "one_max_development.hpp"
#include "surprising_sequences_development.hpp"
#include "basic_individual.hpp"
#include "basic_fitness.hpp"
#include "surprising_sequences_fitness.hpp"
#include "basic_adult_selection.hpp"
#include "full_generational_replacement.hpp"
#include "over_production.hpp"
#include "generational_mixing.hpp"
#include "basic_parent_selection.hpp"
#include "fitness_proportionate.hpp"
#include "sigma_scaling.hpp"
#include "boltzmann_scaling.hpp"
#include "tournament_selection.hpp"
#include "basic_genetic_operator.hpp"
#include "basic_ideal_individual.hpp"
#include "one_max_ideal.hpp"
#include "surprising_sequences_ideal.hpp"
#include "evolutionary_algorithm.hpp"
#include "csv_writer.hpp"


using namespace ea;

void usage_error()
{

}

int problem_t = 0; // 0 = one_max, 1 = surprising
unsigned int runs = 1; // number of runs
unsigned int generations = 50; // number of generations
bool inc_diff = false; // whether to run once or increase problem difficulty incrementally
int dev_tt = 0; // 0 = basic, 1 = one_max, 2 = surprising
int fit_t = 0; // 0 = basic, 1 = surprising
int adult_t = 0; // 0 = basic, 1 = full replace, 2 = over prod, 3 = gen mix
int parent_t = 0; // 0 = basic, 1 = tournament, 2 = fitness prop, 3 = sigma, 4 = boltzmann
//int gen_t = 0; // 0 = basic
int ideal_t = 0; // 0 = basic, 1 = one max, 2 = surprising
unsigned int bits = 8; // number of bits in genome
//unsigned int runs = 1; // number of runs
unsigned int pop_size = 20; // population size
unsigned int symbols = 5; // number of symbols in surprising
//unsigned int generations = 50; // number of generations
double mut_rate = 0.5; // mutation rate
double cross_rate = 0.5; // crossover rate
double init_temp = 100.0; // init temp for boltzmann
double d_temp = 2.5; // delta temp for boltzmann
bool dflag = false; // debug flag
std::string out = "null"; // debug output file
int ss_type = 0; // 0 = local, 1 = global
double child_m = 1.0; // children multiplier

void options(int argc, char** argv)
{
    for(int i = 1; i < argc; ++i)
    {
        if(!strcmp(argv[i], "--one_max") || !strcmp(argv[i], "--om"))
        {
            problem_t = 0;
            dev_tt = 1;
            fit_t = 0;
            ideal_t = 1;
        }
        else if(!strcmp(argv[i], "--surprising_sequences") || !strcmp(argv[i], "--ss"))
        {
            problem_t = 1;
            dev_tt = 2;
            fit_t = 1;
            ideal_t = 2;
        }
        else if(!strcmp(argv[i], "--local"))
        {
            ss_type = 0;
        }
        else if(!strcmp(argv[i], "--global"))
        {
            ss_type = 1;
        }
        else if(!strcmp(argv[i], "--debug") || !strcmp(argv[i], "--d"))
        {
            if(i+1 >= argc)
            {
                usage_error();
                exit(0);
            }
            sstream ss(argv[i+1]);
            ss >> out;
            dflag = true;
        }
        else if(!strcmp(argv[i], "--pop_size") || !strcmp(argv[i], "--popsize") || !strcmp(argv[i], "--ps"))
        {
            if(i+1 >= argc) 
            {
                usage_error();
                exit(0);
            }
            sstream ss(argv[i+1]);
            ss >> pop_size;
            ++i;
        }
        else if(!strcmp(argv[i], "--child"))
        {
            if(i+1 >= argc) 
            {
                usage_error();
                exit(0);
            }
            sstream ss(argv[i+1]);
            ss >> child_m;
            ++i;

        }
        else if(!strcmp(argv[i], "--runs"))
        {
            if(i+1 >= argc)
            {
                usage_error();
                exit(0);
            }
            sstream ss(argv[i+1]);
            ss >> runs;
            ++i;
        }
        else if(!strcmp(argv[i], "--symbols"))
        {
            if(i+1 >= argc)
            {
                usage_error();
                exit(0);
            }
            sstream ss(argv[i+1]);
            ss >> symbols;
            ++i;
        }
        else if(!strcmp(argv[i], "--generations") || !strcmp(argv[i], "--gen"))
        {
            if(i+1 >= argc)
            {
                usage_error();
                exit(0);
            }
            sstream ss(argv[i+1]);
            ss >> generations;
            ++i;
        }
        else if(!strcmp(argv[i], "--bits"))
        {
            if(i+1 >= argc)
            {
                usage_error();
                exit(0);
            }
            sstream ss(argv[i+1]);
            ss >> bits;
            ++i;
        }
        else if(!strcmp(argv[i], "--mut") || !strcmp(argv[i], "--mutrate") || !strcmp(argv[i], "--mr"))
        {
            if(i+1 >= argc)
            {
                usage_error();
                exit(0);
            }
            sstream ss(argv[i+1]);
            ss >> mut_rate;
            ++i;
        }
        else if(!strcmp(argv[i], "--cross") || !strcmp(argv[i], "--crossrate") || !strcmp(argv[i], "--cr"))
        {
            if(i+1 >= argc)
            {
                usage_error();
                exit(0);
            }
            sstream ss(argv[i+1]);
            ss >> cross_rate;
            ++i;
        }
        else if(!strcmp(argv[i], "--fullreplace"))
        {
            adult_t = 1;
        }
        else if(!strcmp(argv[i], "--overproduction"))
        {
            adult_t = 2;
        }
        else if(!strcmp(argv[i], "--mix"))
        {
            adult_t = 3;
        }
        else if(!strcmp(argv[i], "--tournament"))
        {
            parent_t = 1;
        }
        else if(!strcmp(argv[i], "--fitnessprop"))
        {
            parent_t = 2;
        }
        else if(!strcmp(argv[i], "--sigma"))
        {
            parent_t = 3;
        }
        else if(!strcmp(argv[i], "--boltzmann"))
        {
            if(i+2 >= argc)
            {
                usage_error();
                exit(0);
            }
            sstream ss0(argv[i+1]);
            sstream ss1(argv[i+2]);
            ss0 >> init_temp;
            ss1 >> d_temp;
            ++i;
            ++i;
            parent_t = 4;
        }
        else if(!strcmp(argv[i], "--incdiff"))
        {
            inc_diff = true;
        }
    }
}

evolutionary_algorithm* create_ea()
{
    basic_development* bd;
    basic_fitness* bf;
    basic_adult_selection* bas;
    basic_parent_selection* bps;
    basic_genetic_operator* bgo;
    basic_ideal_individual* bii;
    switch(dev_tt)
    {
        case 0: bd = new basic_development(DEFAULT_BIT_CHUNK_SIZE); break;
        case 1: bd = new one_max_development(DEFAULT_BIT_CHUNK_SIZE); break;
        case 2: bd = new surprising_sequences_development(symbols); break;
        default: std::cerr << "bad input" << std::endl; break;
    }
    switch(fit_t)
    {
        case 0: bf = new basic_fitness(); break;
        case 1: 
        {
            if(ss_type == 0) bf = new surprising_sequences_local_fitness();
            else if(ss_type == 1) bf = new surprising_sequences_global_fitness();
        } break;
        default: std::cerr << "bad input" << std::endl; break;
    }
    switch(adult_t)
    {
        case 0: bas = new basic_adult_selection(); break;
        case 1: bas = new full_generational_replacement(); break;
        case 2: bas = new over_production(); break;
        case 3: bas = new generational_mixing(); break;
        default: std::cerr << "bad input" << std::endl; break;
    }
    switch(parent_t)
    {
        case 0: bps = new basic_parent_selection(); break;
        case 1: bps = new tournament_selection(); break;
        case 2: bps = new fitness_proportionate(); break;
        case 3: bps = new sigma_scaling(); break;
        case 4: bps = new boltzmann_scaling(init_temp, d_temp); break;
        default: std::cerr << "bad input" << std::endl; break;
    }
    bgo = new basic_genetic_operator();
    switch(ideal_t)
    {
        case 0: bii = new basic_ideal_individual(); break;
        case 1: bii = new one_max_ideal(); break;
        case 2:
        {
            if(ss_type == 0) bii = new surprising_sequences_local_ideal();
            else if(ss_type == 1) bii = new surprising_sequences_global_ideal();
        } break;
        default: std::cerr << "bad input" << std::endl; break;
    }
    genotype_vector children;
    for(std::size_t i = 0; i < pop_size; ++i)
    {
        children.push_back(random_basic_genotype(bits));
    }
    evolutionary_algorithm* ea = new evolutionary_algorithm(bd, bf, bas, bps, bgo, bii, pop_size, mut_rate, cross_rate, child_m, out, dflag);
    ea->init_children(children);
    return ea;
}

std::string info_ss(basic_individual* ind, unsigned int bit_chunk)
{
    sstream ss;
    ss << "phenotype:\t";
    for(std::size_t j = 0; j < ind->phenotype()->size(); ++j)
    {
        ss << " " << char((*ind->phenotype())[j] + 65);
    }
    ss << "\tgenotype:";
    for(std::size_t j = 0; j < ind->genotype()->size(); ++j)
    {
        if(j % bit_chunk == 0) ss << " ";
        ss << (*ind->genotype())[j];
    }
    return ss.str();
}

std::string info_om(basic_individual* ind, unsigned int bit_chunk)
{
    sstream ss;
    ss << "phenotype:\t";
    for(std::size_t j = 0; j < ind->phenotype()->size(); ++j)
    {
        ss << " " << (*ind->phenotype())[j];
    }
    ss << "\tgenotype:";
    for(std::size_t j = 0; j < ind->genotype()->size(); ++j)
    {
        if(j % bit_chunk == 0) ss << " ";
        ss << (*ind->genotype())[j];
    }
    return ss.str();
}


int main(int argc, char** argv)
{

    std::srand(std::time(0));

    options(argc, argv);
    if(!inc_diff)
    {
        evolutionary_algorithm* ea = create_ea();
        int success = 0;
        bool found = false;
        for(std::size_t n = 0; n < runs; ++n)
        {
            for(std::size_t i = 0; i < generations; ++i)
            {
                basic_individual* ind = ea->simulate_generation();
                if(ind)
                {
                    found = true;
                    if(problem_t == 0) std::cout << info_om(ind, DEFAULT_BIT_CHUNK_SIZE) << std::endl;
                    else if(problem_t == 1) std::cout << info_ss(ind, symbols-1) << std::endl;
                    ++success;
                    break;
                }
            }
            if(found) break;
        }
        std::cout << "accuracy: " << success << "/" << runs << " = " << float(success)/float(runs) << std::endl;
        delete ea;
    }
    else
    {
        bool found;
        evolutionary_algorithm* ea;
        int count = 0;
        std::vector<std::string> results;
        std::ofstream file("results.txt");
        do
        {
            found = false;
            file << "*********************** SEQUENCE LENGTH " << count+1 << "******************************" << std::endl;
            int success = 0;
            for(std::size_t n = 0; n < runs; ++n)
            {
                ea = create_ea();
                basic_individual* ind = 0;
                for(std::size_t i = 0; i < generations; ++i)
                {
                    ind = ea->simulate_generation();
                    if(ind)
                    {
                        if(problem_t == 0) file << info_om(ind, DEFAULT_BIT_CHUNK_SIZE) << std::endl;
                        else if(problem_t == 1) file << info_ss(ind, symbols-1) << std::endl;
                        found = true;
                        ++success;
                        break;
                    }
                }
                delete ea;
                if(found) break;
            }
            sstream ss;
            ss << "stage: " << count << " accuracy: " << float(success)/float(runs);
            std::cout << ss.str() << std::endl;
            results.push_back(ss.str());
            ++count;
            if(problem_t == 1) bits += (symbols-1);
            else if(problem_t == 0) ++bits;
        } 
        while(found);
        file.close();

        for(std::size_t i = 0; i < results.size(); ++i)
        {
            std::cout << results[i] << std::endl;
        }
    }
    return 0;
}
