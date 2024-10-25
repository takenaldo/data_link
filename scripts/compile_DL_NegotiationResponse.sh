g++ DL_NegotiationResponse.cpp -lzmq -o ./build/DL_NegotiationResponse.exe

echo "=================================="
echo "'DL_NegotiationResponse.exe' Built Successfully"
echo "=================================="
echo ""

echo "------------------------------    Starting to Execute ./build/DL_NegotiationResponse.exe    ------------------------------"
./build/DL_NegotiationResponse.exe
