#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

DEFAULT_HEADER_PATH=$DIR/default_values.h

MEAN_DEFAULT='"0"'
STD_DEFAULT='"1"'
LIMIT_DEFAULT='"10"'

while [[ $# -gt 0 ]]
do
    key="$1"

    case $key in
	-u|--mean-default)
	    MEAN_DEFAULT="\"$2\""
	    shift
	    shift
	    ;;
	-d|--std-default)
	    STD_DEFAULT="\"$2\""
	    shift
	    shift
	    ;;
	-l|--limit-default)
	    LIMIT_DEFAULT="\"$2\""
	    shift
	    shift
	    ;;
    esac
done

rm -f $DEFAULT_HEADER_PATH

echo "const std::string MEAN_DEFAULT=$MEAN_DEFAULT;" >> $DEFAULT_HEADER_PATH
echo "const std::string STD_DEFAULT=$STD_DEFAULT;" >> $DEFAULT_HEADER_PATH
echo "const std::string LIMIT_DEFAULT=$LIMIT_DEFAULT;" >> $DEFAULT_HEADER_PATH

g++ -o dgauss_gen -O3 main.cpp

