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

#include "shardd/state_handshake.h"

#include <net/client/connection.h>

#include "shardd/states.h"
#include "shardd/packet_shard.h"
#include "service.h"

namespace shard
{
    StateHandshake::StateHandshake (Service *service, const std::string &srvID, const std::string &cltID,
                                    const boost::shared_ptr<IConnection> &conn)
        : clt::IStateHandshake(srvID,cltID,conn),
        m_service(service)
    {
    }

    StateHandshake::~StateHandshake ()
    {
    }

    void StateHandshake::OnConfig ()
    {
        boost::shared_static_cast<clt::Connection,IConnection>(m_connection)->KeepAlive();

        m_connection->setState(shard::STATE_SHARD);

        OPacket pkt;
        clt_pkt::Config(&pkt,m_service->getHost(),m_service->getPort());
        m_connection->send(&pkt);
    }
}
