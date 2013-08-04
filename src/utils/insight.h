#ifndef INSIGHT_H
#define INSIGHT_H

#include "stddefs.h"

#define INSIGHT_LEVEL 2 // 0 = nothing

// Define all of your messages here:
#define INSIGHT_TABLE(MSG, MSG_ARG, MSG_PTR, MSG_STRING) \
    MSG(NULLMSG, 255, "Should never see this!", 0, NULL) \
    MSG(INIT_INSIGHT, 2, "CodeInsight initalisation. Compilation date {0} @ {1}", 2, MSG_STRING(char) MSG_STRING(char)) \
    MSG(23LC1024_INIT, 3, "Initializing 23LC1024 chip", 0, NULL) \
    MSG(23LC1024_READ, 7, "Reading data at address {0:X} (size {1:X})", 2, MSG_ARG(UI16_t) MSG_ARG(UI16_t)) \
    MSG(23LC1024_WRITE, 7, "Writing data at address {0:X} (size {1:X})", 2, MSG_ARG(UI16_t) MSG_ARG(UI16_t)) \
    MSG(ENC28J60_READ_REG, 15, "[enc28j60] Reading {0:X} (data: {1:X})", 2, MSG_ARG(UI16_t) MSG_ARG(UI16_t)) \
    MSG(ENC28J60_WRITE_REG, 15, "[enc28j60] Writing {0:X} (data: {1:X})", 2, MSG_ARG(UI16_t) MSG_ARG(UI16_t)) \
    MSG(ENC28J60_BITSET_REG, 15, "[enc28j60] Bitset {0:X} (mask: {1:X})", 2, MSG_ARG(UI16_t) MSG_ARG(UI16_t)) \
    MSG(ENC28J60_BITCLR_REG, 15, "[enc28j60] Bitclr {0:X} (mask: {1:X})", 2, MSG_ARG(UI16_t) MSG_ARG(UI16_t)) \
    MSG(ENC28J60_RX, 13, "[enc28j60] RX packet size {0:X} from {1:X}:{2:X}:{3:X}:{4:X}:{5:X}:{6:X}", 7, MSG_ARG(UI16_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t)) \
    MSG(ENC28J60_TX, 13, "[enc28j60] TX packet size {0:X} to {1:X}:{2:X}:{3:X}:{4:X}:{5:X}:{6:X}", 7, MSG_ARG(UI16_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t)) \
    MSG(ENC624J600_SPI, 17, "[enc624j600] SPI TxRx {0:X} TX | {1:X} RX", 2, MSG_ARG(UI08_t) MSG_ARG(UI08_t)) \
    MSG(ENC624J600_REG, 16, "[enc624j600] SPI REG {0:X} = {1:X}", 2, MSG_ARG(UI08_t) MSG_ARG(UI16_t)) \
    MSG(ENC624J600_MAC, 2, "[enc624j600] MAC is {0:X}:{1:X}:{2:X}:{3:X}:{4:X}:{5:X}", 6, MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t)) \
    MSG(ENC624J600_PACKETS, 8, "[enc624j600] {0} packets in queue; link status: {1}", 2, MSG_ARG(UI08_t) MSG_ARG(bool_t)) \
    MSG(ENC624J600_RX, 13, "[enc624j600] RX packet size {0:X} from {1:X}:{2:X}:{3:X}:{4:X}:{5:X}:{6:X}", 7, MSG_ARG(UI16_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t)) \
    MSG(ENC624J600_RX_PKT, 15, "[enc624j600] RX packet @ {0:X} size {1:X} flags {2:X} | {3:X} | {4:X} | {5:X} | {6:X} | {7:X} | {8:X} | {9:X} ", 10, MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t)) \
    MSG(ENC624J600_TX, 13, "[enc624j600] TX packet size {0:X} to {1:X}:{2:X}:{3:X}:{4:X}:{5:X}:{6:X}", 7, MSG_ARG(UI16_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t)) \
    MSG(ENC624J600_TX_PKT, 15, "[enc624j600] TX packet @ {0:X} size {1:X}", 10, MSG_ARG(UI16_t) MSG_ARG(UI16_t)) \
    MSG(ARP_WHOHAS, 6, "[arp] Who has IP {0}.{1}.{2}.{3} asks {5}.{6}.{7}.{8}? {4}", 9, MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(bool_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t)) \
    MSG(ARP_ANNOUNCE, 6, "[arp] Broadcast me with IP {0}.{1}.{2}.{3}", 4, MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t)) \
    MSG(ICMP_PINGPONG, 4, "[icmp] Ping-pong!", 0, NULL) \
    MSG(IPV4_TX_REPLY, 5, "[ipv4] TX-reply packet Size {0:X} Protocol {1:X} CRC {2:X} DstIP: {3}.{4}.{5}.{6}", 7, MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t)) \
    MSG(IPV4_TX, 5, "[ipv4] TX packet Size {0:X} Protocol {1:X} CRC {2:X} DstIP: {3}.{4}.{5}.{6}", 7, MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t)) \
    MSG(IPV4_RX, 5, "[ipv4] RX packet Size {0:X} Protocol {1:X} CRC {2:X} SrcIP: {3}.{4}.{5}.{6}", 7, MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t)) \
    MSG(UDP_TX, 4, "[udp] UDP TX packet port S{0}/D{1} crc {2} size {3:X}", 4, MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t)) \
    MSG(UDP_RX, 4, "[udp] UDP RX packet port S{0}/D{1} crc {2} size {3:X}", 4, MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t)) \
    MSG(NTP_TIME, 4, "[ntp] Timestamp: {0}", 1, MSG_ARG(UI32_t)) \
    MSG(NTP_REQUEST, 4, "[ntp] Send request to ip {0}.{1}.{2}.{3}", 4, MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t)) \
    MSG(TCP_RX, 4, "[tcp] RX packet S{0}/D{1} F{2:X} Size {3} ACK {4}", 5, MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t)) \
    MSG(TCP_RX_FLAGS, 10, "[tcp] RX Flags: SYN: {0} ACK: {1} RST: {2} FIN: {3}", 4, MSG_ARG(bool_t) MSG_ARG(bool_t) MSG_ARG(bool_t) MSG_ARG(bool_t)) \
    MSG(TCP_RX_CONNECTION, 10, "[tcp] RX connection {0} state {1}", 2, MSG_ARG(UI08_t) MSG_ARG(UI08_t)) \
    MSG(TCP_RX_RESERVING, 10, "[tcp] Reserving RX connection", 0, NULL) \
    MSG(TCP_LISTEN, 6, "[tcp] Begin listening on port {0}", 1, MSG_ARG(UI16_t)) \
    MSG(TCP_PICKED, 8, "[tcp] Picked connection {0}", 1, MSG_ARG(UI08_t)) \
    MSG(TCP_MATCHED, 8, "[tcp] Matched connection type {0} at index {1}", 2, MSG_STRING() MSG_ARG(UI08_t)) \
    MSG(TCP_NO_CONNECTION, 10, "[tcp] Could not match incoming TCP packet to a connection!", 0, NULL) \
    MSG(TCP_RX_DATA, 10, "[tcp] RX Data {0} size {1}", 2, MSG_ARG(UI08_t) MSG_ARG(UI16_t)) \
    MSG(DATASIZE, 7, "Data Size: {0}", 1, MSG_ARG(UI16_t)) \
    MSG(HTTP_RX_HEADERS, 7, "[HTTP] HTTP Request {1:X} is {0}", 2, MSG_STRING() MSG_ARG(UI16_t)) \
    MSG(TCP_TX, 4, "[tcp] TX packet to {0}.{1}.{2}.{3} size {4:X} CRC {5:X} flags {6:X}", 7, MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t)) \
    MSG(TCP_TX_REPLY, 4, "[tcp] TX reply packet to {0}.{1}.{2}.{3} size {4:X} CRC {5:X} flags {6:X}", 7, MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI08_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t)) \
    MSG(RTOS_TASK_STACKUSAGE, 8, "[task] Stack usage of task {0}: {1}/{2}", 3, MSG_STRING() MSG_ARG(UI16_t) MSG_ARG(UI16_t)) \
    MSG(RTOS_CPU_USAGE, 1, "[rtos] CPU usage {0}% ran {1} {2}", 3, MSG_ARG(UI16_t) MSG_ARG(UI16_t) MSG_ARG(UI16_t)) \


    //INSIGHT(TCP_TX, connection->remoteIp[0], connection->remoteIp[1], connection->remoteIp[2], connection->remoteIp[3], dataSize, packet->tcp.crc, flags.data);

#define INSIGHT_MESSAGE(cn, lvl, sn, argCount, args) strConcat(INSIGHT_, cn),
#define INSIGHT_MESSAGE_ARGUMENT

#define INSIGHT_DICT_POINTER_WORD 0x1000
#define INSIGHT_DICT_POINTER_SIZEMASK 0x0FFF

#define INSIGHT_DICT(cn, lvl, sn, argCount, args) { strConcat(INSIGHT_, cn), lvl, argCount, { args } },
#define INSIGHT_DICT_ARGUMENT(a) sizeof(a),
#define INSIGHT_DICT_POINTER(a) INSIGHT_DICT_POINTER_WORD | sizeof(UI08_t*),
#define INSIGHT_DICT_STRING(a) 0, // INSIGHT_DICT_POINTER_WORD,

#if INSIGHT_LEVEL == 0
#define INSIGHT(code, ...)
#else
#define INSIGHT(code, ...) insight_msg(strConcat(INSIGHT_, code), F_NUM, __LINE__, ##__VA_ARGS__);
#endif

typedef enum insightMessages_e
{
    INSIGHT_TABLE(INSIGHT_MESSAGE, INSIGHT_MESSAGE_ARGUMENT, INSIGHT_MESSAGE_ARGUMENT, INSIGHT_MESSAGE_ARGUMENT)
    INSIGHT_MESSAGES
} insightMessages_t;

typedef struct insightFormats_s
{
    UI16_t msgId;
    UI16_t msgLvl;
    UI16_t msgCount;
    UI16_t msgSizes[16];
}insightFormats_t;

void insight_init();
void insight_msg(UI16_t msgCode, UI16_t fileNumber, UI16_t line, ...);

#endif