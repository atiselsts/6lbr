/*
 * Copyright (c) 2010, Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef PROJECT_CONF_H_
#define PROJECT_CONF_H_

/* Set to 1 if the SLIP packets contains a CRC8 checksum */
#ifndef SLIP_CONF_CRC_ON
#define SLIP_CONF_CRC_ON 0
#endif

/* Set to 1 if the BR sends packet attributes along with the packet to the SLIP Radio */
#ifndef DESERIALIZE_ATTRIBUTES
#define DESERIALIZE_ATTRIBUTES 1
#endif

/* Set to 1 if the SLIP Radio sends packet attributes along with the packet to the BR */
#ifndef SERIALIZE_ATTRIBUTES
#define SERIALIZE_ATTRIBUTES 0
#endif

/* Set to 1 if the packets contains IP packets and not 802.15.4 packets */
#ifndef SLIP_RADIO_IP
#define SLIP_RADIO_IP 0
#endif

#undef QUEUEBUF_CONF_NUM
#define QUEUEBUF_CONF_NUM       8

#define SLIP_CONF_BUF_NB        5

#undef UIP_CONF_ROUTER
#define UIP_CONF_ROUTER                 0

#undef UIP_CONF_DS6_NBR_NBU
#define UIP_CONF_DS6_NBR_NBU     0

#undef UIP_CONF_MAX_ROUTES
#define UIP_CONF_MAX_ROUTES   0

#undef NBR_TABLE_CONF_MAX_NEIGHBORS
#define NBR_TABLE_CONF_MAX_NEIGHBORS 0

#undef UIP_CONF_DS6_DEFRT_NBU
#define UIP_CONF_DS6_DEFRT_NBU  0

#undef UIP_CONF_DS6_PREFIX_NBU
#define UIP_CONF_DS6_PREFIX_NBU 0

#undef UIP_CONF_DS6_ADDR_NBU
#define UIP_CONF_DS6_ADDR_NBU   0

#define CMD_CONF_OUTPUT slip_radio_cmd_output

/* Default CMD handlers if the target did not specify them */
#ifndef CMD_CONF_HANDLERS
#define CMD_CONF_HANDLERS slip_radio_cmd_handler
#endif

#define NETSTACK_CONF_FRAMER no_framer

#if SLIP_RADIO_IP

#undef NBR_TABLE_CONF_MAX_NEIGHBORS
#define NBR_TABLE_CONF_MAX_NEIGHBORS 12

#undef NETSTACK_CONF_NETWORK
#define NETSTACK_CONF_NETWORK sicslowpan_driver

#if WITH_TSCH

#undef NETSTACK_CONF_MAC
#define NETSTACK_CONF_MAC     tschmac_driver

#undef NETSTACK_CONF_FRAMER
#define NETSTACK_CONF_FRAMER  framer_802154

#undef FRAME802154_CONF_VERSION
#define FRAME802154_CONF_VERSION FRAME802154_IEEE802154_2015

/* Logging */
#define LOG_CONF_LEVEL_RPL                         LOG_LEVEL_WARN
#define LOG_CONF_LEVEL_TCPIP                       LOG_LEVEL_WARN
#define LOG_CONF_LEVEL_IPV6                        LOG_LEVEL_WARN
#define LOG_CONF_LEVEL_6LOWPAN                     LOG_LEVEL_DBG
#define LOG_CONF_LEVEL_MAC                         LOG_LEVEL_DBG
#define LOG_CONF_LEVEL_FRAMER                      LOG_LEVEL_DBG
#define TSCH_LOG_CONF_PER_SLOT                     1

/* Do not start TSCH at init, wait for NETSTACK_MAC.on() */
#undef TSCH_CONF_AUTOSTART
#define TSCH_CONF_AUTOSTART 0

/* 6TiSCH minimal schedule length.
 * Larger values result in less frequent active slots: reduces capacity and saves energy. */
#undef TSCH_SCHEDULE_CONF_DEFAULT_LENGTH
#define TSCH_SCHEDULE_CONF_DEFAULT_LENGTH 3

#define TSCH_CONF_DEFAULT_HOPPING_SEQUENCE TSCH_HOPPING_SEQUENCE_1_1
#define TSCH_CONF_RX_WAIT 1700

#endif /* WITH_TSCH */

#else /* SLIP_RADIO_IP */

/* Configuration for the slipradio/network driver. */
#define NETSTACK_CONF_NETWORK slipnet_driver

/* Override the default debug output to prefix it with SLIP_END symbols */
#define DBG_OUTPUT_IS_APP_DEFINED 1

#endif /* SLIP_RADIO_IP */

/*---------------------------------------------------------------------------*/
#endif /* PROJECT_CONF_H_ */
