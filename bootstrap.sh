#!/bin/bash

#autoscan
##mv configure.ac configure.in

aclocal
autoheader
autoconf
libtoolize --automake --copy --force #--debug
automake --add-missing
