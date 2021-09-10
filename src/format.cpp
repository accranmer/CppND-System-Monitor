#include <string>

#include "format.h"

using std::string;

// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) { 
  string hours, minutes, secs;
    
  int h = seconds / (60*60);
  int m = (seconds % (60*60)) / 60;
  int s = (seconds % (60*60)) % 60;
  if (h > 9){
    hours = std::to_string(h);
  }
  else{
    hours = "0" + std::to_string(h);
  }
  if (m > 9){
    minutes = std::to_string(m);
  }
  else{
    minutes = "0" + std::to_string(m);
  }
  if (s > 9){
    secs = std::to_string(s);
  }
  else{
    secs = "0" + std::to_string(s);
  }
  return hours + ":" + minutes + ":" + secs;                                         
}
