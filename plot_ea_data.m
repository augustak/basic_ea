% plot ea data
function [] = read_ea_data(filename)
    file = csvread(filename)
    plot(file)
    xlabel('generation')
    ylabel('fitness')
    outfile = strcat(filename, '.jpg')
    print(outfile,'-djpg')
end

