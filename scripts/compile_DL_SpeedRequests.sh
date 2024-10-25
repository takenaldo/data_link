g++ DL_SpeedRequests.cpp -lzmq -o ./build/DL_SpeedRequests.exe

echo "=================================="
echo "'DL_SpeedRequests.exe' Built Successfully"
echo "=================================="
echo ""

echo "------------------------------    Starting to Execute ./build/DL_SpeedRequests.exe    ------------------------------"
./build/DL_SpeedRequests.exe
