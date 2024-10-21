set -x 
date
echo "Start of the script"

mkdir build
cd build
# cmake -G "MinGW Makefiles" ..
cmake  ..
make
./hello

echo "End of the script"

set +x 
