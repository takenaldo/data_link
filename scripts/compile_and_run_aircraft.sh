g++ Aircraft.cpp AircraftReceiver.cpp MockDownlinkSender.cpp MockUplinkReceiver.cpp DataLinkMessage.cpp LogonRequest.cpp ConnectionRequest.cpp ConnectionResponse.cpp -lzmq -o ./build/Aircraft.exe

echo "=================================="
echo "'Aircraft.exe' Built Successfully"
echo "=================================="
echo ""
echo ""

echo "------------------------------    Starting to Execute ./build/Aircraft.exe    ------------------------------"
./build/Aircraft.exe
