#pragma once

#include <OpenHaldexC6_defs.h>

void broadcastOpenHaldex(void *arg);
void parseCAN_chs(void *arg);
void parseCAN_hdx(void *arg);
void setupCAN();
void canBusRecovery();

// Haldex-bus transmit/receive helpers. These abstract over the second CAN
// controller so the rest of the firmware is board-agnostic:
//   - OpenHaldex-C6 : internal TWAI controller 1 (twai_bus_1)
//   - LilyGo T-2CAN : MCP2515 over SPI (OH_CAN_HALDEX_MCP2515)
// Chassis-bus traffic continues to use twai_bus_0 directly on both boards.
bool haldex_can_send(const twai_message_t &msg, TickType_t timeout_ticks);
bool haldex_can_receive(twai_message_t &msg, TickType_t timeout_ticks);