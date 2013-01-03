/*********************************************************************************
 *
 * This file is part of ZelosOnline.
 *
 * ZelosOnline is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * ZelosOnline is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright  2013  Rafael Dominguez (npcdoom)
 *
 *********************************************************************************/

#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <stdint.h>
#include <vector>

class OPacket;
class IPacket;

enum DECODE_ERROR
{
    ERR_DECODE_SUCCESS,
    ERR_DECODE_INVALID,
    ERR_DECODE_MISSING_DATA
};

enum AUTH_TYPE
{
    AUTH_SERVER,
    AUTH_CLIENT
};

class Authentication
{
public:

    Authentication (AUTH_TYPE authType, const uint8_t mode = 0)
        : m_Type(authType), m_Mode(mode)
    {}

    virtual ~Authentication() {}

    inline void setMode (const uint8_t mode) { m_Mode = mode; }

    inline uint8_t getMode () const { return m_Mode; }

    virtual void encode (OPacket *packet, bool encrypt, std::vector<uint8_t> &stream) = 0;

    virtual DECODE_ERROR readHeader (const uint8_t *buffer, const size_t pendingLen,
                                     const size_t maxLen, size_t *buffer_size,
                                     size_t *real_size, bool *hasSecurity) = 0;

    virtual DECODE_ERROR decode (IPacket *packet, const size_t buffer_size, const size_t real_size,
                                 const bool hasSecurity) = 0;

protected:

    AUTH_TYPE m_Type;
    uint8_t m_Mode;
};

#endif // AUTHENTICATION_H
