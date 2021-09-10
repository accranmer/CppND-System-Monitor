#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"
#include "system.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid_(pid) {};

// TODO: Return this process's ID
int Process::Pid() { 
  return pid_;
}

long int Process::UpTime() { 
  return LinuxParser::UpTime(pid_);
}

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { 
  long total_time = LinuxParser::ActiveJiffies(pid_);
  long starttime = LinuxParser::UpTime(pid_);
  long uptime = LinuxParser::UpTime();
  cpuUtil_ = (float) (100*(float)total_time / (float)(uptime - starttime)); 
  return cpuUtil_;
  
}

string Process::Command() { 
return LinuxParser::Command(pid_);
}

string Process::Ram() { 
  return LinuxParser::Ram(pid_); 
}

string Process::User() { 
  return LinuxParser::User(pid_);
}

bool Process::operator<(Process const& a) const { 
  return a.cpuUtil_ < cpuUtil_ ? true : false;
                                                                
}
