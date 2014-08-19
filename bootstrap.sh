#!/bin/bash

#autoscan
##mv configure.ac configure.in
#autoheader

aclocal
autoconf
libtoolize --automake --copy --force #--debug
automake --add-missing
