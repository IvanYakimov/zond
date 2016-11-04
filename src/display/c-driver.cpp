// Copyright 2016 Ivan Yakimov
// Licensed under the Apache License, Version 2.0
// e-mail: ivan.yakimov.research@yandex.ru

#include "c-driver.hpp"

extern "C" {
  void alloca_handler(long* pointer, char* type_specifier) {
    cpp__alloca_handler(pointer, type_specifier);
  }

  void return_handler() {
    cpp__return_handler();
  }
  
  void call_handler() {
    cpp__call_handler();
  }
  
  void block_handler() {
    cpp__block_handler();
  }
}

using namespace engine;

void cpp__alloca_handler(long *pointer, char* type_specifier) {
  Engine::Alloca(pointer, std::string(type_specifier));
}

void cpp__return_handler() {
  Engine::Return();
}

void cpp__call_handler() {
  Engine::Call();
}

void cpp__block_handler() {
  Engine::BlockEnd();
}
