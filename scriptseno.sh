#!/bin/bash

for i in $(seq 1 5)
do
	./seno $i seno$i.txt
done
