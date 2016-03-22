/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

// Function sends handshake to nunchuck to initiate communication
// Returns 0 if an error occurs
int NunchuckSendHandshake();

// Function sends 0x00 to request data from nunchuck
// Returns  0 if an error occurs
int NunchuckRequestData();

// Function reads data into buffer
// Returns 0 if an error occurs
int NunchuckReadData(uint8* buffer);

/* [] END OF FILE */
