#include "processor.h"
#include "linux_parser.h"

float Processor::Utilization() { 
  
  std::vector<std::string> current = LinuxParser::CpuUtilization();
  int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
  int totald, idled;
  
  user = stoi(current[0]);
  nice = stoi(current[1]);
  system = stoi(current[2]);
  idle = stoi(current[3]);
  iowait = stoi(current[4]);
  irq = stoi(current[5]);
  softirq = stoi(current[6]);
  steal = stoi(current[7]);
  guest = stoi(current[8]);
  guest_nice = stoi(current[9]);
  
  PrevIdle = Idle;
  PrevNonIdle = NonIdle;
  PrevTotal = Total;
  
  Idle = idle + iowait;
  NonIdle = user + nice + system + irq + softirq + steal;
  Total = Idle + NonIdle;
  
  //Differentiate
  totald = Total - PrevTotal;
  idled = Idle - PrevIdle;
  
  if (totald == 0){
  return 0.0;
  }
  else{
    return ((float)(totald - idled))/((float)totald);
  }
                               
}
