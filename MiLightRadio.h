/*
 * MiLightRadio.h
 *
 *  Created on: 29 May 2015
 *      Author: henryk
 */

#ifdef ARDUINO
#include "Arduino.h"
#else
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#endif

#include "AbstractPL1167.h"

#ifndef MILIGHTRADIO_H_
#define MILIGHTRADIO_H_

class MiLightRadio
{
public:
    MiLightRadio(AbstractPL1167 &pl1167);
    int begin(uint8_t CHANNELS[], uint16_t syncword_one = 0x147A, uint16_t syncword_two = 0x258B, int max_length = 8);
    bool available(uint8_t CHANNELS[]);
    int read(uint8_t frame[], size_t &frame_length);
    int dupesReceived();
    int write(uint8_t frame[], size_t frame_length, uint8_t CHANNELS[], const size_t NUM_CHANNELS);
    int resend(uint8_t CHANNELS[], const size_t NUM_CHANNELS);

private:
    AbstractPL1167 &_pl1167;
    uint32_t _prev_packet_id;

    uint8_t _packet[10], _out_packet[10];
    bool _waiting;
    int _dupes_received;
};

#endif /* MILIGHTRADIO_H_ */
