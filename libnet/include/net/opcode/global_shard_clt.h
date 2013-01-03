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

#ifndef __ZELOS_LIBNET_OPCODE_GLOBAL_SHARD_CLT_H__
#define __ZELOS_LIBNET_OPCODE_GLOBAL_SHARD_CLT_H__

enum
{
    CLT_SHARD_CONFIG = 0xA001,
    CLT_SHARD_NOTIFY,
    CLT_SHARD_AGENT_ADD,
    CLT_SHARD_AGENT_DEL,
    CLT_ACCOUNT_NOTIFY
};

#endif // __ZELOS_LIBNET_OPCODE_GLOBAL_SHARD_CLT_H__
