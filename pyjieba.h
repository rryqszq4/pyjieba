/*
 *  Copyright (c) 2017-2018, Quan Zhao <rryqszq@gmail.com>
 */

#ifndef PYJIEBA_H
#define PYJIEBA_H

#include <Python.h>
#include "Jieba.hpp"

typedef struct 
{
    PyObject_HEAD
    cppjieba::Jieba* jieba_handler;
    cppjieba::KeywordExtractor* extractor;
} pyjieba_t;

//extern PyTypeObject pyjieba_ObjectType;

#endif