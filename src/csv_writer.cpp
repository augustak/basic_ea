#include "csv_writer.hpp"

#include <cstdarg>
#include <limits>
#include <iostream>
namespace ea
{

std::vector<std::vector<data>> csv_data;

csv_writer::csv_writer(const std::string& out) :
    out_file("csv/" + out + ".csv")
{
}

csv_writer::~csv_writer()
{
    out_file.close();
    csv_data.push_back(datas);
}

void csv_writer::write_title(std::size_t count, ...)
{
    va_list args;
    va_start(args, count);
    if(out_file.is_open())
    {
        for(std::size_t i = 0; i < count; ++i)
        {
            out_file << va_arg(args, char*);
            if(i != count-1) out_file << ",";
        }
        out_file << std::endl;
    }
    va_end(args);
}

void csv_writer::write(std::size_t count, ...)
{
    va_list args;
    va_start(args, count);
    if(out_file.is_open())
    {
        std::vector<double> vals;
        for(std::size_t i = 0; i < count; ++i)
        {
            double val = va_arg(args, double);
            out_file << val;
            vals.push_back(val);
            if(i!=count-1) out_file << ",";
        }
        datas.push_back(data(vals[0], vals[1], vals[2]));
        out_file << '\n';
    }
    va_end(args);
}

}
