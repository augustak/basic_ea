% plot ea data
function [] = plot_ea_data(filename)
    file = csvread(filename)
    plot(file)
    legend('avg','std','max')
    title(filename)
    xlabel('Generation')
    ylabel('Fitness')
    outfile = strcat('jpg/', filename, '.jpg')
    print(outfile,'-djpg')
end

