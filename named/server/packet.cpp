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

#include "server/packet.h"

#include <net/opcode/name_srv.h>
#include <packet/packet.h>

#include "name_service.h"

namespace srv_pkt
{
    void Register (OPacket *pkt, const uint8_t result)
    {
        pkt->WriteOpcode(SRV_REGISTER_SERVICE);
        pkt->Write<uint8_t>(result);
    }

    void Query (OPacket *pkt, const NameService *service)
    {
        pkt->WriteOpcode(SRV_QUERY);
        pkt->Write<uint8_t>(service->type);
        pkt->Write(service->host);
        pkt->Write(service->port);
    }
}
