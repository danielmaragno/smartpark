#!/bin/bash
for i in `ps aux | grep "python3 \.\/gateway" | grep -v "grep" | awk '{print $2}'`; do kill -9 $i; done
