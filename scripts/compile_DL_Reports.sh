g++ DL_Reports.cpp -lzmq -o ./build/DL_Reports.exe

echo "=================================="
echo "'DL_Reports.exe' Built Successfully"
echo "=================================="
echo ""

echo "------------------------------    Starting to Execute ./build/DL_Reports.exe    ------------------------------"
./build/DL_Reports.exe
