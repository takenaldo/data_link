g++ DL_LateralOffset.cpp -lzmq -o ./build/DL_LateralOffset.exe

echo "=================================="
echo "'DL_LateralOffset.exe' Built Successfully"
echo "=================================="
echo ""

echo "------------------------------    Starting to Execute ./build/DL_LateralOffset.exe    ------------------------------"
./build/DL_LateralOffset.exe
