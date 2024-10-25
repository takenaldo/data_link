g++ DL_RouteModificationRequests.cpp -lzmq -o ./build/DL_RouteModificationRequests.exe

echo "=================================="
echo "'DL_RouteModificationRequests.exe' Built Successfully"
echo "=================================="
echo ""

echo "------------------------------    Starting to Execute ./build/DL_RouteModificationRequests.exe    ------------------------------"
./build/DL_RouteModificationRequests.exe
