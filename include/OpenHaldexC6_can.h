#pragma once

#include <OpenHaldexC6_defs.h>

void broadcastOpenHaldex(void *arg);
void parseCAN_chs(void *arg);
void parseCAN_hdx(void *arg);
void setupCAN();
bool haldex_can_send(const twai_message_t& msg, TickType_t timeout_ticks);
void canBusRecovery();