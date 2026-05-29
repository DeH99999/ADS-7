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
  int len = 0;
  Car* cur = first;
  do {
    cur = cur->next;
    ++len;
    ++countOp;
  } while (cur != first);
  for (int i = 0; i < len; ++i) {
    cur = cur->prev;
    ++countOp;
  }
  return len;
}

int Train::getOpCount() {
  return countOp;
}
