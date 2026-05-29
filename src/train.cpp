// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};
  if (!first) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  if (!first) return 0;
  if (first->next == first) return 1;
  first->light = true;
  int len = 1;
  while (true) {
    Car* cur = first;
    for (int i = 0; i < len; ++i) {
      cur = cur->next;
      ++countOp;
      cur->light = false;
    }
    for (int i = 0; i < len; ++i) {
      cur = cur->prev;
      ++countOp;
    }
    if (!first->light) {
      return len;
    }
    ++len;
    first->light = true;
  }
}

int Train::getOpCount() {
  return countOp;
}
