#include <project.h>

// Define unit address for nunchuck
#define nunchuckUnitAddress 0x52

// Function sends handshake to nunchuck to initiate communication
// Returns 0 if an error occurs
int NunchuckSendHandshake();

// Function sends 0x00 to request data from nunchuck
// Returns  0 if an error occurs
int NunchuckRequestData();

// Function reads data into buffer
// Returns 0 if an error occurs
int NunchuckReadData(uint8* buffer);
