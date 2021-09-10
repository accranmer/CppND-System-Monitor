#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
 int PrevIdle{0};
  int PrevNonIdle{0};
  int PrevTotal{0};
  int Idle{0};
  int NonIdle{0};
  int Total{0};int PrevIdle{0};
  int PrevNonIdle{0};
  int PrevTotal{0};
  int Idle{0};
  int NonIdle{0};
  int Total{0};
};

#endif
