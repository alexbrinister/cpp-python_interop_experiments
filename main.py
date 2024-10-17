#!/usr/bin/env python

import ctypes
from ctypes import cdll
lib = cdll.LoadLibrary('./build/libcpp-python-interop.so')

size = 5

RandomUintGenHandle = ctypes.POINTER(ctypes.c_char)

lib.RandomUintGenerator_new.restype = RandomUintGenHandle
lib.RandomUintGenerator_delete.argtypes = [RandomUintGenHandle]
lib.RandomUintGenerator_get.argtypes = [RandomUintGenHandle]

randomUintGenPtr = lib.RandomUintGenerator_new()

RandomUintGeneratorGet = lib.RandomUintGenerator_get
RandomUintGeneratorDelete = lib.RandomUintGenerator_delete

for i in range(0, 5):
    print(RandomUintGeneratorGet(randomUintGenPtr))

RandomUintGeneratorDelete(randomUintGenPtr)
