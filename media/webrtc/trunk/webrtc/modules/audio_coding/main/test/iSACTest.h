/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef ACM_ISAC_TEST_H
#define ACM_ISAC_TEST_H

#include <string.h>

#include "ACMTest.h"
#include "Channel.h"
#include "PCMFile.h"
#include "audio_coding_module.h"
#include "utility.h"
#include "common_types.h"

#define MAX_FILE_NAME_LENGTH_BYTE 500
#define NO_OF_CLIENTS             15

namespace webrtc {

struct ACMTestISACConfig
{
    int32_t  currentRateBitPerSec;
    int16_t  currentFrameSizeMsec;
    uint32_t maxRateBitPerSec;
    int16_t  maxPayloadSizeByte;
    int16_t  encodingMode;
    uint32_t initRateBitPerSec;
    int16_t  initFrameSizeInMsec;
    bool           enforceFrameSize;
};



class ISACTest : public ACMTest
{
public:
    ISACTest(int testMode);
    ~ISACTest();

    void Perform();
private:
    int16_t Setup();
    int16_t SetupConference();
    int16_t RunConference();    


    void Run10ms();

    void EncodeDecode(
        int                testNr,
        ACMTestISACConfig& wbISACConfig,
        ACMTestISACConfig& swbISACConfig);
    
    void TestBWE(
        int testNr);

    void SwitchingSamplingRate(
        int testNr, 
        int maxSampRateChange);

    AudioCodingModule* _acmA;
    AudioCodingModule* _acmB;

    Channel* _channel_A2B;
    Channel* _channel_B2A;

    PCMFile _inFileA;
    PCMFile _inFileB;

    PCMFile _outFileA;
    PCMFile _outFileB;

    uint8_t _idISAC16kHz;
    uint8_t _idISAC32kHz;
    CodecInst _paramISAC16kHz;
    CodecInst _paramISAC32kHz;

    std::string file_name_swb_;

    ACMTestTimer _myTimer;
    int _testMode;
    
    AudioCodingModule* _defaultACM32;
    AudioCodingModule* _defaultACM16;
    
    AudioCodingModule* _confACM[NO_OF_CLIENTS];
    AudioCodingModule* _clientACM[NO_OF_CLIENTS];
    Channel*               _conf2Client[NO_OF_CLIENTS];
    Channel*               _client2Conf[NO_OF_CLIENTS];

    PCMFile                _clientOutFile[NO_OF_CLIENTS];
};

} // namespace webrtc

#endif
