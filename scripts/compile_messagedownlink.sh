
g++ Messagedownlink.cpp  -lzmq -o messagedownlink.exe
echo "=================================="
echo "'Messagedownlink.exe' Built Successfully"
echo "=================================="
echo ""
echo ""

echo "------------------------------    Starting to Execute ./build/Messagedownlink.exe    ------------------------------"
./build/messagedownlink.exe
