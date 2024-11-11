g++ Aircraft.cpp MockDownlinkSender.cpp MockUplinkReceiver.cpp ConnectionResponse.cpp AircraftReceiver.cpp \
DataLinkMessage.cpp  \
./DownLinkMessages/RequestLevel.cpp \
./DownLinkMessages/RequestBlockLevel.cpp \
./DownLinkMessages/RequestCruiseLevel.cpp \
./DownLinkMessages/RequestClimbLevel.cpp \
./DownLinkMessages/RequestDescentLevel.cpp \
./DownLinkMessages/RequestLevelAtPosition.cpp \
./DownLinkMessage.h \
./DownLinkMessages/PermittedResponseGroup.cpp \
-lzmq -o ./build/Aircraft.exe



echo "=================================="
echo "'Aircraft.exe' Built Successfully"
echo "=================================="
echo ""
echo ""

echo "------------------------------    Starting to Execute ./build/Aircraft.exe    ------------------------------"
./build/Aircraft.exe
