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

#include "globald/state_handshake.h"

#include <net/client/connection.h>

#include "globald/states.h"
#include "globald/packet.h"

namespace clt
{

StateHandshake::StateHandshake (const std::string &srvID, const std::string &cltID,
                                const boost::shared_ptr<IConnection> &conn)
    : clt::IStateHandshake(srvID,cltID,conn)
{
}

StateHandshake::~StateHandshake ()
{
}

void StateHandshake::OnConfig ()
{
    boost::shared_static_cast<clt::Connection,IConnection>(m_connection)->KeepAlive();

    OPacket pkt;
    clt_pkt::WriteConfig(&pkt);
    m_connection->send(&pkt);

    m_connection->setState(clt::STATE_GLOBAL);
}

}
