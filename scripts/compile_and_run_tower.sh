g++ Tower.cpp TowerSender.cpp TowerReceiver.cpp  ConnectionRequest.cpp LogonResponse.cpp DataLinkMessage.cpp -lzmq -o ./build/Tower.exe
echo "=================================="
echo "'Tower.exe' Built Successfully"
echo "=================================="
echo ""
echo ""

echo "------------------------------    Starting to Execute ./build/Tower.exe    ------------------------------"
./build/Tower.exe
