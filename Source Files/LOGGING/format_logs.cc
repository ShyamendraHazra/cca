#include <Logs/format_logs.h>


std::string log_formatter(std::string input) {

    std::string output;

    seconds_from_epoch rawtime;
    time(&rawtime);
    cal_time *timeinfo = localtime(&rawtime);
    char current_day_time_array[22]; 
    strftime(current_day_time_array,22,"%d-%m-%Y %H::%M::%S", timeinfo);

    std::string current_day_time_string(current_day_time_array);

    output.append(current_day_time_string);
    output.append(" [MESSAGE] ");
    output.append(input);
    output.append("\n");
    
    return output;
    
}
