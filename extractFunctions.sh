#!/bin/sh

nm -gD build/libtestLib.so | grep " T " | cut -c 20- > build/libtestLib.txt