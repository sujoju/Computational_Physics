#!/bin/sh

file=$1

cat $file | sed -e 's,-,\ ,g'
