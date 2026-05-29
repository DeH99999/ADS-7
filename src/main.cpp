// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
  const int c = 1221;
  std::srand(static_cast<unsigned>(std::time(nullptr)));
  std::ofstream fOff("all_off.csv");
  std::ofstream fOn("all_on.csv");
  std::ofstream fRand("random.csv");
  fOff << "n,ops\n";
  fOn << "n,ops\n";
  fRand << "n,ops\n";
  for (int n = 1; n <= c; ++n) {
    {
      Train train;
      for (int i = 0; i < n; ++i) train.addCar(false);
      train.getLength();
      fOff << n << "," << train.getOpCount() << "\n";
    }
    {
      Train train;
      for (int i = 0; i < n; ++i) train.addCar(true);
      train.getLength();
      fOn << n << "," << train.getOpCount() << "\n";
    }
    {
      Train train;
      for (int i = 0; i < n; ++i) train.addCar(std::rand() % 2);
      train.getLength();
      fRand << n << "," << train.getOpCount() << "\n";
    }
  }
  fOff.close();
  fOn.close();
  fRand.close();
  return 0;
}
